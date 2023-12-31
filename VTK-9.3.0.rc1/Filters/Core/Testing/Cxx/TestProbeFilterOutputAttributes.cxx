// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// This is a test to check that the active attributes are set
// appropriately in the output when passing attribute data to the
// output.

#include "vtkProbeFilter.h"

#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkPolyData.h"
#include "vtkRTAnalyticSource.h"
#include "vtkSmartPointer.h"
#include "vtkSphereSource.h"

//------------------------------------------------------------------------------
int TestProbeFilterOutputAttributes(int, char*[])
{
  vtkNew<vtkSphereSource> sphere;
  sphere->SetRadius(4.0);

  static const int dim = 48;
  double center[3];
  center[0] = center[1] = center[2] = static_cast<double>(dim) / 2.0;
  int extent[6] = { 0, dim - 1, 0, dim - 1, 0, dim - 1 };

  vtkNew<vtkRTAnalyticSource> imageSource;
  imageSource->SetWholeExtent(extent[0], extent[1], extent[2], extent[3], extent[4], extent[5]);
  imageSource->SetCenter(center);

  vtkNew<vtkProbeFilter> probe;
  probe->PassPointArraysOn();
  probe->SetSourceConnection(imageSource->GetOutputPort());
  probe->SetInputConnection(sphere->GetOutputPort());
  probe->Update();

  vtkPolyData* pd = probe->GetPolyDataOutput();
  vtkPointData* spherePointData = sphere->GetOutput()->GetPointData();
  vtkPointData* probePointData = pd->GetPointData();

  std::cout << spherePointData->GetNormals() << " " << probePointData->GetNormals() << std::endl;

  if (probePointData->GetNormals() != spherePointData->GetNormals())
  {
    std::cout << "The normals array does not match!\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
