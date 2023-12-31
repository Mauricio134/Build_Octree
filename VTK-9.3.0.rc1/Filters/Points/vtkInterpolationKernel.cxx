// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkInterpolationKernel.h"
#include "vtkAbstractPointLocator.h"
#include "vtkDataSet.h"
#include "vtkPointData.h"

//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_BEGIN
vtkInterpolationKernel::vtkInterpolationKernel()
{
  this->RequiresInitialization = true;

  this->Locator = nullptr;
  this->DataSet = nullptr;
  this->PointData = nullptr;
}

//------------------------------------------------------------------------------
vtkInterpolationKernel::~vtkInterpolationKernel()
{
  this->FreeStructures();
}

//------------------------------------------------------------------------------
void vtkInterpolationKernel::FreeStructures()
{
  if (this->Locator)
  {
    this->Locator->Delete();
    this->Locator = nullptr;
  }

  if (this->DataSet)
  {
    this->DataSet->Delete();
    this->DataSet = nullptr;
  }

  if (this->PointData)
  {
    this->PointData->Delete();
    this->PointData = nullptr;
  }
}

//------------------------------------------------------------------------------
void vtkInterpolationKernel::Initialize(
  vtkAbstractPointLocator* loc, vtkDataSet* ds, vtkPointData* attr)
{
  this->FreeStructures();

  if (loc)
  {
    this->Locator = loc;
    this->Locator->Register(this);
  }

  if (ds)
  {
    this->DataSet = ds;
    this->DataSet->Register(this);
  }

  if (attr)
  {
    this->PointData = attr;
    this->PointData->Register(this);
  }
}

//------------------------------------------------------------------------------
void vtkInterpolationKernel::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent
     << "Requires Initialization: " << (this->GetRequiresInitialization() ? "On\n" : "Off\n");

  if (this->Locator)
  {
    os << indent << "Locator:\n";
    this->Locator->PrintSelf(os, indent.GetNextIndent());
  }
  else
  {
    os << indent << "Locator: (None)\n";
  }

  if (this->DataSet)
  {
    os << indent << "DataSet:\n";
    this->DataSet->PrintSelf(os, indent.GetNextIndent());
  }
  else
  {
    os << indent << "DataSet: (None)\n";
  }

  if (this->PointData)
  {
    os << indent << "PointData:\n";
    this->PointData->PrintSelf(os, indent.GetNextIndent());
  }
  else
  {
    os << indent << "PointData: (None)\n";
  }
}
VTK_ABI_NAMESPACE_END
