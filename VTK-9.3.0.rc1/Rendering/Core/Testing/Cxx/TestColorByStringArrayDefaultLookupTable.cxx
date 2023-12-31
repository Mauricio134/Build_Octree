// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

#include <vtkActor.h>
#include <vtkCellData.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkStringArray.h>

int TestColorByStringArrayDefaultLookupTable(int argc, char* argv[])
{
  vtkNew<vtkSphereSource> sphere;
  sphere->Update();

  vtkNew<vtkPolyData> polydata;
  polydata->ShallowCopy(sphere->GetOutput());

  // Set up string array associated with cells
  vtkNew<vtkStringArray> sArray;
  char arrayName[] = "string type";
  sArray->SetName(arrayName);
  sArray->SetNumberOfComponents(1);
  sArray->SetNumberOfTuples(polydata->GetNumberOfCells());

  vtkVariant strings[5];
  strings[0] = "violin";
  strings[1] = "viola";
  strings[2] = "cello";
  strings[3] = "bass";
  strings[4] = "double bass";

  // Round-robin assignment of color strings
  for (int i = 0; i < polydata->GetNumberOfCells(); ++i)
  {
    sArray->SetValue(i, strings[i % 5].ToString());
  }

  vtkCellData* cd = polydata->GetCellData();
  cd->AddArray(sArray);

  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputDataObject(polydata);
  mapper->ScalarVisibilityOn();
  mapper->SetScalarModeToUseCellFieldData();
  mapper->SelectColorArray(arrayName);

  // Direct coloring shouldn't be possible with string arrays, so we
  // enable direct scalars to test that the string arrays get mapped
  // despite the color mode setting being direct scalars.
  mapper->SetColorModeToDirectScalars();

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);

  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(actor);

  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->AddRenderer(renderer);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renderWindow);

  renderWindow->Render();

  int retVal = vtkRegressionTestImage(renderWindow);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }

  return !retVal;
}
