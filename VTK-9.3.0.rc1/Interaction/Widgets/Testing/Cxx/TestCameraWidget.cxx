// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
//
// This example tests the vtkCameraWidget.

// First include the required header files for the VTK classes we are using.
#include "vtkSmartPointer.h"

#include "vtkActor.h"
#include "vtkCameraRepresentation.h"
#include "vtkCameraWidget.h"
#include "vtkCommand.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkTesting.h"

int TestCameraWidget(int argc, char* argv[])
{
  // Create the RenderWindow, Renderer and both Actors
  //
  vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
  renWin->AddRenderer(ren1);

  vtkSmartPointer<vtkRenderWindowInteractor> iren =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  iren->SetRenderWindow(renWin);

  // Create a test pipeline
  //
  vtkSmartPointer<vtkSphereSource> ss = vtkSmartPointer<vtkSphereSource>::New();
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(ss->GetOutputPort());
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  // Create the widget
  vtkSmartPointer<vtkCameraRepresentation> rep = vtkSmartPointer<vtkCameraRepresentation>::New();
  rep->SetNumberOfFrames(2400);

  vtkSmartPointer<vtkCameraWidget> widget = vtkSmartPointer<vtkCameraWidget>::New();
  widget->SetInteractor(iren);
  widget->SetRepresentation(rep);

  // Add the actors to the renderer, set the background and size
  //
  ren1->AddActor(actor);
  ren1->SetBackground(0.1, 0.2, 0.4);
  renWin->SetSize(300, 300);

  // render the image
  //
  iren->Initialize();
  renWin->Render();
  rep->SetCamera(ren1->GetActiveCamera());
  widget->On();

  int retVal = vtkTesting::InteractorEventLoop(argc, argv, iren);

  return retVal;
}
