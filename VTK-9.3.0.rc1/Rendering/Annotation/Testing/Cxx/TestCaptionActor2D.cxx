// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtkCaptionActor2D.h>
#include <vtkNew.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>

int TestCaptionActor2D(int, char*[])
{
  // Draw text with diameter measure
  vtkNew<vtkCaptionActor2D> captionActor;
  captionActor->SetAttachmentPoint(0, 0, 0);
  captionActor->SetCaption("(2) 2.27");
  captionActor->BorderOff();
  captionActor->LeaderOff();
  captionActor->SetPadding(0);
  captionActor->GetCaptionTextProperty()->SetJustificationToLeft();
  captionActor->GetCaptionTextProperty()->ShadowOff();
  captionActor->GetCaptionTextProperty()->ItalicOff();
  captionActor->GetCaptionTextProperty()->SetFontFamilyToCourier();
  captionActor->GetCaptionTextProperty()->SetFontSize(24);
  captionActor->GetTextActor()->SetTextScaleModeToNone();

  vtkNew<vtkRenderer> renderer;
  renderer->SetBackground(0, 0, 0);
  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->AddRenderer(renderer);
  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(captionActor);

  renderWindow->SetMultiSamples(0);
  renderWindow->Render();
  renderWindow->GetInteractor()->Initialize();
  renderWindow->GetInteractor()->Start();

  return EXIT_SUCCESS;
}
