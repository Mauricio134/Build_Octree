// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// Test converting from a vtkGhostLevels to vtkGhostType
// see http://www.kitware.com/blog/home/post/856
// Ghost and Blanking (Visibility) Changes

#include "vtkActor.h"
#include "vtkCellData.h"
#include "vtkCellType.h"
#include "vtkDataSetSurfaceFilter.h"
#include "vtkGeometryFilter.h"
#include "vtkNew.h"
#include "vtkPoints.h"
#include "vtkPolyDataMapper.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkTesting.h"
#include "vtkUnsignedCharArray.h"
#include "vtkUnstructuredGrid.h"
#include "vtkXMLUnstructuredGridReader.h"
#include "vtkXMLUnstructuredGridWriter.h"

// ghost_cells.vtu was created using this function
vtkSmartPointer<vtkUnstructuredGrid> CreateThreeTetra()
{
  vtkNew<vtkPoints> points;
  points->InsertPoint(0, 0, 0, 0);
  points->InsertPoint(1, 1, 0, 0);
  points->InsertPoint(2, 0.5, 1, 0);
  points->InsertPoint(3, 0.5, 0.5, 1);
  points->InsertPoint(4, 0.5, -1, 0);
  points->InsertPoint(5, 0.5, -0.5, 1);

  vtkIdType v[3][4] = { { 0, 1, 2, 3 }, { 0, 4, 1, 5 }, { 5, 3, 1, 0 } };

  vtkSmartPointer<vtkUnstructuredGrid> grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  grid->InsertNextCell(VTK_TETRA, 4, v[0]);
  grid->InsertNextCell(VTK_TETRA, 4, v[1]);
  grid->InsertNextCell(VTK_TETRA, 4, v[2]);
  grid->SetPoints(points);

  vtkNew<vtkUnsignedCharArray> ghosts;
  ghosts->InsertNextValue(0);
  ghosts->InsertNextValue(1);
  ghosts->InsertNextValue(2);
  ghosts->SetName("vtkGhostLevels");
  grid->GetCellData()->AddArray(ghosts);

  return grid;
}

void WriteThreeTetra()
{
  vtkSmartPointer<vtkUnstructuredGrid> grid = CreateThreeTetra();

  vtkNew<vtkXMLUnstructuredGridWriter> writer;
  writer->SetInputData(grid);
  writer->SetFileName("ghost_cells.vtu");
  writer->Write();
}

int TestXMLGhostCellsImport(int argc, char* argv[])
{
  vtkNew<vtkTesting> testing;
  testing->AddArguments(argc, argv);

  // this was used to generate ghost_cells.vtu
  // WriteThreeTetra();

  std::string filename = testing->GetDataRoot();
  filename += "/Data/ghost_cells.vtu";

  vtkNew<vtkXMLUnstructuredGridReader> reader;
  reader->SetFileName(filename.c_str());

  // this filter removes the ghost cells
  vtkNew<vtkGeometryFilter> surfaces;
  surfaces->SetInputConnection(reader->GetOutputPort());

  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(surfaces->GetOutputPort());

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);

  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(actor);

  vtkNew<vtkRenderWindow> renwin;
  renwin->AddRenderer(renderer);
  renwin->SetSize(300, 300);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renwin);
  iren->Initialize();

  renwin->Render();

  int retVal = vtkRegressionTestImage(renwin);

  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }

  return !retVal;
}
