// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkAxis.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkNew.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkTextProperty.h"

//------------------------------------------------------------------------------
int TestAxes2(int, char*[])
{
  int status = EXIT_SUCCESS;

  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetSize(200, 200);

  vtkNew<vtkAxis> axisVertical;

  axisVertical->LogScaleOn();
  axisVertical->SetPoint1(vtkVector2f(180, 16));
  axisVertical->SetPoint2(vtkVector2f(180, 184));
  axisVertical->SetPosition(vtkAxis::LEFT);

  axisVertical->SetNotation(vtkAxis::SCIENTIFIC_NOTATION);
  axisVertical->SetPosition(vtkAxis::LEFT);
  axisVertical->SetPrecision(0);
  axisVertical->SetRange(0.1, 1000000.);
  axisVertical->SetRangeLabelsVisible(true);
  //  We need a larger than normal font size to ensure that AllowShift = 1
  //  doesn't let tests that shouldn't pass pass.
  axisVertical->GetLabelProperties()->SetFontSize(24);

  view->GetScene()->AddItem(axisVertical);

  axisVertical->Update();

  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

  return status;
}
