// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtkMinimalStandardRandomSequence.h>
#include <vtkSmartPointer.h>
#include <vtkTexturedSphereSource.h>

int TestTexturedSphereSource(int vtkNotUsed(argc), char* vtkNotUsed(argv)[])
{
  vtkSmartPointer<vtkMinimalStandardRandomSequence> randomSequence =
    vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
  randomSequence->SetSeed(1);

  vtkSmartPointer<vtkTexturedSphereSource> texturedSphereSource =
    vtkSmartPointer<vtkTexturedSphereSource>::New();
  texturedSphereSource->SetThetaResolution(8);
  texturedSphereSource->SetPhiResolution(8);
  texturedSphereSource->SetTheta(0.0);
  texturedSphereSource->SetPhi(0.0);

  texturedSphereSource->SetOutputPointsPrecision(vtkAlgorithm::SINGLE_PRECISION);

  randomSequence->Next();
  double radius = randomSequence->GetValue();
  texturedSphereSource->SetRadius(radius);

  texturedSphereSource->Update();

  vtkSmartPointer<vtkPolyData> polyData = texturedSphereSource->GetOutput();
  vtkSmartPointer<vtkPoints> points = polyData->GetPoints();

  if (points->GetDataType() != VTK_FLOAT)
  {
    return EXIT_FAILURE;
  }

  texturedSphereSource->SetOutputPointsPrecision(vtkAlgorithm::DOUBLE_PRECISION);

  randomSequence->Next();
  radius = randomSequence->GetValue();
  texturedSphereSource->SetRadius(radius);

  texturedSphereSource->Update();

  polyData = texturedSphereSource->GetOutput();
  points = polyData->GetPoints();

  if (points->GetDataType() != VTK_DOUBLE)
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
