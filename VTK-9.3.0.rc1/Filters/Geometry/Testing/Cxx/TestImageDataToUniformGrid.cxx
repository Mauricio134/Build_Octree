// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME TestImageDAtaToUniformGrid.cxx --Test vtkImageDataToUniformGrid
//
// .SECTION Description
// Serial tests for converting an image data to a uniform grid with blanking.

// VTK includes
#include <vtkDataSet.h>
#include <vtkElevationFilter.h>
#include <vtkImageDataToUniformGrid.h>
#include <vtkMultiBlockDataGroupFilter.h>
#include <vtkMultiBlockDataSet.h>
#include <vtkNew.h>
#include <vtkPointDataToCellData.h>
#include <vtkRTAnalyticSource.h>
#include <vtkSphereSource.h>
#include <vtkThreshold.h>
#include <vtkUnstructuredGrid.h>

// C++ includes
#include <iostream>

namespace
{

// returns 0 for success.
int TestSingleGridBlanking(bool pointBlanking, bool reverse, int expectedNumberOfCells)
{
  vtkNew<vtkRTAnalyticSource> source;
  vtkNew<vtkElevationFilter> elevation;
  elevation->SetInputConnection(source->GetOutputPort());
  elevation->SetLowPoint(-10, 0, 0);
  elevation->SetHighPoint(10, 0, 0);
  elevation->SetScalarRange(0, 3);
  vtkNew<vtkPointDataToCellData> pointDataToCellData;
  pointDataToCellData->SetInputConnection(elevation->GetOutputPort());
  pointDataToCellData->PassPointDataOn();

  pointDataToCellData->Update();

  vtkNew<vtkImageDataToUniformGrid> imageDataToUniformGrid;
  imageDataToUniformGrid->SetInputConnection(pointDataToCellData->GetOutputPort());
  imageDataToUniformGrid->SetReverse(reverse);
  if (pointBlanking)
  {
    imageDataToUniformGrid->SetInputArrayToProcess(
      0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_POINTS, "Elevation");
  }
  else
  {
    imageDataToUniformGrid->SetInputArrayToProcess(
      0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_CELLS, "Elevation");
  }
  imageDataToUniformGrid->Update();

  // the threshold filter is really meant to create an unstructured
  // grid. The threshold is set to include the range of RTData so that
  // the only cells that aren't outputted from the threshold filter
  // are the blanked cells.
  vtkNew<vtkThreshold> threshold;
  threshold->SetInputArrayToProcess(0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_POINTS, "RTData");
  threshold->SetThresholdFunction(vtkThreshold::THRESHOLD_BETWEEN);
  threshold->SetLowerThreshold(-1000.0);
  threshold->SetUpperThreshold(1000.0);
  threshold->SetInputConnection(imageDataToUniformGrid->GetOutputPort());
  threshold->Update();
  vtkUnstructuredGrid* outputGrid = threshold->GetOutput();

  if (outputGrid->GetNumberOfCells() == expectedNumberOfCells)
  {
    return 0;
  }
  vtkGenericWarningMacro(
    "Expecting " << expectedNumberOfCells << " but getting " << outputGrid->GetNumberOfCells());
  return 1;
}

// returns 0 for success. only tests point blanking
int TestMultiBlockBlanking(int expectedNumberOfCells)
{
  vtkNew<vtkRTAnalyticSource> source;
  vtkNew<vtkElevationFilter> elevation;
  elevation->SetInputConnection(source->GetOutputPort());
  elevation->SetLowPoint(-10, 0, 0);
  elevation->SetHighPoint(10, 0, 0);
  elevation->SetScalarRange(0, 3);
  vtkNew<vtkPointDataToCellData> pointDataToCellData;
  pointDataToCellData->SetInputConnection(elevation->GetOutputPort());
  pointDataToCellData->PassPointDataOn();

  vtkNew<vtkSphereSource> sphereSource;
  vtkNew<vtkMultiBlockDataGroupFilter> groupFilter;
  groupFilter->SetInputConnection(pointDataToCellData->GetOutputPort());
  groupFilter->SetInputConnection(pointDataToCellData->GetOutputPort());
  groupFilter->AddInputConnection(sphereSource->GetOutputPort());

  vtkNew<vtkImageDataToUniformGrid> imageDataToUniformGrid;
  imageDataToUniformGrid->SetInputConnection(groupFilter->GetOutputPort());
  imageDataToUniformGrid->SetInputArrayToProcess(
    0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_POINTS, "Elevation");
  imageDataToUniformGrid->Update();
  vtkMultiBlockDataSet* output =
    vtkMultiBlockDataSet::SafeDownCast(imageDataToUniformGrid->GetOutput());

  vtkNew<vtkThreshold> threshold;
  threshold->SetInputArrayToProcess(0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_POINTS, "RTData");
  threshold->SetThresholdFunction(vtkThreshold::THRESHOLD_BETWEEN);
  threshold->SetLowerThreshold(50.0);
  threshold->SetUpperThreshold(150.0);
  threshold->SetInputData(output->GetBlock(0));
  threshold->Update();
  vtkUnstructuredGrid* outputGrid = threshold->GetOutput();

  if (outputGrid->GetNumberOfCells() == expectedNumberOfCells)
  {
    return 0;
  }
  vtkGenericWarningMacro(
    "Expecting " << expectedNumberOfCells << " but getting " << outputGrid->GetNumberOfCells());
  return 1;
}

} // end anonymous namespace

//------------------------------------------------------------------------------
// Program main
int TestImageDataToUniformGrid(int, char*[])
{
  int rc = TestSingleGridBlanking(true, false, 5200);
  rc += TestSingleGridBlanking(false, false, 5200);

  rc += TestSingleGridBlanking(true, true, 2400);
  // note that this and the second call to TestSingleGridBlanking
  // are opposites so they should add up to 8000 cells.
  rc += TestSingleGridBlanking(false, true, 2800);

  rc += TestMultiBlockBlanking(1102);

  return rc;
}
