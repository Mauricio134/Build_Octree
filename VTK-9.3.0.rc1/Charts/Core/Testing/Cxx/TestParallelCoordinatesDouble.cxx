// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkChartParallelCoordinates.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkDoubleArray.h"
#include "vtkNew.h"
#include "vtkPlot.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTable.h"

//------------------------------------------------------------------------------
int TestParallelCoordinatesDouble(int, char*[])
{
  // Set up a 2D scene, add an XY chart to it
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetSize(600, 400);
  vtkNew<vtkChartParallelCoordinates> chart;
  view->GetScene()->AddItem(chart);

  // Create a table with some points in it...
  vtkNew<vtkTable> table;
  vtkNew<vtkDoubleArray> arrX;
  arrX->SetName("x");
  table->AddColumn(arrX);
  vtkNew<vtkDoubleArray> arrC;
  arrC->SetName("cosine");
  table->AddColumn(arrC);
  vtkNew<vtkDoubleArray> arrS;
  arrS->SetName("sine");
  table->AddColumn(arrS);
  vtkNew<vtkDoubleArray> arrS2;
  arrS2->SetName("tangent");
  table->AddColumn(arrS2);
  // Test charting with a few more points...
  int numPoints = 200;
  float inc = 7.5 / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc);
    table->SetValue(i, 1, cos(i * inc) * 1.0e-82);
    table->SetValue(i, 2, sin(i * inc) * 1.0e+89);
    table->SetValue(i, 3, tan(i * inc) + 0.5);
  }

  chart->GetPlot(0)->SetInputData(table);

  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();
  return EXIT_SUCCESS;
}
