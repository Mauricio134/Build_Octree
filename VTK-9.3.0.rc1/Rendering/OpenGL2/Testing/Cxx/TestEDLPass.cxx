// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// test baking shadow maps
//
// The command line arguments are:
// -I        => run in interactive mode; unless this is used, the program will
//              not allow interaction and exit

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkEDLShading.h"
#include "vtkNew.h"
#include "vtkOpenGLRenderer.h"
#include "vtkPLYReader.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderStepsPass.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTestUtilities.h"
#include "vtkTimerLog.h"

//------------------------------------------------------------------------------
int TestEDLPass(int argc, char* argv[])
{
  vtkNew<vtkRenderer> renderer;
  renderer->SetBackground(0.3, 0.4, 0.6);
  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->SetSize(600, 600);
  renderWindow->AddRenderer(renderer);
  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renderWindow);

  const char* fileName = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/dragon.ply");
  vtkNew<vtkPLYReader> reader;
  reader->SetFileName(fileName);
  reader->Update();
  delete[] fileName;

  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(reader->GetOutputPort());

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);
  actor->GetProperty()->SetAmbientColor(0.135, 0.2225, 0.3);
  actor->GetProperty()->SetDiffuseColor(0.54, 0.89, 0.63);
  actor->GetProperty()->SetDiffuse(0.7);
  actor->GetProperty()->SetAmbient(0.7);
  actor->GetProperty()->LightingOff();
  renderer->AddActor(actor);
  // actor->GetProperty()->SetRepresentationToWireframe();

  renderWindow->SetMultiSamples(0);

  // create the basic VTK render steps
  vtkNew<vtkRenderStepsPass> basicPasses;

  // finally blur the resulting image
  // The blur delegates rendering the unblured image
  // to the basicPasses
  vtkNew<vtkEDLShading> edl;
  edl->SetDelegatePass(basicPasses);

  // tell the renderer to use our render pass pipeline
  vtkOpenGLRenderer* glrenderer = vtkOpenGLRenderer::SafeDownCast(renderer);
  glrenderer->SetPass(edl);

  vtkNew<vtkTimerLog> timer;
  timer->StartTimer();
  renderWindow->Render();
  timer->StopTimer();
  double firstRender = timer->GetElapsedTime();
  cerr << "first render time: " << firstRender << endl;

  timer->StartTimer();
  int numRenders = 8;
  for (int i = 0; i < numRenders; ++i)
  {
    renderer->GetActiveCamera()->Azimuth(80.0 / numRenders);
    renderer->GetActiveCamera()->Elevation(80.0 / numRenders);
    renderWindow->Render();
  }
  timer->StopTimer();
  double elapsed = timer->GetElapsedTime();
  cerr << "interactive render time: " << elapsed / numRenders << endl;
  unsigned int numTris = reader->GetOutput()->GetPolys()->GetNumberOfCells();
  cerr << "number of triangles: " << numTris << endl;
  cerr << "triangles per second: " << numTris * (numRenders / elapsed) << endl;

  renderer->GetActiveCamera()->SetPosition(-0.2, 0.2, 1);
  renderer->GetActiveCamera()->SetFocalPoint(0, 0, 0);
  renderer->GetActiveCamera()->SetViewUp(0, 1, 0);
  renderer->GetActiveCamera()->OrthogonalizeViewUp();
  renderer->ResetCamera();
  renderWindow->Render();

  int retVal = vtkRegressionTestImage(renderWindow);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }

  return !retVal;
}
