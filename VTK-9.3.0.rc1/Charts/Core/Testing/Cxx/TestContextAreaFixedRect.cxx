// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkPropItem.h"

#include "vtkActor.h"
#include "vtkAxis.h"
#include "vtkBoundingBox.h"
#include "vtkContextArea.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkContourFilter.h"
#include "vtkDEMReader.h"
#include "vtkImageData.h"
#include "vtkImageDataGeometryFilter.h"
#include "vtkLookupTable.h"
#include "vtkNew.h"
#include "vtkPen.h"
#include "vtkPointData.h"
#include "vtkPolyDataMapper.h"
#include "vtkRect.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkStripper.h"
#include "vtkTestUtilities.h"
#include "vtkTextProperty.h"

//------------------------------------------------------------------------------
int TestContextAreaFixedRect(int argc, char* argv[])
{
  // Prepare some data for plotting:
  char* fname = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/SainteHelens.dem");
  vtkNew<vtkDEMReader> demReader;
  demReader->SetFileName(fname);
  delete[] fname;

  // Get dataset metadata:
  demReader->Update();
  vtkBoundingBox bounds(demReader->GetOutput()->GetBounds());
  double scalarRange[2];
  demReader->GetOutput()->GetScalarRange(scalarRange);

  // Raw data:
  vtkNew<vtkImageDataGeometryFilter> imageToPd;
  imageToPd->SetInputConnection(demReader->GetOutputPort());

  vtkNew<vtkPolyDataMapper> imageMapper;
  imageMapper->SetInputConnection(imageToPd->GetOutputPort());
  imageMapper->SetScalarVisibility(1);

  vtkNew<vtkLookupTable> imageLUT;
  imageLUT->SetHueRange(0.6, 0);
  imageLUT->SetSaturationRange(1.0, 0.25);
  imageLUT->SetValueRange(0.5, 1.0);

  imageMapper->SetLookupTable(imageLUT);
  imageMapper->SetScalarRange(scalarRange);

  vtkNew<vtkActor> imageActor;
  imageActor->SetMapper(imageMapper);

  vtkNew<vtkPropItem> imageItem;
  imageItem->SetPropObject(imageActor);

  // Contours:
  double range[2];
  demReader->Update();
  demReader->GetOutput()->GetPointData()->GetScalars()->GetRange(range);

  vtkNew<vtkContourFilter> contours;
  contours->SetInputConnection(demReader->GetOutputPort());
  contours->GenerateValues(21, range[0], range[1]);

  vtkNew<vtkStripper> contourStripper;
  contourStripper->SetInputConnection(contours->GetOutputPort());

  vtkNew<vtkPolyDataMapper> contourMapper;
  contourMapper->SetInputConnection(contourStripper->GetOutputPort());

  vtkNew<vtkLookupTable> contourLUT;
  contourLUT->SetHueRange(0.6, 0);
  contourLUT->SetSaturationRange(0.75, 1.0);
  contourLUT->SetValueRange(0.25, 0.75);

  contourMapper->SetLookupTable(contourLUT);
  contourMapper->SetScalarRange(scalarRange);

  vtkNew<vtkActor> contourActor;
  contourActor->SetMapper(contourMapper);

  vtkNew<vtkPropItem> contourItem;
  contourItem->SetPropObject(contourActor);

  //----------------------------------------------------------------------------
  // Context2D initialization:

  vtkNew<vtkContextView> view;
  view->GetRenderer()->SetBackground(0.2, 0.2, 0.7);
  view->GetRenderWindow()->SetSize(600, 600);
  view->GetRenderWindow()->StencilCapableOn(); // For vtkLabeledContourMapper
  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetInteractor()->Initialize();

  vtkNew<vtkContextArea> area;
  area->SetDrawAreaBounds(
    vtkRectd(bounds.GetBound(0), bounds.GetBound(2), bounds.GetLength(0), bounds.GetLength(1)));
  area->SetFixedRect(100, 50, 200, 400);

  area->GetAxis(vtkAxis::TOP)->SetTitle("Top Axis");
  area->GetAxis(vtkAxis::BOTTOM)->SetTitle("Bottom Axis");
  area->GetAxis(vtkAxis::LEFT)->SetTitle("Left Axis");
  area->GetAxis(vtkAxis::RIGHT)->SetTitle("Right Axis");

  for (int i = 0; i < 4; ++i)
  {
    vtkAxis* axis = area->GetAxis(static_cast<vtkAxis::Location>(i));
    axis->GetLabelProperties()->SetColor(.6, .6, .9);
    axis->GetTitleProperties()->SetColor(.6, .6, .9);
    axis->GetPen()->SetColor(.6 * 255, .6 * 255, .9 * 255, 255);
    axis->GetGridPen()->SetColor(.6 * 255, .6 * 255, .9 * 255, 128);
  }

  area->GetDrawAreaItem()->AddItem(imageItem);
  area->GetDrawAreaItem()->AddItem(contourItem);

  view->GetScene()->AddItem(area);

  view->GetInteractor()->Start();
  return EXIT_SUCCESS;
}
