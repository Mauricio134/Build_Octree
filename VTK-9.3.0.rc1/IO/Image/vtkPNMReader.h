// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkPNMReader
 * @brief   read pnm (i.e., portable anymap) files
 *
 *
 * vtkPNMReader is a source object that reads pnm (portable anymap) files.
 * This includes .pbm (bitmap), .pgm (grayscale), and .ppm (pixmap) files.
 * (Currently this object only reads binary versions of these files.)
 *
 * PNMReader creates structured point datasets. The dimension of the
 * dataset depends upon the number of files read. Reading a single file
 * results in a 2D image, while reading more than one file results in a
 * 3D volume.
 *
 * To read a volume, files must be of the form "FileName.<number>" (e.g.,
 * foo.ppm.0, foo.ppm.1, ...). You must also specify the DataExtent.  The
 * fifth and sixth values of the DataExtent specify the beginning and ending
 * files to read.
 */

#ifndef vtkPNMReader_h
#define vtkPNMReader_h

#include "vtkIOImageModule.h" // For export macro
#include "vtkImageReader.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKIOIMAGE_EXPORT vtkPNMReader : public vtkImageReader
{
public:
  static vtkPNMReader* New();
  vtkTypeMacro(vtkPNMReader, vtkImageReader);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  int CanReadFile(VTK_FILEPATH const char* fname) override;
  /**
   * .pnm .pgm .ppm
   */
  const char* GetFileExtensions() override { return ".pnm .pgm .ppm"; }

  /**
   * PNM
   */
  const char* GetDescriptiveName() override { return "PNM"; }

protected:
  vtkPNMReader() = default;
  ~vtkPNMReader() override = default;
  void ExecuteInformation() override;

private:
  vtkPNMReader(const vtkPNMReader&) = delete;
  void operator=(const vtkPNMReader&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
