// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME vtkBridgePointIteratorOnCell - Implementation of vtkGenericPointIterator.
// .SECTION Description
// It is just an example that show how to implement the Generic. It is also
// used for testing and evaluating the Generic.
// .SECTION See Also
// vtkGenericPointIterator, vtkBridgeDataSet

#include "vtkBridgePointIteratorOnCell.h"

#include <cassert>

#include "vtkBridgeCell.h"
#include "vtkBridgeDataSet.h"
#include "vtkCell.h"
#include "vtkDataSet.h"
#include "vtkIdList.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkBridgePointIteratorOnCell);

//------------------------------------------------------------------------------
// Description:
// Default constructor.
vtkBridgePointIteratorOnCell::vtkBridgePointIteratorOnCell()
{
  this->DataSet = nullptr;
  this->Cursor = 0;
  this->PtIds = nullptr;
}

//------------------------------------------------------------------------------
// Description:
// Destructor.
vtkBridgePointIteratorOnCell::~vtkBridgePointIteratorOnCell()
{
  vtkSetObjectBodyMacro(DataSet, vtkBridgeDataSet, static_cast<vtkBridgeDataSet*>(nullptr));
}

//------------------------------------------------------------------------------
void vtkBridgePointIteratorOnCell::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//------------------------------------------------------------------------------
// Description:
// Move iterator to first position if any (loop initialization).
void vtkBridgePointIteratorOnCell::Begin()
{
  if (this->PtIds != nullptr)
  {
    this->Cursor = 0;
  }
}

//------------------------------------------------------------------------------
// Description:
// Is there no point at iterator position? (exit condition).
vtkTypeBool vtkBridgePointIteratorOnCell::IsAtEnd()
{
  return (this->PtIds == nullptr) || (this->Cursor >= this->PtIds->GetNumberOfIds());
}

//------------------------------------------------------------------------------
// Description:
// Move iterator to next position. (loop progression).
// \pre not_off: !IsAtEnd()
void vtkBridgePointIteratorOnCell::Next()
{
  assert("pre: not_off" && !IsAtEnd());
  this->Cursor++;
}

//------------------------------------------------------------------------------
// Description:
// Point at iterator position.
// \pre not_off: !IsAtEnd()
// \post result_exists: result!=0
double* vtkBridgePointIteratorOnCell::GetPosition()
{
  assert("pre: not_off" && !IsAtEnd());

  double* result = this->DataSet->Implementation->GetPoint(this->PtIds->GetId(this->Cursor));

  assert("post: result_exists" && result != nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Description:
// Point at iterator position.
// \pre not_off: !IsAtEnd()
// \pre x_exists: x!=0
void vtkBridgePointIteratorOnCell::GetPosition(double x[3])
{
  assert("pre: not_off" && !IsAtEnd());
  assert("pre: x_exists" && x != nullptr);
  this->DataSet->Implementation->GetPoint(this->PtIds->GetId(this->Cursor), x);
}

//------------------------------------------------------------------------------
// Description:
// Unique identifier for the point, could be non-contiguous
// \pre not_off: !IsAtEnd()
vtkIdType vtkBridgePointIteratorOnCell::GetId()
{
  assert("pre: not_off" && !IsAtEnd());

  return this->PtIds->GetId(this->Cursor);
}

//------------------------------------------------------------------------------
// Description:
// The iterator will iterate over the point of a cell
// \pre cell_exists: cell!=0
void vtkBridgePointIteratorOnCell::InitWithCell(vtkBridgeCell* cell)
{
  assert("pre: cell_exists" && cell != nullptr);

  vtkSetObjectBodyMacro(DataSet, vtkBridgeDataSet, cell->DataSet);
  this->PtIds = cell->Cell->GetPointIds();
}
VTK_ABI_NAMESPACE_END
