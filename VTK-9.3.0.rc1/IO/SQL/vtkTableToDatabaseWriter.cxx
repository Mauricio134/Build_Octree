// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDoubleArray.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkIntArray.h"
#include "vtkObjectFactory.h"
#include "vtkSQLDatabase.h"
#include "vtkSQLQuery.h"
#include "vtkSmartPointer.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkStringArray.h"
#include "vtkTable.h"
#include "vtkVariant.h"
#include "vtkVariantArray.h"

#include "vtkTableToDatabaseWriter.h"

//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_BEGIN
vtkTableToDatabaseWriter::vtkTableToDatabaseWriter()
{
  this->Database = nullptr;
}

//------------------------------------------------------------------------------
vtkTableToDatabaseWriter::~vtkTableToDatabaseWriter() = default;

//------------------------------------------------------------------------------
bool vtkTableToDatabaseWriter::SetDatabase(vtkSQLDatabase* db)
{
  if (!db)
  {
    return false;
  }
  this->Database = db;
  if (!this->Database->IsOpen())
  {
    vtkErrorMacro(<< "SetDatabase must be passed an open database connection");
    this->Database = nullptr;
    return false;
  }

  if (!this->TableName.empty())
  {
    return this->TableNameIsNew();
  }
  return true;
}

//------------------------------------------------------------------------------
bool vtkTableToDatabaseWriter::SetTableName(const char* name)
{
  std::string nameStr = name;
  this->TableName = nameStr;
  if (this->Database != nullptr)
  {
    return this->TableNameIsNew();
  }
  return true;
}

//------------------------------------------------------------------------------
bool vtkTableToDatabaseWriter::TableNameIsNew()
{
  if (this->Database == nullptr)
  {
    vtkErrorMacro(<< "TableNameIsNew() called with no open database!");
    return false;
  }

  if (this->TableName.empty())
  {
    vtkErrorMacro(<< "TableNameIsNew() called but no table name specified.");
    return false;
  }

  vtkStringArray* tableNames = this->Database->GetTables();
  if (tableNames->LookupValue(this->TableName) == -1)
  {
    return true;
  }

  vtkErrorMacro(<< "Table " << this->TableName << " already exists in the database.  "
                << "Please choose another name.");
  this->TableName = "";
  return false;
}

int vtkTableToDatabaseWriter::FillInputPortInformation(int, vtkInformation* info)
{
  info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkTable");
  return 1;
}

vtkTable* vtkTableToDatabaseWriter::GetInput()
{
  return vtkTable::SafeDownCast(this->Superclass::GetInput());
}

vtkTable* vtkTableToDatabaseWriter::GetInput(int port)
{
  return vtkTable::SafeDownCast(this->Superclass::GetInput(port));
}

//------------------------------------------------------------------------------
void vtkTableToDatabaseWriter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
