// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// This test verifies that time varying data works as expected in ospray
//
// The command line arguments are:
// -I        => run in interactive mode; unless this is used, the program will
//              not allow interaction and exit

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkDataSetSurfaceFilter.h"
#include "vtkInformation.h"
#include "vtkOSPRayPass.h"
#include "vtkOSPRayRendererNode.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkTimeSourceExample.h"

int TestOSPRayTime(int argc, char* argv[])
{
  vtkSmartPointer<vtkRenderWindowInteractor> iren =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
  iren->SetRenderWindow(renWin);
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  renWin->AddRenderer(renderer);
  renderer->SetBackground(0.0, 0.0, 0.0);
  renWin->SetSize(400, 400);
  renWin->Render();

  vtkSmartPointer<vtkOSPRayPass> ospray = vtkSmartPointer<vtkOSPRayPass>::New();
  renderer->SetPass(ospray);

  for (int i = 0; i < argc; ++i)
  {
    if (!strcmp(argv[i], "--OptiX"))
    {
      vtkOSPRayRendererNode::SetRendererType("optix pathtracer", renderer);
      break;
    }
  }

  vtkSmartPointer<vtkTimeSourceExample> timeywimey = vtkSmartPointer<vtkTimeSourceExample>::New();
  timeywimey->GrowingOn();
  vtkSmartPointer<vtkDataSetSurfaceFilter> dsf = vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
  dsf->SetInputConnection(timeywimey->GetOutputPort());

  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(dsf->GetOutputPort());
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  renderer->AddActor(actor);
  actor->SetMapper(mapper);

  renWin->Render();
  renderer->ResetCamera();
  double pos[3];
  vtkCamera* camera = renderer->GetActiveCamera();
  camera->SetFocalPoint(0.0, 2.5, 0.0);
  camera->GetPosition(pos);
  pos[0] = pos[0] + 6;
  pos[1] = pos[1] + 6;
  pos[2] = pos[2] + 6;
  camera->SetPosition(pos);
  renderer->ResetCameraClippingRange();
  renWin->Render();

  for (int i = 0; i < 20; i++)
  {
    double updateTime = (double)(i % 10) / 10.0;
    cerr << "t=" << updateTime << endl;
    renderer->SetActiveCamera(camera);
    vtkInformation* outInfo = dsf->GetExecutive()->GetOutputInformation(0);
    outInfo->Set(vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEP(), updateTime);
    renderer->ResetCameraClippingRange();
    renWin->Render();
  }
  iren->Start();

  return 0;
}
