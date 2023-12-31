// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkPResampleWithDataSet.h"

#include "vtkActor.h"
#include "vtkCompositeDataGeometryFilter.h"
#include "vtkCompositePolyDataMapper.h"
#include "vtkCompositeRenderManager.h"
#include "vtkCylinder.h"
#include "vtkExtentTranslator.h"
#include "vtkMPIController.h"
#include "vtkMultiBlockDataSet.h"
#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkRTAnalyticSource.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSphere.h"
#include "vtkTableBasedClipDataSet.h"
#include "vtkTransform.h"
#include "vtkTransformFilter.h"

namespace
{

void CreateInputDataSet(
  vtkMultiBlockDataSet* dataset, int rank, int numberOfProcs, int blocksPerProc)
{
  int numPieces = blocksPerProc * numberOfProcs;
  dataset->SetNumberOfBlocks(numPieces);

  vtkNew<vtkExtentTranslator> extentTranslator;
  extentTranslator->SetWholeExtent(-16, 16, -16, 16, -16, 16);
  extentTranslator->SetNumberOfPieces(numPieces);
  extentTranslator->SetSplitModeToBlock();

  vtkNew<vtkRTAnalyticSource> wavelet;
  wavelet->SetWholeExtent(-16, 16, -16, 16, -16, 16);
  wavelet->SetCenter(0, 0, 0);

  vtkNew<vtkCylinder> cylinder;
  cylinder->SetCenter(0, 0, 0);
  cylinder->SetRadius(15);
  cylinder->SetAxis(0, 1, 0);
  vtkNew<vtkTableBasedClipDataSet> clipCyl;
  clipCyl->SetClipFunction(cylinder);
  clipCyl->InsideOutOn();

  vtkNew<vtkSphere> sphere;
  sphere->SetCenter(0, 0, 4);
  sphere->SetRadius(12);
  vtkNew<vtkTableBasedClipDataSet> clipSphr;
  clipSphr->SetInputConnection(clipCyl->GetOutputPort());
  clipSphr->SetClipFunction(sphere);

  vtkNew<vtkTransform> transform;
  transform->RotateZ(45);
  vtkNew<vtkTransformFilter> transFilter;
  transFilter->SetInputConnection(clipSphr->GetOutputPort());
  transFilter->SetTransform(transform);

  for (int i = 0; i < blocksPerProc; ++i)
  {
    int piece = (rank * blocksPerProc) + i;

    int blockExtent[6];
    extentTranslator->SetPiece(piece);
    extentTranslator->PieceToExtent();
    extentTranslator->GetExtent(blockExtent);

    wavelet->UpdateExtent(blockExtent);
    clipCyl->SetInputData(wavelet->GetOutputDataObject(0));
    transFilter->Update();

    vtkDataObject* block = transFilter->GetOutputDataObject(0)->NewInstance();
    block->DeepCopy(transFilter->GetOutputDataObject(0));
    dataset->SetBlock(piece, block);
    block->Delete();
  }
}

void CreateSourceDataSet(
  vtkMultiBlockDataSet* dataset, int rank, int numberOfProcs, int blocksPerProc)
{
  int numPieces = blocksPerProc * numberOfProcs;
  dataset->SetNumberOfBlocks(numPieces);

  vtkNew<vtkExtentTranslator> extentTranslator;
  extentTranslator->SetWholeExtent(-22, 22, -22, 22, -16, 16);
  extentTranslator->SetNumberOfPieces(numPieces);
  extentTranslator->SetSplitModeToBlock();

  vtkNew<vtkRTAnalyticSource> wavelet;
  wavelet->SetWholeExtent(-22, 22, -22, 22, -16, 16);
  wavelet->SetCenter(0, 0, 0);

  for (int i = 0; i < blocksPerProc; ++i)
  {
    int piece = (rank * blocksPerProc) + i;

    int blockExtent[6];
    extentTranslator->SetPiece(piece);
    extentTranslator->PieceToExtent();
    extentTranslator->GetExtent(blockExtent);

    wavelet->UpdateExtent(blockExtent);

    vtkDataObject* block = wavelet->GetOutputDataObject(0)->NewInstance();
    block->DeepCopy(wavelet->GetOutputDataObject(0));
    dataset->SetBlock(piece, block);
    block->Delete();
  }
}

} // anonymous namespace

int TestPResampleWithDataSet(int argc, char* argv[])
{
  vtkNew<vtkMPIController> controller;
  controller->Initialize(&argc, &argv);

  int numProcs = controller->GetNumberOfProcesses();
  int rank = controller->GetLocalProcessId();

  // create input dataset
  vtkNew<vtkMultiBlockDataSet> input;
  CreateInputDataSet(input, rank, numProcs, 3);

  vtkNew<vtkMultiBlockDataSet> source;
  CreateSourceDataSet(source, rank, numProcs, 5);

  vtkNew<vtkPResampleWithDataSet> resample;
  resample->SetController(controller);
  resample->SetInputData(input);
  resample->SetSourceData(source);
  resample->Update();

  // Render
  vtkNew<vtkCompositeDataGeometryFilter> toPoly;
  toPoly->SetInputConnection(resample->GetOutputPort());

  double range[2];
  toPoly->Update();
  toPoly->GetOutput()->GetPointData()->GetArray("RTData")->GetRange(range);

  vtkNew<vtkCompositePolyDataMapper> mapper;
  mapper->SetInputConnection(toPoly->GetOutputPort());
  mapper->SetScalarRange(range);

  // Setup parallel rendering
  vtkNew<vtkCompositeRenderManager> prm;
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::Take(prm->MakeRenderer());
  vtkSmartPointer<vtkRenderWindow> renWin =
    vtkSmartPointer<vtkRenderWindow>::Take(prm->MakeRenderWindow());
  renWin->AddRenderer(renderer);
  renWin->DoubleBufferOn();
  renWin->SetMultiSamples(0);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renWin);

  prm->SetRenderWindow(renWin);
  prm->SetController(controller);

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);
  renderer->AddActor(actor);

  int r1 = vtkTesting::PASSED;
  if (rank == 0)
  {
    prm->ResetAllCameras();

    std::cout << "Test with RegularPartition" << std::endl;
    renWin->Render();
    r1 = vtkRegressionTester::Test(argc, argv, renWin, 10);
    if (!r1)
    {
      std::cout << "Test with RegularPartition failed" << std::endl;
    }
    else if (r1 == vtkRegressionTester::DO_INTERACTOR)
    {
      iren->Start();
    }
    prm->StopServices();
  }
  else
  {
    prm->StartServices();
  }
  controller->Barrier();

  resample->UseBalancedPartitionForPointsLookupOn();
  int r2 = vtkTesting::PASSED;
  if (rank == 0)
  {
    prm->ResetAllCameras();

    std::cout << "Test with BalancedPartition" << std::endl;
    renWin->Render();
    r2 = vtkRegressionTester::Test(argc, argv, renWin, 10);
    if (!r2)
    {
      std::cout << "Test with BalancedPartition failed" << std::endl;
    }
    else if (r2 == vtkRegressionTester::DO_INTERACTOR)
    {
      iren->Start();
    }
    prm->StopServices();
  }
  else
  {
    prm->StartServices();
  }
  controller->Barrier();

  int status = r1 && r2;
  controller->Broadcast(&status, 1, 0);
  controller->Finalize();

  return !status;
}
