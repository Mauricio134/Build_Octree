// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkImageActor.h"
#include "vtkImageData.h"
#include "vtkImageMandelbrotSource.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkImageMapper3D.h"
#include "vtkImageShiftScale.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkTextProperty.h"

#include "vtkActor.h"
#include "vtkCornerAnnotation.h"
#include "vtkPolyDataMapper.h"
#include "vtkRegressionTestImage.h"

int TestCornerAnnotation(int argc, char* argv[])
{
  vtkSmartPointer<vtkImageMandelbrotSource> imageSource =
    vtkSmartPointer<vtkImageMandelbrotSource>::New();
  vtkSmartPointer<vtkImageShiftScale> imageCast = vtkSmartPointer<vtkImageShiftScale>::New();
  imageCast->SetInputConnection(imageSource->GetOutputPort());
  imageCast->SetScale(100);
  imageCast->SetShift(0);
  imageCast->SetOutputScalarTypeToShort();
  imageCast->Update();

  vtkSmartPointer<vtkImageMapToWindowLevelColors> imageWL =
    vtkSmartPointer<vtkImageMapToWindowLevelColors>::New();
  imageWL->SetInputConnection(imageCast->GetOutputPort());
  imageWL->SetWindow(10000);
  imageWL->SetLevel(5000);
  vtkSmartPointer<vtkImageActor> imageActor = vtkSmartPointer<vtkImageActor>::New();
  imageActor->GetMapper()->SetInputConnection(imageWL->GetOutputPort());

  // Visualize
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  renderWindow->SetSize(800, 600);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  renderer->AddActor(imageActor);

  // Annotate the image with window/level and mouse over pixel information
  vtkSmartPointer<vtkCornerAnnotation> cornerAnnotation =
    vtkSmartPointer<vtkCornerAnnotation>::New();

  cornerAnnotation->SetImageActor(imageActor);
  cornerAnnotation->SetWindowLevel(imageWL);

  cornerAnnotation->SetLinearFontScaleFactor(2);
  cornerAnnotation->SetNonlinearFontScaleFactor(1);
  cornerAnnotation->SetMaximumFontSize(20);

  cornerAnnotation->SetText(vtkCornerAnnotation::LowerLeft, "LL (<image>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::LowerRight, "LR (<image_and_max>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::UpperLeft, "UL (<slice>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::UpperRight, "UR (<slice_and_max>)");

  cornerAnnotation->SetText(vtkCornerAnnotation::UpperEdge, "T (<window_level>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::LowerEdge, "B (<slice_pos>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::LeftEdge, "L (<window>)");
  cornerAnnotation->SetText(vtkCornerAnnotation::RightEdge, "R (<level>)");

  cornerAnnotation->GetTextProperty()->SetColor(1, 0, 0);

  renderer->AddViewProp(cornerAnnotation);

  renderWindow->Render();

  int retVal = vtkRegressionTestImage(renderWindow);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    renderWindowInteractor->Start();
  }

  return !retVal;
}
