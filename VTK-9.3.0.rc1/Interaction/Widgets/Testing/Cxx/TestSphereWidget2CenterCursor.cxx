// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include <vtkCamera.h>
#include <vtkCommand.h>
#include <vtkMath.h>
#include <vtkNew.h>
#include <vtkRegressionTestImage.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphere.h>
#include <vtkSphereRepresentation.h>
#include <vtkSphereWidget2.h>

int TestSphereWidget2CenterCursor(int argc, char* argv[])
{
  // Create a renderer and a render window
  vtkNew<vtkRenderer> renderer;
  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->AddRenderer(renderer);

  // Create an interactor
  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
  renderWindowInteractor->SetRenderWindow(renderWindow);

  // Create a sphere widget
  vtkNew<vtkSphereWidget2> sphereWidget;
  sphereWidget->SetInteractor(renderWindowInteractor);
  sphereWidget->CreateDefaultRepresentation();

  vtkSphereRepresentation* sphereRepresentation =
    vtkSphereRepresentation::SafeDownCast(sphereWidget->GetRepresentation());
  sphereRepresentation->HandleVisibilityOff();
  double center[3] = { 4, 0, 0 };
  sphereRepresentation->SetCenter(center);
  sphereRepresentation->SetRadius(3);

  // Create a second sphere widget
  vtkNew<vtkSphereWidget2> sphereWidget2;
  sphereWidget2->SetInteractor(renderWindowInteractor);
  sphereWidget2->CreateDefaultRepresentation();

  vtkSphereRepresentation* sphereRepresentation2 =
    vtkSphereRepresentation::SafeDownCast(sphereWidget2->GetRepresentation());
  sphereRepresentation2->HandleVisibilityOff();
  double center2[3] = { -4, 0, 0 };
  sphereRepresentation2->SetCenter(center2);
  sphereRepresentation2->SetRadius(3);
  sphereRepresentation2->SetCenterCursor(true);

  vtkCamera* camera = renderer->GetActiveCamera();
  renderWindow->SetSize(300, 300);
  camera->SetPosition(0.0, 0.0, 20.0);
  camera->SetFocalPoint(0.0, 0.0, -1);

  renderWindow->Render();
  renderWindowInteractor->Initialize();
  sphereWidget->On();
  sphereWidget2->On();
  renderWindow->Render();

  int retVal = vtkRegressionTestImage(renderWindow);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    renderWindowInteractor->Start();
  }
  return !retVal;
}
