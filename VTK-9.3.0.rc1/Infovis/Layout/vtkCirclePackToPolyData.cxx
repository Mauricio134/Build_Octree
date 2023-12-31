// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
#include "vtkCirclePackToPolyData.h"
#include "vtkAppendPolyData.h"
#include "vtkCellArray.h"
#include "vtkCellData.h"
#include "vtkCommand.h"
#include "vtkFloatArray.h"
#include "vtkIdTypeArray.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkSectorSource.h"
#include "vtkSmartPointer.h"
#include "vtkStripper.h"
#include "vtkTimerLog.h"
#include "vtkTree.h"

#define VTK_CREATE(type, name) vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkCirclePackToPolyData);

vtkCirclePackToPolyData::vtkCirclePackToPolyData()
{
  this->SetCirclesArrayName("circles");
  this->Resolution = 100;
}

vtkCirclePackToPolyData::~vtkCirclePackToPolyData() = default;

int vtkCirclePackToPolyData::FillInputPortInformation(int vtkNotUsed(port), vtkInformation* info)
{
  info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkTree");
  return 1;
}

int vtkCirclePackToPolyData::RequestData(vtkInformation* vtkNotUsed(request),
  vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  // get the info objects
  vtkInformation* inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation* outInfo = outputVector->GetInformationObject(0);

  // get the input and output
  vtkTree* inputTree = vtkTree::SafeDownCast(inInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkPolyData* outputPoly = vtkPolyData::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()));

  if (inputTree->GetNumberOfVertices() == 0)
  {
    return 1;
  }

  vtkDataArray* circlesArray = this->GetInputArrayToProcess(0, inputTree);
  if (!circlesArray)
  {
    vtkErrorMacro("Circles array not found.");
    return 0;
  }

  double progress = 0.0;
  this->InvokeEvent(vtkCommand::ProgressEvent, &progress);
  VTK_CREATE(vtkAppendPolyData, appendFilter);

  for (int i = 0; i < inputTree->GetNumberOfVertices(); i++)
  {
    // Grab coords from the input
    double circle[3];
    circlesArray->GetTuple(i, circle);
    VTK_CREATE(vtkPolyData, circlePData);
    this->CreateCircle(circle[0], circle[1], 0.0, circle[2], this->Resolution, circlePData);
    appendFilter->AddInputData(circlePData);

    if (i % 1000 == 0)
    {
      progress = static_cast<double>(i) / inputTree->GetNumberOfVertices() * 0.8;
      this->InvokeEvent(vtkCommand::ProgressEvent, &progress);
    }
  }

  appendFilter->Update();
  outputPoly->ShallowCopy(appendFilter->GetOutput());

  // Pass the input vertex data to the output cell data :)
  vtkDataSetAttributes* const input_vertex_data = inputTree->GetVertexData();
  vtkDataSetAttributes* const output_cell_data = outputPoly->GetCellData();
  output_cell_data->PassData(input_vertex_data);

  return 1;
}

void vtkCirclePackToPolyData::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "Resolution: " << this->Resolution << endl;
}

void vtkCirclePackToPolyData::CreateCircle(const double& x, const double& y, const double& z,
  const double& radius, const int& resolution, vtkPolyData* polyData)
{
  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();

  points->SetNumberOfPoints(resolution);
  cells->AllocateEstimate(1, resolution);
  cells->InsertNextCell(resolution);

  for (int i = 0; i < resolution; ++i)
  {
    double theta = vtkMath::RadiansFromDegrees(360. * i / double(resolution));
    double xp = x + radius * cos(theta);
    double yp = y + radius * sin(theta);
    points->SetPoint(i, xp, yp, z);
    cells->InsertCellPoint(i);
  }

  polyData->Initialize();
  polyData->SetPolys(cells);
  polyData->SetPoints(points);
}
VTK_ABI_NAMESPACE_END
