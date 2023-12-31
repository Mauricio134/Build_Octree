// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtkFloatArray.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>

namespace
{
void InitializePointSet(vtkPointSet* pointSet, int dataType)
{
  vtkSmartPointer<vtkMinimalStandardRandomSequence> randomSequence =
    vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
  randomSequence->SetSeed(1);

  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

  const int numPoints = 4;

  if (dataType == VTK_DOUBLE)
  {
    points->SetDataType(VTK_DOUBLE);
    for (unsigned int i = 0; i < numPoints; ++i)
    {
      double point[3];
      for (unsigned int j = 0; j < 3; ++j)
      {
        randomSequence->Next();
        point[j] = randomSequence->GetValue();
      }
      points->InsertNextPoint(point);
    }
  }
  else
  {
    points->SetDataType(VTK_FLOAT);
    for (unsigned int i = 0; i < numPoints; ++i)
    {
      float point[3];
      for (unsigned int j = 0; j < 3; ++j)
      {
        randomSequence->Next();
        point[j] = static_cast<float>(randomSequence->GetValue());
      }
      points->InsertNextPoint(point);
    }
  }

  // Add texture coordinates. Values don't matter, we just want to make sure
  // they are passed through the transform filter.
  vtkSmartPointer<vtkFloatArray> tcoords = vtkSmartPointer<vtkFloatArray>::New();
  tcoords->SetNumberOfComponents(2);
  tcoords->SetNumberOfTuples(numPoints);
  tcoords->FillComponent(0, 0.0);
  tcoords->FillComponent(1, 1.0);
  pointSet->GetPointData()->SetTCoords(tcoords);

  points->Squeeze();
  pointSet->SetPoints(points);
}

void InitializeTransform(vtkTransform* transform)
{
  vtkSmartPointer<vtkMinimalStandardRandomSequence> randomSequence =
    vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
  randomSequence->SetSeed(1);

  double elements[16];
  for (unsigned int i = 0; i < 16; ++i)
  {
    randomSequence->Next();
    elements[i] = randomSequence->GetValue();
  }
  transform->SetMatrix(elements);
}
}

vtkSmartPointer<vtkPointSet> TransformPointSet(int dataType, int outputPointsPrecision)
{
  vtkSmartPointer<vtkPointSet> inputPointSet = vtkSmartPointer<vtkPolyData>::New();
  InitializePointSet(inputPointSet, dataType);

  vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
  InitializeTransform(transform);

  vtkSmartPointer<vtkTransformFilter> transformFilter = vtkSmartPointer<vtkTransformFilter>::New();
  transformFilter->SetTransformAllInputVectors(true);
  transformFilter->SetOutputPointsPrecision(outputPointsPrecision);

  transformFilter->SetTransform(transform);
  transformFilter->SetInputData(inputPointSet);

  transformFilter->Update();

  vtkSmartPointer<vtkPointSet> outputPointSet = transformFilter->GetOutput();
  vtkSmartPointer<vtkPoints> points = outputPointSet->GetPoints();

  return outputPointSet;
}

int TestTransformFilter(int vtkNotUsed(argc), char* vtkNotUsed(argv)[])
{
  vtkSmartPointer<vtkPointSet> pointSet =
    TransformPointSet(VTK_FLOAT, vtkAlgorithm::DEFAULT_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_FLOAT)
  {
    return EXIT_FAILURE;
  }

  pointSet = TransformPointSet(VTK_DOUBLE, vtkAlgorithm::DEFAULT_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_DOUBLE)
  {
    return EXIT_FAILURE;
  }

  pointSet = TransformPointSet(VTK_FLOAT, vtkAlgorithm::SINGLE_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_FLOAT)
  {
    return EXIT_FAILURE;
  }

  if (pointSet->GetPointData()->GetTCoords() == nullptr)
  {
    std::cerr << "TCoords were not passed through vtkTransformFilter." << std::endl;
    return EXIT_FAILURE;
  }

  pointSet = TransformPointSet(VTK_DOUBLE, vtkAlgorithm::SINGLE_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_FLOAT)
  {
    return EXIT_FAILURE;
  }

  pointSet = TransformPointSet(VTK_FLOAT, vtkAlgorithm::DOUBLE_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_DOUBLE)
  {
    return EXIT_FAILURE;
  }

  pointSet = TransformPointSet(VTK_DOUBLE, vtkAlgorithm::DOUBLE_PRECISION);

  if (pointSet->GetPoints()->GetDataType() != VTK_DOUBLE)
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
