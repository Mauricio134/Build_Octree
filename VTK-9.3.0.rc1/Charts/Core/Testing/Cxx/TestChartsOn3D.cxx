// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkChartXY.h"
#include "vtkContextActor.h"
#include "vtkContextScene.h"
#include "vtkCubeSource.h"
#include "vtkFloatArray.h"
#include "vtkNew.h"
#include "vtkPlotPoints.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTable.h"

//------------------------------------------------------------------------------
int TestChartsOn3D(int, char*[])
{

  vtkNew<vtkRenderWindow> renwin;
  renwin->SetMultiSamples(4);
  renwin->SetSize(600, 400);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renwin);

  vtkNew<vtkRenderer> renderer;
  renderer->SetBackground(0.8, 0.8, 0.8);
  renwin->AddRenderer(renderer);

  renderer->ResetCamera();
  renderer->GetActiveCamera()->SetPosition(1.0, 1.0, -4.0);
  renderer->GetActiveCamera()->Azimuth(40);

  // Cube Source 1
  vtkNew<vtkCubeSource> cube;
  vtkNew<vtkPolyDataMapper> cubeMapper;
  vtkNew<vtkActor> cubeActor;

  cubeMapper->SetInputConnection(cube->GetOutputPort());
  cubeActor->SetMapper(cubeMapper);
  cubeActor->GetProperty()->SetColor(1.0, 0.0, 0.0);
  renderer->AddActor(cubeActor);
  cubeActor->GetProperty()->SetRepresentationToSurface();

  // Now the chart
  vtkNew<vtkChartXY> chart;
  vtkNew<vtkContextScene> chartScene;
  vtkNew<vtkContextActor> chartActor;

  chart->SetAutoSize(false);
  chart->SetSize(vtkRectf(0.0, 0.0, 300, 200));

  chartScene->AddItem(chart);
  chartActor->SetScene(chartScene);

  // both needed
  renderer->AddActor(chartActor);
  chartScene->SetRenderer(renderer);

  // Create a table with some points in it...
  vtkNew<vtkTable> table;
  vtkNew<vtkFloatArray> arrX;
  arrX->SetName("X Axis");
  table->AddColumn(arrX);
  vtkNew<vtkFloatArray> arrC;
  arrC->SetName("Cosine");
  table->AddColumn(arrC);
  vtkNew<vtkFloatArray> arrS;
  arrS->SetName("Sine");
  table->AddColumn(arrS);
  vtkNew<vtkFloatArray> arrT;
  arrT->SetName("Tan");
  table->AddColumn(arrT);
  // Test charting with a few more points...
  int numPoints = 69;
  float inc = 7.5 / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc);
    table->SetValue(i, 1, cos(i * inc) + 0.0);
    table->SetValue(i, 2, sin(i * inc) + 0.0);
    table->SetValue(i, 3, tan(i * inc) + 0.5);
  }

  // Add multiple line plots, setting the colors etc
  vtkPlot* points = chart->AddPlot(vtkChart::POINTS);
  points->SetInputData(table, 0, 1);
  points->SetColor(0, 0, 0, 255);
  points->SetWidth(1.0);
  vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CROSS);
  points = chart->AddPlot(vtkChart::POINTS);
  points->SetInputData(table, 0, 2);
  points->SetColor(0, 0, 0, 255);
  points->SetWidth(1.0);
  vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::PLUS);
  points = chart->AddPlot(vtkChart::POINTS);
  points->SetInputData(table, 0, 3);
  points->SetColor(0, 0, 255, 255);
  points->SetWidth(4.0);

  renwin->SetMultiSamples(0);
  iren->Initialize();
  iren->Start();

  return EXIT_SUCCESS;
}
