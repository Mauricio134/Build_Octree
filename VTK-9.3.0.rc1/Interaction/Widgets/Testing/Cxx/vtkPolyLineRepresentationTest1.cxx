// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkPolyLineRepresentation.h"

#include <cstdlib>
#include <iostream>

#include "WidgetTestingMacros.h"

#include "vtkPlaneSource.h"
#include "vtkPointHandleRepresentation3D.h"

#include "vtkPolyData.h"
#include "vtkProperty.h"

#include "vtkDoubleArray.h"

int vtkPolyLineRepresentationTest1(int, char*[])
{
  vtkSmartPointer<vtkPolyLineRepresentation> node1 =
    vtkSmartPointer<vtkPolyLineRepresentation>::New();

  EXERCISE_BASIC_REPRESENTATION_METHODS(vtkPolyLineRepresentation, node1);

  vtkSmartPointer<vtkPlaneSource> planeSource = vtkSmartPointer<vtkPlaneSource>::New();
  node1->SetPlaneSource(planeSource);

  TEST_SET_GET_BOOLEAN(node1, ProjectToPlane);

  // clamped 0-3
  TEST_SET_GET_INT_RANGE(node1, ProjectionNormal, 1, 2);
  node1->SetProjectionNormalToXAxes();
  node1->SetProjectionNormalToYAxes();
  node1->SetProjectionNormalToZAxes();
  node1->SetProjectionNormalToOblique();

  TEST_SET_GET_DOUBLE_RANGE(node1, ProjectionPosition, -10.0, 10.0);

  vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();
  node1->GetPolyData(pd);
  if (pd == nullptr)
  {
    std::cout << "Polydata is null" << std::endl;
  }

  vtkSmartPointer<vtkProperty> prop = node1->GetHandleProperty();
  if (prop == nullptr)
  {
    std::cout << "Handle Property is nullptr." << std::endl;
  }
  prop = node1->GetSelectedHandleProperty();
  if (prop == nullptr)
  {
    std::cout << "Selected Handle Property is nullptr." << std::endl;
  }

  prop = node1->GetLineProperty();
  if (prop == nullptr)
  {
    std::cout << "Line Property is nullptr." << std::endl;
  }
  prop = node1->GetSelectedLineProperty();
  if (prop == nullptr)
  {
    std::cout << "Selected Line Property is nullptr." << std::endl;
  }

  double pt3[3] = { 1, 2, 3 };
  node1->SetHandlePosition(3, pt3);

  node1->SetNumberOfHandles(10);
  int numHandles = node1->GetNumberOfHandles();
  if (numHandles != 10)
  {
    std::cerr << "Error in Setting number of Handles to 10, got " << numHandles << std::endl;
    return EXIT_FAILURE;
  }

  double testPt[3];
  node1->GetHandlePosition(3, testPt);
  if (testPt[0] != pt3[0] || testPt[1] != pt3[1] || testPt[2] != pt3[2])
  {
    std::cerr << "Handle position 3 changed after resize, but should have stayed the same.\n";
    return EXIT_FAILURE;
  }

  node1->SetNumberOfHandles(-1);
  numHandles = node1->GetNumberOfHandles();
  std::cout << "After setting num handles to -1, got back " << numHandles << std::endl;
  node1->SetNumberOfHandles(0);
  numHandles = node1->GetNumberOfHandles();
  std::cout << "After setting num handles to 0, got back " << numHandles << std::endl;

  numHandles = 5;
  node1->SetNumberOfHandles(numHandles);
  double x, y, z;
  x = y = z = 0.0;
  double xyz[3] = { 0.0, 0.0, 0.0 };
  double* hpos;
  double hpos2[3];
  for (int h = 0; h < numHandles; h++)
  {
    node1->SetHandlePosition(h, x, y, z);
    hpos = node1->GetHandlePosition(h);
    if (!hpos)
    {
      std::cerr << "Null handle position back for handle " << h << std::endl;
      return EXIT_FAILURE;
    }
    else if (hpos[0] != x || hpos[1] != y || hpos[2] != z)
    {
      std::cerr << "Failure in SetHandlePosition(" << h << "," << x << "," << y << "," << z
                << "), got " << hpos[0] << ", " << hpos[1] << ", " << hpos[2] << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Handle " << h << " position = " << hpos[0] << ", " << hpos[1] << ", " << hpos[2]
                << std::endl;
    }
    node1->GetHandlePosition(h, hpos2);
    if (hpos2[0] != x || hpos2[1] != y || hpos2[2] != z)
    {
      std::cerr << "Failure in SetHandlePosition(" << h << "," << x << "," << y << "," << z
                << "), got " << hpos2[0] << ", " << hpos2[1] << ", " << hpos2[2] << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Handle " << h << " position = " << hpos2[0] << ", " << hpos2[1] << ", "
                << hpos2[2] << std::endl;
    }

    node1->SetHandlePosition(h, xyz);
    hpos = node1->GetHandlePosition(h);
    if (!hpos)
    {
      std::cerr << "Null handle position back for handle " << h << std::endl;
      return EXIT_FAILURE;
    }
    else if (hpos[0] != xyz[0] || hpos[1] != xyz[1] || hpos[2] != xyz[2])
    {
      std::cerr << "Failure in SetHandlePosition(" << h << ", xyz), expected " << xyz[0] << ", "
                << xyz[1] << ", " << xyz[2] << ", got " << hpos[0] << ", " << hpos[1] << ", "
                << hpos[2] << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Handle " << h << " position = " << hpos[0] << ", " << hpos[1] << ", " << hpos[2]
                << std::endl;
    }
    node1->GetHandlePosition(h, hpos2);
    if (hpos2[0] != xyz[0] || hpos2[1] != xyz[1] || hpos2[2] != xyz[2])
    {
      std::cerr << "Failure in SetHandlePosition(" << h << ",xyz), , expected " << xyz[0] << ", "
                << xyz[1] << ", " << xyz[2] << ", got " << hpos2[0] << ", " << hpos2[1] << ", "
                << hpos2[2] << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Handle " << h << " position xyz = " << hpos2[0] << ", " << hpos2[1] << ", "
                << hpos2[2] << std::endl;
    }
    x -= 1.0;
    y += 1.0;
    z += 2.5;
    xyz[0] += 1.0;
    xyz[1] -= 1.0;
    xyz[2] += 3.9;
  }
  vtkSmartPointer<vtkDoubleArray> da = node1->GetHandlePositions();
  if (da == nullptr)
  {
    std::cerr << "HandlePositions array is null!" << std::endl;
    return EXIT_FAILURE;
  }
  else
  {
    for (vtkIdType i = 0; i < da->GetNumberOfTuples(); i++)
    {
      double val[3];
      da->GetTypedTuple(i, val);
      std::cout << i << " = " << val[0] << ", " << val[1] << ", " << val[2] << std::endl;
    }
  }

  TEST_SET_GET_BOOLEAN(node1, Closed);
  std::cout << "Closed = " << node1->IsClosed() << std::endl;

  std::cout << "Summed Length = " << node1->GetSummedLength();

  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  points->SetNumberOfPoints(2);
  points->SetPoint(0, 3.0, 6.8, -9.9);
  points->SetPoint(1, -3.0, -6.8, 9.9);
  node1->InitializeHandles(points);
  da = node1->GetHandlePositions();
  if (da == nullptr)
  {
    std::cerr << "HandlePositions array is null after initing with vtkPoints!" << std::endl;
    return EXIT_FAILURE;
  }
  else
  {
    for (vtkIdType i = 0; i < da->GetNumberOfTuples(); i++)
    {
      double val[3];
      da->GetTypedTuple(i, val);
      std::cout << i << " = " << val[0] << ", " << val[1] << ", " << val[2] << std::endl;
    }
  }

  node1->SetLineColor(1.0, 0.5, 0.3);

  return EXIT_SUCCESS;
}
