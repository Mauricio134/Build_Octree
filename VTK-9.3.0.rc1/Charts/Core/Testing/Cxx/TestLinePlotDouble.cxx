// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkChartXY.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkDoubleArray.h"
#include "vtkFloatingPointExceptions.h"
#include "vtkMath.h"
#include "vtkNew.h"
#include "vtkPlot.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkTable.h"
//------------------------------------------------------------------------------
int TestLinePlotDouble(int, char*[])
{
  // Thus test will cause floating point because it uses inf and nan for some
  // numbers
  vtkFloatingPointExceptions::Disable();

  // Set up a 2D scene, add an XY chart to it
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetSize(400, 300);
  vtkNew<vtkChartXY> chart;
  view->GetScene()->AddItem(chart);

  // Create a table with some points in it...
  vtkNew<vtkTable> table;
  vtkNew<vtkDoubleArray> arrX;
  arrX->SetName("X Axis");
  table->AddColumn(arrX);
  vtkNew<vtkDoubleArray> arrC;
  arrC->SetName("Cosine");
  table->AddColumn(arrC);
  vtkNew<vtkDoubleArray> arrS;
  arrS->SetName("Sine");
  table->AddColumn(arrS);
  vtkNew<vtkDoubleArray> arrS2;
  arrS2->SetName("Sine2");
  table->AddColumn(arrS2);
  // Test charting with a few more points...
  int numPoints = 69;
  float inc = 7.5 / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc);
    table->SetValue(i, 1, 1.0e-80 * cos(i * inc - 1.0) * 1.0e-8);
    table->SetValue(i, 2, 1.0e-80 * sin(i * inc) * 1.0e-8);
    table->SetValue(i, 3, 1.0e80 * sin(i * inc - 1.0));
  }
  table->SetValue(66, 2, vtkMath::Nan());
  table->SetValue(4, 3, vtkMath::Inf());

  // Add multiple line plots, setting the colors etc
  vtkPlot* line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table, 0, 1);
  line->SetColor(0, 255, 0, 255);
  line->SetWidth(1.0);
  line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table, 0, 2);
  line->SetColor(255, 0, 0, 255);
  line->SetWidth(5.0);
  line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table, 0, 3);
  line->SetColor(0, 0, 255, 255);
  line->SetWidth(4.0);
  chart->SetPlotCorner(line, 1);

  // Render the scene and compare the image to a reference image
  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

  return EXIT_SUCCESS;
}
