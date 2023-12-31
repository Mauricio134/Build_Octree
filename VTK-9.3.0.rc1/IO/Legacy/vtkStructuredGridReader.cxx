// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkStructuredGridReader.h"

#include "vtkDataSetAttributes.h"
#include "vtkErrorCode.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkStructuredGrid.h"
#include "vtkUnsignedCharArray.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkStructuredGridReader);

vtkStructuredGridReader::vtkStructuredGridReader() = default;
vtkStructuredGridReader::~vtkStructuredGridReader() = default;

//------------------------------------------------------------------------------
vtkStructuredGrid* vtkStructuredGridReader::GetOutput()
{
  return this->GetOutput(0);
}

//------------------------------------------------------------------------------
vtkStructuredGrid* vtkStructuredGridReader::GetOutput(int idx)
{
  return vtkStructuredGrid::SafeDownCast(this->GetOutputDataObject(idx));
}

//------------------------------------------------------------------------------
void vtkStructuredGridReader::SetOutput(vtkStructuredGrid* output)
{
  this->GetExecutive()->SetOutputData(0, output);
}

//------------------------------------------------------------------------------
int vtkStructuredGridReader::ReadMetaDataSimple(const std::string& fname, vtkInformation* metadata)
{
  char line[256];
  bool dimsRead = false;

  if (!this->OpenVTKFile(fname.c_str()) || !this->ReadHeader(fname.c_str()))
  {
    return 1;
  }

  // Read structured grid specific stuff
  //
  if (!this->ReadString(line))
  {
    vtkErrorMacro(<< "Data file ends prematurely!");
    this->CloseVTKFile();
    return 1;
  }

  if (!strncmp(this->LowerCase(line), "dataset", 7))
  {
    // Make sure we're reading right type of geometry
    //
    if (!this->ReadString(line))
    {
      vtkErrorMacro(<< "Data file ends prematurely!");
      this->CloseVTKFile();
      return 1;
    }

    if (strncmp(this->LowerCase(line), "structured_grid", 15) != 0)
    {
      vtkErrorMacro(<< "Cannot read dataset type: " << line);
      this->CloseVTKFile();
      return 1;
    }

    // Read keyword and dimensions
    //
    while (true)
    {
      if (!this->ReadString(line))
      {
        break;
      }

      // Have to read field data because it may be binary.
      if (!strncmp(this->LowerCase(line), "field", 5))
      {
        vtkFieldData* fd = this->ReadFieldData();
        fd->Delete();
      }

      if (!strncmp(this->LowerCase(line), "dimensions", 10) && !dimsRead)
      {
        int dim[3];
        if (!(this->Read(dim) && this->Read(dim + 1) && this->Read(dim + 2)))
        {
          vtkErrorMacro(<< "Error reading dimensions!");
          this->CloseVTKFile();
          this->SetErrorCode(vtkErrorCode::FileFormatError);
          return 1;
        }
        metadata->Set(vtkStreamingDemandDrivenPipeline::WHOLE_EXTENT(), 0, dim[0] - 1, 0,
          dim[1] - 1, 0, dim[2] - 1);
        dimsRead = true;
      }

      else if (!strncmp(line, "extent", 6) && !dimsRead)
      {
        int extent[6];
        if (!(this->Read(extent) && this->Read(extent + 1) && this->Read(extent + 2) &&
              this->Read(extent + 3) && this->Read(extent + 4) && this->Read(extent + 5)))
        {
          vtkErrorMacro(<< "Error reading extent!");
          this->CloseVTKFile();
          this->SetErrorCode(vtkErrorCode::FileFormatError);
          return 1;
        }

        metadata->Set(vtkStreamingDemandDrivenPipeline::WHOLE_EXTENT(), extent[0], extent[1],
          extent[2], extent[3], extent[4], extent[5]);

        dimsRead = true;
      }
    }
  }

  if (!dimsRead)
  {
    vtkWarningMacro(<< "Could not read dimensions or extents from the file.");
  }
  this->CloseVTKFile();

  return 1;
}

//------------------------------------------------------------------------------
int vtkStructuredGridReader::ReadMeshSimple(const std::string& fname, vtkDataObject* doOutput)
{
  vtkIdType numPts = 0, npts = 0, numCells = 0, ncells;
  char line[256];
  int dimsRead = 0;
  vtkStructuredGrid* output = vtkStructuredGrid::SafeDownCast(doOutput);

  vtkDebugMacro(<< "Reading vtk structured grid file...");

  if (!this->OpenVTKFile(fname.c_str()) || !this->ReadHeader(fname.c_str()))
  {
    return 1;
  }

  // Read structured grid specific stuff
  //
  if (!this->ReadString(line))
  {
    vtkErrorMacro(<< "Data file ends prematurely!");
    this->CloseVTKFile();
    return 1;
  }

  if (!strncmp(this->LowerCase(line), "dataset", 7))
  {
    // Make sure we're reading right type of geometry
    //
    if (!this->ReadString(line))
    {
      vtkErrorMacro(<< "Data file ends prematurely!");
      this->CloseVTKFile();
      return 1;
    }

    if (strncmp(this->LowerCase(line), "structured_grid", 15) != 0)
    {
      vtkErrorMacro(<< "Cannot read dataset type: " << line);
      this->CloseVTKFile();
      return 1;
    }

    // Read keyword and number of points
    //
    while (true)
    {
      if (!this->ReadString(line))
      {
        break;
      }

      if (!strncmp(this->LowerCase(line), "field", 5))
      {
        vtkFieldData* fd = this->ReadFieldData();
        output->SetFieldData(fd);
        fd->Delete(); // ?
      }

      else if (!strncmp(line, "extent", 6) && !dimsRead)
      {
        int extent[6];
        if (!(this->Read(extent) && this->Read(extent + 1) && this->Read(extent + 2) &&
              this->Read(extent + 3) && this->Read(extent + 4) && this->Read(extent + 5)))
        {
          vtkErrorMacro(<< "Error reading extent!");
          this->CloseVTKFile();
          this->SetErrorCode(vtkErrorCode::FileFormatError);
          return 1;
        }

        output->SetExtent(extent);
        numPts = output->GetNumberOfPoints();
        numCells = output->GetNumberOfCells();
        dimsRead = 1;
      }
      else if (!strncmp(line, "dimensions", 10))
      {
        int dim[3];
        if (!(this->Read(dim) && this->Read(dim + 1) && this->Read(dim + 2)))
        {
          vtkErrorMacro(<< "Error reading dimensions!");
          this->CloseVTKFile();
          this->SetErrorCode(vtkErrorCode::FileFormatError);
          return 1;
        }

        numPts = dim[0] * dim[1] * dim[2];
        output->SetDimensions(dim);
        numCells = output->GetNumberOfCells();
        dimsRead = 1;
      }

      else if (this->FileMajorVersion < 4 && !strncmp(line, "blanking", 8))
      {
        if (!this->Read(&npts))
        {
          vtkErrorMacro(<< "Error reading blanking!");
          this->CloseVTKFile();
          return 1;
        }

        if (!this->ReadString(line))
        {
          vtkErrorMacro(<< "Cannot read blank type!");
          this->CloseVTKFile();
          return 1;
        }

        vtkUnsignedCharArray* data =
          vtkArrayDownCast<vtkUnsignedCharArray>(this->ReadArray(line, numPts, 1));

        if (data != nullptr)
        {
          vtkUnsignedCharArray* ghosts = vtkUnsignedCharArray::New();
          ghosts->SetNumberOfValues(numPts);
          ghosts->SetName(vtkDataSetAttributes::GhostArrayName());
          for (vtkIdType ptId = 0; ptId < numPts; ++ptId)
          {
            unsigned char value = 0;
            if (data->GetValue(ptId) == 0)
            {
              value |= vtkDataSetAttributes::HIDDENPOINT;
            }
            ghosts->SetValue(ptId, value);
          }
          output->GetPointData()->AddArray(ghosts);
          ghosts->Delete();
          data->Delete();
        }
      }

      else if (!strncmp(line, "points", 6))
      {
        if (!this->Read(&npts))
        {
          vtkErrorMacro(<< "Error reading points!");
          this->CloseVTKFile();
          return 1;
        }

        this->ReadPointCoordinates(output, npts);
      }

      else if (!strncmp(line, "cell_data", 9))
      {
        if (!this->Read(&ncells))
        {
          vtkErrorMacro(<< "Cannot read cell data!");
          this->CloseVTKFile();
          return 1;
        }

        if (ncells != numCells)
        {
          vtkErrorMacro(<< "Number of cells don't match!");
          this->CloseVTKFile();
          return 1;
        }

        this->ReadCellData(output, ncells);
        break; // out of this loop
      }

      else if (!strncmp(line, "point_data", 10))
      {
        if (!this->Read(&numPts))
        {
          vtkErrorMacro(<< "Cannot read point data!");
          this->CloseVTKFile();
          return 1;
        }

        if (npts != numPts)
        {
          vtkErrorMacro(<< "Number of points don't match!");
          this->CloseVTKFile();
          return 1;
        }

        this->ReadPointData(output, npts);
        break; // out of this loop
      }

      else
      {
        vtkErrorMacro(<< "Unrecognized keyword: " << line);
        this->CloseVTKFile();
        return 1;
      }
    }

    if (!dimsRead)
      vtkWarningMacro(<< "No dimensions read.");
    if (!output->GetPoints())
      vtkWarningMacro(<< "No points read.");
  }

  else if (!strncmp(line, "cell_data", 9))
  {
    vtkWarningMacro(<< "No geometry defined in data file!");
    if (!this->Read(&ncells))
    {
      vtkErrorMacro(<< "Cannot read cell data!");
      this->CloseVTKFile();
      return 1;
    }
    this->ReadCellData(output, ncells);
  }

  else if (!strncmp(line, "point_data", 10))
  {
    vtkWarningMacro(<< "No geometry defined in data file!");
    if (!this->Read(&npts))
    {
      vtkErrorMacro(<< "Cannot read point data!");
      this->CloseVTKFile();
      return 1;
    }
    this->ReadPointData(output, npts);
  }

  else
  {
    vtkErrorMacro(<< "Unrecognized keyword: " << line);
  }
  this->CloseVTKFile();

  return 1;
}

//------------------------------------------------------------------------------
int vtkStructuredGridReader::FillOutputPortInformation(int, vtkInformation* info)
{
  info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkStructuredGrid");
  return 1;
}

void vtkStructuredGridReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
