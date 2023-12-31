// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// Description
// This test creates a wavelet dataset and creates isosurfaces using
// vtkFlyingEdges3D

#include "vtkActor.h"
#include "vtkFlyingEdges3D.h"
#include "vtkNew.h"
#include "vtkPolyDataMapper.h"
#include "vtkRTAnalyticSource.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTesting.h"

int TestFlyingEdges(int argc, char* argv[])
{
  // Create the sample dataset
  vtkNew<vtkRTAnalyticSource> wavelet;
  wavelet->SetWholeExtent(-63, 64, -63, 64, -63, 64);
  wavelet->SetCenter(0.0, 0.0, 0.0);
  wavelet->Update();

  vtkNew<vtkFlyingEdges3D> flyingEdges;
  flyingEdges->SetInputConnection(wavelet->GetOutputPort());
  flyingEdges->GenerateValues(6, 128.0, 225.0);
  flyingEdges->ComputeNormalsOn();
  flyingEdges->ComputeGradientsOn();
  flyingEdges->ComputeScalarsOn();
  flyingEdges->SetArrayComponent(0);

  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(flyingEdges->GetOutputPort());
  mapper->SetScalarRange(128, 225);
  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);
  vtkNew<vtkRenderer> ren;
  ren->AddActor(actor);

  vtkNew<vtkRenderWindow> renWin;
  renWin->SetSize(399, 401);
  renWin->SetMultiSamples(0);
  renWin->AddRenderer(ren);
  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renWin);

  ren->ResetCamera();
  renWin->Render();

  int retVal = vtkRegressionTestImage(renWin);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }
  return !retVal;
}
