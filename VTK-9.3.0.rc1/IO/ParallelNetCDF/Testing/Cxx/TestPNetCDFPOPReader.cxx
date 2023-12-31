// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME Test of vtkPNetCDFPOPReader
// .SECTION Description
// Tests the vtkPNetCDFPOPReader.

#include "vtkPNetCDFPOPReader.h"

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkGeometryFilter.h"
#include "vtkMPIController.h"
#include "vtkPointData.h"
#include "vtkPolyDataMapper.h"
#include "vtkRectilinearGrid.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkTestUtilities.h"

int TestPNetCDFPOPReader(int argc, char* argv[])
{
  vtkMPIController* controller = vtkMPIController::New();

  controller->Initialize(&argc, &argv, 0);
  vtkMPIController::SetGlobalController(controller);

  // Read file name.
  char* fname = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/NetCDF/test.pop.nc");

  // Create the reader.
  vtkSmartPointer<vtkPNetCDFPOPReader> reader = vtkSmartPointer<vtkPNetCDFPOPReader>::New();
  reader->SetFileName(fname);
  reader->SetStride(2, 3, 4);
  delete[] fname;
  reader->Update();
  vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(reader->GetOutput());
  grid->GetPointData()->SetScalars(grid->GetPointData()->GetArray("DYE01"));

  // Convert to PolyData.
  vtkGeometryFilter* geometryFilter = vtkGeometryFilter::New();
  geometryFilter->SetInputConnection(reader->GetOutputPort());

  // Create a mapper.
  vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
  mapper->SetInputConnection(geometryFilter->GetOutputPort());
  mapper->ScalarVisibilityOn();

  // Create the actor.
  vtkActor* actor = vtkActor::New();
  actor->SetMapper(mapper);

  // Basic visualisation.
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  vtkRenderer* ren = vtkRenderer::New();
  renWin->AddRenderer(ren);
  vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  vtkCamera* camera = ren->GetActiveCamera();
  ren->ResetCamera(grid->GetBounds());
  camera->Zoom(8);

  ren->AddActor(actor);
  ren->SetBackground(0, 0, 0);
  renWin->SetSize(300, 300);

  // interact with data
  renWin->Render();

  int retVal = vtkRegressionTestImage(renWin);

  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }

  actor->Delete();
  mapper->Delete();
  geometryFilter->Delete();
  renWin->Delete();
  ren->Delete();
  iren->Delete();

  controller->Finalize(0);
  controller->Delete();

  return !retVal;
}
