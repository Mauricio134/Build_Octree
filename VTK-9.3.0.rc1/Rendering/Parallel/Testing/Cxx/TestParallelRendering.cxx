// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtk_mpi.h>

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCompositedSynchronizedRenderers.h"
#include "vtkLookupTable.h"
#include "vtkMPICommunicator.h"
#include "vtkMPIController.h"
#include "vtkObjectFactory.h"
#include "vtkOpenGLRenderWindow.h"
#include "vtkPieceScalars.h"
#include "vtkPolyDataMapper.h"
#include "vtkProcess.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkSynchronizedRenderWindows.h"
#include "vtkTestUtilities.h"

namespace
{

class MyProcess : public vtkProcess
{
public:
  static MyProcess* New();

  void Execute() override;

  void SetArgs(int anArgc, char* anArgv[])
  {
    this->Argc = anArgc;
    this->Argv = anArgv;
  }

  void CreatePipeline(vtkRenderer* renderer)
  {
    int num_procs = this->Controller->GetNumberOfProcesses();
    int my_id = this->Controller->GetLocalProcessId();

    vtkSphereSource* sphere = vtkSphereSource::New();
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);

    vtkPieceScalars* piecescalars = vtkPieceScalars::New();
    piecescalars->SetInputConnection(sphere->GetOutputPort());
    piecescalars->SetScalarModeToCellData();

    vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(piecescalars->GetOutputPort());
    mapper->SetScalarModeToUseCellFieldData();
    mapper->SelectColorArray("Piece");
    mapper->SetScalarRange(0, num_procs - 1);
    mapper->SetPiece(my_id);
    mapper->SetNumberOfPieces(num_procs);
    mapper->Update();

    vtkActor* actor = vtkActor::New();
    actor->SetMapper(mapper);
    renderer->AddActor(actor);

    actor->Delete();
    mapper->Delete();
    piecescalars->Delete();
    sphere->Delete();
  }

protected:
  MyProcess()
  {
    this->Argc = 0;
    this->Argv = nullptr;
  }

  int Argc;
  char** Argv;
};

vtkStandardNewMacro(MyProcess);

void MyProcess::Execute()
{
  this->ReturnValue = 0;
  int my_id = this->Controller->GetLocalProcessId();
  int numProcs = this->Controller->GetNumberOfProcesses();

  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->DoubleBufferOn();
  vtkRenderer* renderer = vtkRenderer::New();

  renWin->AddRenderer(renderer);

  vtkSynchronizedRenderWindows* syncWindows = vtkSynchronizedRenderWindows::New();
  syncWindows->SetRenderWindow(renWin);
  syncWindows->SetParallelController(this->Controller);
  syncWindows->SetIdentifier(1);

  vtkCompositedSynchronizedRenderers* syncRenderers = vtkCompositedSynchronizedRenderers::New();
  syncRenderers->SetRenderer(renderer);
  syncRenderers->SetParallelController(this->Controller);
  // syncRenderers->SetImageReductionFactor(3);

  this->CreatePipeline(renderer);

  int retVal;

  if (my_id == 0)
  {
    vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    iren->Initialize();

    retVal = vtkRegressionTester::Test(this->Argc, this->Argv, renWin, 10);

    if (retVal == vtkRegressionTester::DO_INTERACTOR)
    {
      iren->Start();
    }
    iren->Delete();

    this->Controller->TriggerBreakRMIs();
    // This should really be Broadcast
    for (int i = 1; i < numProcs; i++)
    {
      this->Controller->Send(&retVal, 1, i, 33);
    }
  }
  else
  {
    this->Controller->ProcessRMIs();
    this->Controller->Receive(&retVal, 1, 0, 33);
  }

  renderer->Delete();
  renWin->Delete();
  syncWindows->Delete();
  syncRenderers->Delete();
  this->ReturnValue = retVal;
}

}

int TestParallelRendering(int argc, char* argv[])
{
  // This is here to avoid false leak messages from vtkDebugLeaks when
  // using mpich. It appears that the root process which spawns all the
  // main processes waits in MPI_Init() and calls exit() when
  // the others are done, causing apparent memory leaks for any objects
  // created before MPI_Init().
  MPI_Init(&argc, &argv);

  // Note that this will create a vtkMPIController if MPI
  // is configured, vtkThreadedController otherwise.
  vtkMPIController* contr = vtkMPIController::New();
  contr->Initialize(&argc, &argv, 1);

  int numProcs = contr->GetNumberOfProcesses();

  if (numProcs < 2)
  {
    cout << "This test requires at least 2 processes" << endl;
    contr->Delete();
    return EXIT_FAILURE;
  }

  vtkMultiProcessController::SetGlobalController(contr);

  MyProcess* p = MyProcess::New();
  p->SetArgs(argc, argv);

  contr->SetSingleProcessObject(p);
  contr->SingleMethodExecute();

  int retVal = p->GetReturnValue();

  p->Delete();
  contr->Finalize();
  contr->Delete();
  vtkMultiProcessController::SetGlobalController(nullptr);
  return !retVal;
}
