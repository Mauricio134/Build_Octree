// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// .NAME Test of an RGBA texture on a vtkActor.
// .SECTION Description
// this program tests the rendering of an vtkActor with a translucent texture
// with alpha blending.

#include "vtkActor.h"
#include "vtkImageData.h"
#include "vtkPNGReader.h"
#include "vtkPlaneSource.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTestUtilities.h"
#include "vtkTexture.h"

int TestTextureRGBA(int argc, char* argv[])
{
  char* fname = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/textureRGBA.png");

  vtkPNGReader* PNGReader = vtkPNGReader::New();
  PNGReader->SetFileName(fname);
  PNGReader->Update();

  vtkTexture* texture = vtkTexture::New();
  texture->SetInputConnection(PNGReader->GetOutputPort());
  PNGReader->Delete();
  texture->InterpolateOn();

  vtkPlaneSource* planeSource = vtkPlaneSource::New();
  planeSource->Update();

  vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
  mapper->SetInputConnection(planeSource->GetOutputPort());
  planeSource->Delete();

  vtkActor* actor = vtkActor::New();
  actor->SetTexture(texture);
  texture->Delete();
  actor->SetMapper(mapper);
  mapper->Delete();

  vtkRenderer* renderer = vtkRenderer::New();
  renderer->AddActor(actor);
  actor->Delete();
  renderer->SetBackground(0.5, 0.7, 0.7);

  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->AddRenderer(renderer);

  vtkRenderWindowInteractor* interactor = vtkRenderWindowInteractor::New();
  interactor->SetRenderWindow(renWin);

  renWin->SetSize(400, 400);
  renWin->Render();
  interactor->Initialize();
  renWin->Render();

  int retVal = vtkRegressionTestImage(renWin);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    interactor->Start();
  }

  renderer->Delete();
  renWin->Delete();
  interactor->Delete();
  delete[] fname;

  return !retVal;
}
