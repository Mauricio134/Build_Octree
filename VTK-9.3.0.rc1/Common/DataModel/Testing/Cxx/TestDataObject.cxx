// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <cassert>

#include <vtkDataObject.h>

int TestGetAssociationTypeFromString()
{
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_POINTS") ==
    vtkDataObject::FIELD_ASSOCIATION_POINTS);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_CELLS") ==
    vtkDataObject::FIELD_ASSOCIATION_CELLS);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_NONE") ==
    vtkDataObject::FIELD_ASSOCIATION_NONE);
  assert(vtkDataObject::GetAssociationTypeFromString(
           "vtkDataObject::FIELD_ASSOCIATION_POINTS_THEN_CELLS") ==
    vtkDataObject::FIELD_ASSOCIATION_POINTS_THEN_CELLS);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_VERTICES") ==
    vtkDataObject::FIELD_ASSOCIATION_VERTICES);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_EDGES") ==
    vtkDataObject::FIELD_ASSOCIATION_EDGES);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD_ASSOCIATION_ROWS") ==
    vtkDataObject::FIELD_ASSOCIATION_ROWS);

  assert(
    vtkDataObject::GetAssociationTypeFromString("vtkDataObject::POINT") == vtkDataObject::POINT);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::CELL") == vtkDataObject::CELL);
  assert(
    vtkDataObject::GetAssociationTypeFromString("vtkDataObject::FIELD") == vtkDataObject::FIELD);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::POINT_THEN_CELL") ==
    vtkDataObject::POINT_THEN_CELL);
  assert(
    vtkDataObject::GetAssociationTypeFromString("vtkDataObject::VERTEX") == vtkDataObject::VERTEX);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::EDGE") == vtkDataObject::EDGE);
  assert(vtkDataObject::GetAssociationTypeFromString("vtkDataObject::ROW") == vtkDataObject::ROW);

  assert(vtkDataObject::GetAssociationTypeFromString(nullptr) == -1);
  assert(vtkDataObject::GetAssociationTypeFromString("") == -1);
  assert(vtkDataObject::GetAssociationTypeFromString("INVALID") == -1);

  return 0;
}

int TestDataObject(int, char*[])
{
  return TestGetAssociationTypeFromString();
}
