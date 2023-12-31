// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkChartXY.h"
#include "vtkColorTransferFunction.h"
#include "vtkCompositeControlPointsItem.h"
#include "vtkCompositeTransferFunctionItem.h"
#include "vtkContext2D.h"
#include "vtkContextDevice2D.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkLookupTable.h"
#include "vtkPiecewiseControlPointsItem.h"
#include "vtkPiecewiseFunction.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkRenderingOpenGLConfigure.h"
#include "vtkSmartPointer.h"

//------------------------------------------------------------------------------
int TestScalarsToColors(int, char*[])
{
  // Set up a 2D scene, add an XY chart to it
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetRenderWindow()->SetSize(400, 300);
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  chart->SetTitle("Chart");
  chart->ForceAxesToBoundsOn();
  view->GetScene()->AddItem(chart);

  vtkSmartPointer<vtkLookupTable> lookupTable = vtkSmartPointer<vtkLookupTable>::New();
  lookupTable->Build();

  vtkSmartPointer<vtkColorTransferFunction> colorTransferFunction =
    vtkSmartPointer<vtkColorTransferFunction>::New();
  colorTransferFunction->AddHSVSegment(0., 0., 1., 1., 0.3333, 0.3333, 1., 1.);
  colorTransferFunction->AddHSVSegment(0.3333, 0.3333, 1., 1., 0.6666, 0.6666, 1., 1.);
  colorTransferFunction->AddHSVSegment(0.6666, 0.6666, 1., 1., 1., 0., 1., 1.);

  colorTransferFunction->Build();

  vtkSmartPointer<vtkPiecewiseFunction> opacityFunction =
    vtkSmartPointer<vtkPiecewiseFunction>::New();
  opacityFunction->AddPoint(0.2, 0.);
  opacityFunction->AddPoint(0.5, 0.5);
  opacityFunction->AddPoint(1., 1.);

  vtkSmartPointer<vtkCompositeTransferFunctionItem> item3 =
    vtkSmartPointer<vtkCompositeTransferFunctionItem>::New();
  item3->SetColorTransferFunction(colorTransferFunction);
  item3->SetOpacityFunction(opacityFunction);
  item3->SetMaskAboveCurve(true);
  chart->AddPlot(item3);

  vtkSmartPointer<vtkCompositeControlPointsItem> item5 =
    vtkSmartPointer<vtkCompositeControlPointsItem>::New();
  item5->SetOpacityFunction(opacityFunction);
  item5->SetColorTransferFunction(colorTransferFunction);
  chart->AddPlot(item5);

  // Finally render the scene and compare the image to a reference image
  view->GetRenderWindow()->SetMultiSamples(1);

  if (view->GetContext()->GetDevice()->IsA("vtkOpenGL2ContextDevice2D"))
  {
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();
  }

  return EXIT_SUCCESS;
}
