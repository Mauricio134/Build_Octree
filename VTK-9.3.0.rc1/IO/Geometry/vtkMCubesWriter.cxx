// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkMCubesWriter.h"

#include "vtkByteSwap.h"
#include "vtkCellArray.h"
#include "vtkInformation.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkPolyData.h"
#include <vtksys/SystemTools.hxx>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkMCubesWriter);

// Create object.
vtkMCubesWriter::vtkMCubesWriter()
{
  this->FileName = nullptr;
  this->LimitsFileName = nullptr;
}

vtkMCubesWriter::~vtkMCubesWriter()
{
  delete[] this->FileName;
  delete[] this->LimitsFileName;
}

// Write out data in MOVIE.BYU format.
void vtkMCubesWriter::WriteData()
{
  vtkPoints* pts;
  vtkDataArray* normals;
  vtkCellArray* polys;
  vtkPolyData* input = this->GetInput();

  polys = input->GetPolys();
  pts = input->GetPoints();
  if (pts == nullptr || polys == nullptr)
  {
    vtkErrorMacro(<< "No data to write!");
    return;
  }

  normals = input->GetPointData()->GetNormals();
  if (normals == nullptr)
  {
    vtkErrorMacro(<< "No normals to write!: use vtkPolyDataNormals to generate them");
    return;
  }

  if (this->FileName == nullptr)
  {
    vtkErrorMacro(<< "Please specify FileName to write");
    return;
  }

  vtkDebugMacro("Writing MCubes tri file");
  FILE* fp;
  if ((fp = vtksys::SystemTools::Fopen(this->FileName, "w")) == nullptr)
  {
    vtkErrorMacro(<< "Couldn't open file: " << this->FileName);
    return;
  }
  this->WriteMCubes(fp, pts, normals, polys);
  fclose(fp);

  if (this->LimitsFileName)
  {
    vtkDebugMacro("Writing MCubes limits file");
    if ((fp = vtksys::SystemTools::Fopen(this->LimitsFileName, "w")) == nullptr)
    {
      vtkErrorMacro(<< "Couldn't open file: " << this->LimitsFileName);
      return;
    }
    this->WriteLimits(fp, input->GetBounds());
    fclose(fp);
  }
}

void vtkMCubesWriter::WriteMCubes(
  FILE* fp, vtkPoints* pts, vtkDataArray* normals, vtkCellArray* polys)
{
  struct pointType_t
  {
    float x[3], n[3];
  };
  using pointType = struct pointType_t;
  pointType point;
  int i;
  vtkIdType npts;
  const vtkIdType* indx = nullptr;

  //  Write out triangle polygons.  In not a triangle polygon, create
  //  triangles.
  //
  double p[3], n[3];
  bool status = true;
  for (polys->InitTraversal(); polys->GetNextCell(npts, indx) && status;)
  {
    for (i = 0; i < 3 && status; i++)
    {
      pts->GetPoint(indx[i], p);
      normals->GetTuple(indx[i], n);
      point.x[0] = static_cast<float>(p[0]);
      point.x[1] = static_cast<float>(p[1]);
      point.x[2] = static_cast<float>(p[2]);
      point.n[0] = static_cast<float>(n[0]);
      point.n[1] = static_cast<float>(n[1]);
      point.n[2] = static_cast<float>(n[2]);
      status = vtkByteSwap::SwapWrite4BERange(reinterpret_cast<float*>(&point), 6, fp);
      if (!status)
      {
        vtkErrorMacro(<< "SwapWrite failed.");
      }
    }
  }
}
void vtkMCubesWriter::WriteLimits(FILE* fp, double* bounds)
{
  float fbounds[6];
  fbounds[0] = static_cast<float>(bounds[0]);
  fbounds[1] = static_cast<float>(bounds[1]);
  fbounds[2] = static_cast<float>(bounds[2]);
  fbounds[3] = static_cast<float>(bounds[3]);
  fbounds[4] = static_cast<float>(bounds[4]);
  fbounds[5] = static_cast<float>(bounds[5]);
  bool status = vtkByteSwap::SwapWrite4BERange(fbounds, 6, fp);
  if (!status)
  {
    vtkErrorMacro(<< "SwapWrite failed.");
  }
  else
  {
    status = vtkByteSwap::SwapWrite4BERange(fbounds, 6, fp);
    if (!status)
    {
      vtkErrorMacro(<< "SwapWrite failed.");
    }
  }
}

void vtkMCubesWriter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Limits File Name: " << (this->LimitsFileName ? this->LimitsFileName : "(none)")
     << "\n";
}

vtkPolyData* vtkMCubesWriter::GetInput()
{
  return vtkPolyData::SafeDownCast(this->Superclass::GetInput());
}

vtkPolyData* vtkMCubesWriter::GetInput(int port)
{
  return vtkPolyData::SafeDownCast(this->Superclass::GetInput(port));
}

int vtkMCubesWriter::FillInputPortInformation(int, vtkInformation* info)
{
  info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkPolyData");
  return 1;
}
VTK_ABI_NAMESPACE_END
