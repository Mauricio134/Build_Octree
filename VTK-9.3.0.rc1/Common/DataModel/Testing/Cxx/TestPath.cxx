// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkIntArray.h"
#include "vtkNew.h"
#include "vtkPath.h"
#include "vtkPoints.h"

int TestPath(int, char*[])
{
  vtkNew<vtkPath> path;

  path->Allocate(7);

  path->InsertNextPoint(0.0, 0.0, 0.0, vtkPath::MOVE_TO);
  path->InsertNextPoint(1.0, 0.0, 0.0, vtkPath::LINE_TO);
  path->InsertNextPoint(1.5, 2.0, 0.0, vtkPath::CONIC_CURVE);
  path->InsertNextPoint(1.0, 1.5, 0.0, vtkPath::CONIC_CURVE);
  path->InsertNextPoint(0.0, 3.0, 0.0, vtkPath::CUBIC_CURVE);
  path->InsertNextPoint(0.0, 1.0, 0.0, vtkPath::CUBIC_CURVE);
  path->InsertNextPoint(path->GetPoint(0), vtkPath::CUBIC_CURVE);

  if (path->GetCodes()->GetNumberOfTuples() != 7 || path->GetPoints()->GetNumberOfPoints() != 7)
  {
    return EXIT_FAILURE;
  }

  path->Reset();

  if (path->GetCodes()->GetNumberOfTuples() != 0 || path->GetPoints()->GetNumberOfPoints() != 0)
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
