// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// This test covers rendering of a text actor with alpha blending.
//
// The command line arguments are:
// -I        => run in interactive mode; unless this is used, the program will
//              not allow interaction and exit

#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

#include "vtkCamera.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTextActor.h"
#include "vtkTextProperty.h"

int TestTextActorAlphaBlending(int argc, char* argv[])
{
  vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  iren->SetRenderWindow(renWin);
  renWin->Delete();

  vtkRenderer* renderer = vtkRenderer::New();
  renWin->AddRenderer(renderer);
  renderer->Delete();

  renderer->SetBackground(0.1, 0.2, 0.4);
  renWin->SetSize(300, 300);

  vtkTextActor* actor = vtkTextActor::New();
  actor->SetInput("Testing vtkTextActor with alpha blending.\nLine 2.\nLine 3.");
  actor->SetDisplayPosition(150, 150);
  actor->GetTextProperty()->SetJustificationToCentered();

  renderer->AddActor(actor);
  actor->Delete();

  renWin->Render();
  int retVal = vtkRegressionTestImage(renWin);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }
  iren->Delete();

  return !retVal;
}
