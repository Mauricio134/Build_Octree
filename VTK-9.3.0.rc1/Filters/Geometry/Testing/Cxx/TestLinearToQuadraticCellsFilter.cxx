// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkCellIterator.h>
#include <vtkClipDataSet.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkDoubleArray.h>
#include <vtkGenericCell.h>
#include <vtkLinearToQuadraticCellsFilter.h>
#include <vtkPointData.h>
#include <vtkPointLocator.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRegressionTestImage.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTestUtilities.h>
#include <vtkTetra.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVersion.h>

namespace
{
void AddTetra(const double* p0, const double* p1, const double* p2, const double* p3,
  vtkPointLocator* pointLocator, vtkCellArray* cells)
{
  vtkSmartPointer<vtkTetra> t = vtkSmartPointer<vtkTetra>::New();
  static vtkIdType bIndices[4][4] = { { 0, 0, 0, 1 }, { 1, 0, 0, 0 }, { 0, 1, 0, 0 },
    { 0, 0, 1, 0 } };
  vtkIdType order = 1;
  vtkIdType nPoints = 4;
  t->GetPointIds()->SetNumberOfIds(nPoints);
  t->GetPoints()->SetNumberOfPoints(nPoints);
  t->Initialize();
  double p[3];
  vtkIdType pId;
  vtkIdType* bIndex;
  for (vtkIdType i = 0; i < nPoints; i++)
  {
    bIndex = bIndices[i];
    for (vtkIdType j = 0; j < 3; j++)
    {
      p[j] = (p0[j] * bIndex[3]) / order + (p1[j] * bIndex[0]) / order +
        (p2[j] * bIndex[1]) / order + (p3[j] * bIndex[2]) / order;
    }
    pointLocator->InsertUniquePoint(p, pId);
    t->GetPointIds()->SetId(i, pId);
  }
  cells->InsertNextCell(t);
}
}

int TestLinearToQuadraticCellsFilter(int argc, char* argv[])
{
  // This test constructs a meshed cube comprised of linear tetrahedra and
  // degree elevates the cells to quadratic tetrahedra. The resulting wireframe
  // image depicts the subsequent linearization of these cells, so it should
  // look like a <2*nX> x <2*nY> x <2*nZ> tetrahedralized cube.

  vtkIdType nX = 2;
  vtkIdType nY = 2;
  vtkIdType nZ = 2;

  vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid =
    vtkSmartPointer<vtkUnstructuredGrid>::New();

  vtkSmartPointer<vtkPoints> pointArray = vtkSmartPointer<vtkPoints>::New();

  vtkSmartPointer<vtkPointLocator> pointLocator = vtkSmartPointer<vtkPointLocator>::New();
  double bounds[6] = { -1., 1., -1., 1., -1., 1. };
  pointLocator->InitPointInsertion(pointArray, bounds);

  vtkSmartPointer<vtkCellArray> cellArray = vtkSmartPointer<vtkCellArray>::New();

  double p[8][3];
  double dx = (bounds[1] - bounds[0]) / nX;
  double dy = (bounds[3] - bounds[2]) / nY;
  double dz = (bounds[5] - bounds[4]) / nZ;
  for (vtkIdType i = 0; i < 8; i++)
  {
    for (vtkIdType j = 0; j < 3; j++)
    {
      p[i][j] = bounds[2 * j];
    }
  }
  p[1][0] += dx;
  p[2][0] += dx;
  p[2][1] += dy;
  p[3][1] += dy;
  p[5][0] += dx;
  p[5][2] += dz;
  p[6][0] += dx;
  p[6][1] += dy;
  p[6][2] += dz;
  p[7][1] += dy;
  p[7][2] += dz;

  for (vtkIdType xInc = 0; xInc < nX; xInc++)
  {
    p[0][1] = p[1][1] = p[4][1] = p[5][1] = bounds[2];
    p[2][1] = p[3][1] = p[6][1] = p[7][1] = bounds[2] + dy;

    for (vtkIdType yInc = 0; yInc < nY; yInc++)
    {
      p[0][2] = p[1][2] = p[2][2] = p[3][2] = bounds[4];
      p[4][2] = p[5][2] = p[6][2] = p[7][2] = bounds[4] + dz;

      for (vtkIdType zInc = 0; zInc < nZ; zInc++)
      {
        AddTetra(p[0], p[1], p[2], p[5], pointLocator, cellArray);
        AddTetra(p[0], p[2], p[3], p[7], pointLocator, cellArray);
        AddTetra(p[0], p[5], p[7], p[4], pointLocator, cellArray);
        AddTetra(p[2], p[5], p[6], p[7], pointLocator, cellArray);
        AddTetra(p[0], p[2], p[5], p[7], pointLocator, cellArray);

        for (vtkIdType i = 0; i < 8; i++)
        {
          p[i][2] += dz;
        }
      }

      for (vtkIdType i = 0; i < 8; i++)
      {
        p[i][1] += dy;
      }
    }

    for (vtkIdType i = 0; i < 8; i++)
    {
      p[i][0] += dx;
    }
  }

  unstructuredGrid->SetPoints(pointArray);
  unstructuredGrid->SetCells(VTK_TETRA, cellArray);

  vtkIdType nPoints = unstructuredGrid->GetPoints()->GetNumberOfPoints();

  vtkSmartPointer<vtkDoubleArray> radiant = vtkSmartPointer<vtkDoubleArray>::New();
  radiant->SetName("Distance from Origin");
  radiant->SetNumberOfTuples(nPoints);

  vtkSmartPointer<vtkDoubleArray> elevation = vtkSmartPointer<vtkDoubleArray>::New();
  elevation->SetName("Elevation");
  elevation->SetNumberOfTuples(nPoints);

  double maxDist = 0;
  for (vtkIdType i = 0; i < nPoints; i++)
  {
    double xyz[3];
    unstructuredGrid->GetPoints()->GetPoint(i, xyz);
    double dist = sqrt(xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2]);
    maxDist = (dist > maxDist ? dist : maxDist);
    radiant->SetTypedTuple(i, &dist);
    elevation->SetTypedTuple(i, &xyz[2]);
  }

  unstructuredGrid->GetPointData()->AddArray(radiant);
  unstructuredGrid->GetPointData()->AddArray(elevation);
  unstructuredGrid->GetPointData()->SetScalars(radiant);

  vtkSmartPointer<vtkLinearToQuadraticCellsFilter> degreeElevate =
    vtkSmartPointer<vtkLinearToQuadraticCellsFilter>::New();
  degreeElevate->SetInputData(unstructuredGrid);

  // Visualize
  vtkSmartPointer<vtkDataSetSurfaceFilter> surfaceFilter =
    vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
  surfaceFilter->SetInputConnection(degreeElevate->GetOutputPort());

  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(surfaceFilter->GetOutputPort());
  mapper->SetScalarRange(maxDist * .5, maxDist);

  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->SetRepresentationToWireframe();
  actor->GetProperty()->SetLineWidth(4);

  vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
  camera->SetPosition(3. * maxDist, 3. * maxDist, -3. * maxDist);
  camera->SetFocalPoint(.0, .0, 0.);

  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->SetActiveCamera(camera);

  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(actor);

  renderWindow->Render();

  int retVal = vtkRegressionTestImage(renderWindow);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    renderWindowInteractor->Start();
  }

  return !retVal;
}
