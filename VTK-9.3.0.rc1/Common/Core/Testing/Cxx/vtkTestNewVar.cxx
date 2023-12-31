// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkTestNewVar.h"
#include "vtkPoints2D.h"

#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkTestNewVar);

vtkTestNewVar::vtkTestNewVar() = default;

vtkTestNewVar::~vtkTestNewVar() = default;

vtkIdType vtkTestNewVar::GetPointsRefCount()
{
  // Note - this is valid until class destruction and then Delete() will be
  // called on the Data object, decrementing its reference count.
  return this->Points->GetReferenceCount();
}

vtkObject* vtkTestNewVar::GetPoints()
{
  return this->Points.GetPointer();
}

vtkObject* vtkTestNewVar::GetPoints2()
{
  return this->Points;
}

void vtkTestNewVar::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "Points: " << endl;
  this->Points->PrintSelf(os, indent.GetNextIndent());
}
