// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkJPEGReader.h"

#include "vtkDataArray.h"
#include "vtkImageData.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include <vtksys/SystemTools.hxx>

#include <vector>

extern "C"
{
#include "vtk_jpeg.h"
#include <setjmp.h>
}

VTK_ABI_NAMESPACE_BEGIN

vtkStandardNewMacro(vtkJPEGReader);

VTK_ABI_NAMESPACE_END

#if defined(_MSC_VER)
#if defined(_WIN64)
#pragma warning(disable : 4324) // structure was padded at end...
#endif
#endif

// create an error handler for jpeg that
// can longjmp out of the jpeg library
struct vtk_jpeg_error_mgr
{
  struct jpeg_error_mgr pub; /* "public" fields */
  jmp_buf setjmp_buffer;     /* for return to caller */
  vtkJPEGReader* JPEGReader;
  FILE* fp;
};

namespace
{
// this is called on jpeg error conditions
void vtk_jpeg_error_exit(j_common_ptr cinfo)
{
  /* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
  vtk_jpeg_error_mgr* err = reinterpret_cast<vtk_jpeg_error_mgr*>(cinfo->err);

  /* Return control to the setjmp point */
  longjmp(err->setjmp_buffer, 1);
}

void vtk_jpeg_output_message(j_common_ptr cinfo)
{
  char buffer[JMSG_LENGTH_MAX];

  /* Create the message */
  (*cinfo->err->format_message)(cinfo, buffer);
  vtk_jpeg_error_mgr* err = reinterpret_cast<vtk_jpeg_error_mgr*>(cinfo->err);
  vtkWarningWithObjectMacro(err->JPEGReader, "libjpeg error: " << buffer);
  cinfo->err->num_warnings++;
}

void jpg_null(j_decompress_ptr vtkNotUsed(cinfo)) {}

boolean fill_input_buffer(j_decompress_ptr vtkNotUsed(cinfo))
{
  vtkGenericWarningMacro(<< "libjpeg error: unexpected end of JPEG data!");
  return FALSE;
}

void skip_input_data(j_decompress_ptr cinfo, long num_bytes)
{
  struct jpeg_source_mgr* src = (struct jpeg_source_mgr*)cinfo->src;

  if (num_bytes > 0)
  {
    src->next_input_byte += (size_t)num_bytes;
    src->bytes_in_buffer -= (size_t)num_bytes;
  }
}

// Read JPEG image from a memory buffer
#if JPEG_LIB_VERSION >= 80 || defined(MEM_SRCDST_SUPPORTED)
void jMemSrc(j_decompress_ptr cinfo, const void* buffer, long nbytes)
#else
void jpeg_mem_src(j_decompress_ptr cinfo, const void* buffer, long nbytes)
#endif
{
  cinfo->src = (struct jpeg_source_mgr*)(*cinfo->mem->alloc_small)(
    (j_common_ptr)cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));
  cinfo->src = (struct jpeg_source_mgr*)cinfo->src;
  cinfo->src->init_source = jpg_null;
  cinfo->src->fill_input_buffer = fill_input_buffer;
  cinfo->src->skip_input_data = skip_input_data;
  cinfo->src->resync_to_restart = jpeg_resync_to_restart;
  cinfo->src->term_source = jpg_null;
  cinfo->src->bytes_in_buffer = nbytes;
  cinfo->src->next_input_byte = (const JOCTET*)buffer;
}
}

#ifdef _MSC_VER
// Let us get rid of this funny warning on /W4:
// warning C4611: interaction between '_setjmp' and C++ object
// destruction is non-portable
#pragma warning(disable : 4611)
#endif

VTK_ABI_NAMESPACE_BEGIN

void vtkJPEGReader::ExecuteInformation()
{
  // certain variables must be stored here for longjmp
  struct vtk_jpeg_error_mgr jerr;
  jerr.JPEGReader = this;
  jerr.fp = nullptr;

  this->ComputeInternalFileName(this->DataExtent[4]);
  if (this->InternalFileName == nullptr && this->MemoryBuffer == nullptr)
  {
    return;
  }

  // reset the error code before reading
  this->ErrorCode = 0;

  if (!this->MemoryBuffer)
  {
    jerr.fp = vtksys::SystemTools::Fopen(this->InternalFileName, "rb");
    if (!jerr.fp)
    {
      vtkErrorWithObjectMacro(this, "Unable to open file " << this->InternalFileName);
      return;
    }
  }
  else
  {
    if (this->MemoryBufferLength == 0)
    {
      vtkErrorWithObjectMacro(this,
        "Trying to read a JPEG image from "
        "a zero-length memory buffer!");
      return;
    }
  }

  // create jpeg decompression object and error handler
  struct jpeg_decompress_struct cinfo;
  cinfo.err = jpeg_std_error(&jerr.pub);
  // for any jpeg error call vtk_jpeg_error_exit
  jerr.pub.error_exit = vtk_jpeg_error_exit;
  // for any output message call vtk_jpeg_output_message
  jerr.pub.output_message = vtk_jpeg_output_message;
  jerr.pub.num_warnings = 0;
  if (setjmp(jerr.setjmp_buffer))
  {
    // clean up
    jpeg_destroy_decompress(&cinfo);
    // close the file
    if (jerr.fp)
    {
      fclose(jerr.fp);
      // this is not a valid jpeg file
      vtkErrorWithObjectMacro(this, "libjpeg could not read file: " << this->InternalFileName);
    }
    else
    {
      vtkErrorWithObjectMacro(this,
        "libjpeg could not read file from memory buffer: " << (this->MemoryBuffer ? "<ptr>"
                                                                                  : "(null)"));
    }
    return;
  }
  jpeg_create_decompress(&cinfo);

  // set the source file
  if (jerr.fp)
  {
    jpeg_stdio_src(&cinfo, jerr.fp);
  }
  else
  {
#if JPEG_LIB_VERSION >= 80 || defined(MEM_SRCDST_SUPPORTED)
    jMemSrc(&cinfo, this->MemoryBuffer, this->MemoryBufferLength);
#else
    jpeg_mem_src(&cinfo, this->MemoryBuffer, this->MemoryBufferLength);
#endif
  }

  // read the header
  jpeg_read_header(&cinfo, TRUE);

  // force the output image size to be calculated (we could have used
  // cinfo.image_height etc. but that would preclude using libjpeg's
  // ability to scale an image on input).
  jpeg_calc_output_dimensions(&cinfo);

  // pull out the width/height, etc.
  this->DataExtent[0] = 0;
  this->DataExtent[1] = cinfo.output_width - 1;
  this->DataExtent[2] = 0;
  this->DataExtent[3] = cinfo.output_height - 1;

  this->SetDataScalarTypeToUnsignedChar();
  this->SetNumberOfScalarComponents(cinfo.output_components);

  this->vtkImageReader2::ExecuteInformation();

  // close the file
  jpeg_destroy_decompress(&cinfo);

  if (jerr.fp)
  {
    fclose(jerr.fp);
  }
}

template <class OT>
int vtkJPEGReaderUpdate2(vtkJPEGReader* self, OT* outPtr, int* outExt, vtkIdType* outInc, long)
{
  // certain variables must be stored here for longjmp
  struct vtk_jpeg_error_mgr jerr;
  jerr.JPEGReader = self;
  jerr.fp = nullptr;

  if (!self->GetMemoryBuffer())
  {
    jerr.fp = vtksys::SystemTools::Fopen(self->GetInternalFileName(), "rb");
    if (!jerr.fp)
    {
      return 1;
    }
  }

  // create jpeg decompression object and error handler
  struct jpeg_decompress_struct cinfo;
  cinfo.err = jpeg_std_error(&jerr.pub);
  // for any jpeg error call vtk_jpeg_error_exit
  jerr.pub.error_exit = vtk_jpeg_error_exit;
  // for any output message call vtk_jpeg_output_message
  jerr.pub.output_message = vtk_jpeg_output_message;
  jerr.pub.num_warnings = 0;
  if (setjmp(jerr.setjmp_buffer))
  {
    // clean up
    jpeg_destroy_decompress(&cinfo);
    // close the file
    if (jerr.fp)
    {
      fclose(jerr.fp);
    }

    // this is not a valid jpeg file
    return 2;
  }
  jpeg_create_decompress(&cinfo);

  // set the source file
  if (jerr.fp)
  {
    jpeg_stdio_src(&cinfo, jerr.fp);
  }
  else
  {
#if JPEG_LIB_VERSION >= 80 || defined(MEM_SRCDST_SUPPORTED)
    jMemSrc(&cinfo, self->GetMemoryBuffer(), self->GetMemoryBufferLength());
#else
    jpeg_mem_src(&cinfo, self->GetMemoryBuffer(), self->GetMemoryBufferLength());
#endif
  }

  // read the header
  jpeg_read_header(&cinfo, TRUE);

  // prepare to read the bulk data
  jpeg_start_decompress(&cinfo);

  unsigned int maxChunk = cinfo.output_height;
  if (maxChunk > 4096)
  {
    maxChunk = 4096;
  }
  vtkIdType rowbytes = cinfo.output_components * cinfo.output_width;
  std::vector<unsigned char> tempImage(rowbytes * maxChunk);
  std::vector<JSAMPROW> row_pointers(maxChunk);
  for (unsigned int ui = 0; ui < maxChunk; ++ui)
  {
    row_pointers[ui] = tempImage.data() + rowbytes * ui;
  }

  // read the bulk data
  long outSize = cinfo.output_components * (outExt[1] - outExt[0] + 1);
  while (cinfo.output_scanline < cinfo.output_height)
  {
    JDIMENSION linesRead = jpeg_read_scanlines(&cinfo, row_pointers.data(), maxChunk);

    // copy the data into the outPtr
    long destLine = cinfo.output_height - cinfo.output_scanline;
    for (unsigned int i = 0; i < linesRead; ++i)
    {
      if (destLine >= outExt[2] && destLine <= outExt[3])
      {
        OT* outPtr2 = outPtr + (destLine - outExt[2]) * outInc[1];
        memcpy(
          outPtr2, row_pointers[linesRead - i - 1] + outExt[0] * cinfo.output_components, outSize);
      }
      destLine++;
    }
  }

  // finish the decompression step
  jpeg_finish_decompress(&cinfo);

  // destroy the decompression object
  jpeg_destroy_decompress(&cinfo);

  // close the file
  if (jerr.fp)
  {
    fclose(jerr.fp);
  }
  return jerr.pub.num_warnings;
}

//------------------------------------------------------------------------------
// This function reads in one data of data.
// templated to handle different data types.
template <class OT>
void vtkJPEGReader::InternalUpdate(vtkImageData* data, OT* outPtr)
{
  vtkIdType outIncr[3];
  int outExtent[6];
  OT* outPtr2;

  data->GetExtent(outExtent);
  data->GetIncrements(outIncr);

  long pixSize = data->GetNumberOfScalarComponents() * sizeof(OT);

  outPtr2 = outPtr;
  int idx2;
  for (idx2 = outExtent[4]; idx2 <= outExtent[5]; ++idx2)
  {
    this->ComputeInternalFileName(idx2);
    // read in a JPEG file
    if (vtkJPEGReaderUpdate2(this, outPtr2, outExtent, outIncr, pixSize) != 0)
    {
      const char* fn = this->GetInternalFileName();
      vtkErrorMacro("libjpeg could not read file: " << fn);
      this->ErrorCode = 2;
      return;
    }

    this->UpdateProgress((idx2 - outExtent[4]) / (outExtent[5] - outExtent[4] + 1.0));
    outPtr2 += outIncr[2];
  }
}

//------------------------------------------------------------------------------
// This function reads a data from a file.  The datas extent/axes
// are assumed to be the same as the file extent/order.
void vtkJPEGReader::ExecuteDataWithInformation(vtkDataObject* output, vtkInformation* outInfo)
{
  vtkImageData* data = this->AllocateOutputData(output, outInfo);

  if (this->InternalFileName == nullptr)
  {
    vtkErrorMacro(<< "Either a FileName or FilePrefix must be specified.");
    return;
  }

  this->ComputeDataIncrements();

  data->GetPointData()->GetScalars()->SetName("JPEGImage");

  // Call the correct templated function for the output
  void* outPtr;

  // reset the error code before reading
  this->ErrorCode = 0;

  // Call the correct templated function for the input
  outPtr = data->GetScalarPointer();
  switch (data->GetScalarType())
  {
    vtkTemplateMacro(this->InternalUpdate(data, (VTK_TT*)(outPtr)));
    default:
      vtkErrorMacro(<< "UpdateFromFile: Unknown data type");
  }
}

int vtkJPEGReader::CanReadFile(const char* fname)
{
  // certain variables must be stored here for longjmp
  struct vtk_jpeg_error_mgr jerr;
  jerr.JPEGReader = this;

  // reset the error code before reading
  this->ErrorCode = 0;

  // open the file
  jerr.fp = vtksys::SystemTools::Fopen(fname, "rb");
  if (!jerr.fp)
  {
    return 0;
  }
  // read the first two bytes
  char magic[2];
  int n = static_cast<int>(fread(magic, sizeof(magic), 1, jerr.fp));
  if (n != 1)
  {
    fclose(jerr.fp);
    return 0;
  }
  // check for the magic stuff:
  // 0xFF followed by 0xD8
  if (((static_cast<unsigned char>(magic[0]) != 0xFF) ||
        (static_cast<unsigned char>(magic[1]) != 0xD8)))
  {
    fclose(jerr.fp);
    return 0;
  }
  // go back to the start of the file
  fseek(jerr.fp, 0, SEEK_SET);
  // magic number is ok, try and read the header
  struct jpeg_decompress_struct cinfo;
  cinfo.err = jpeg_std_error(&jerr.pub);
  // for any jpeg error call vtk_jpeg_error_exit
  jerr.pub.error_exit = vtk_jpeg_error_exit;
  // for any output message call vtk_jpeg_error_exit
  jerr.pub.output_message = vtk_jpeg_error_exit;
  // set the jump point, if there is a jpeg error or warning
  // this will evaluate to true
  if (setjmp(jerr.setjmp_buffer))
  {
    // clean up
    jpeg_destroy_decompress(&cinfo);
    // close the file
    fclose(jerr.fp);
    // this is not a valid jpeg file
    return 0;
  }
  /* Now we can initialize the JPEG decompression object. */
  jpeg_create_decompress(&cinfo);
  /* Step 2: specify data source (eg, a file) */
  jpeg_stdio_src(&cinfo, jerr.fp);
  /* Step 3: read file parameters with jpeg_read_header() */
  jpeg_read_header(&cinfo, TRUE);

  // if no errors have occurred yet, then it must be jpeg
  jpeg_destroy_decompress(&cinfo);
  fclose(jerr.fp);
  return 3;
}
#ifdef _MSC_VER
// Put the warning back
#pragma warning(default : 4611)
#endif

//------------------------------------------------------------------------------
void vtkJPEGReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
