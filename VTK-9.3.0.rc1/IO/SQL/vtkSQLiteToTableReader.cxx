// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDoubleArray.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkIntArray.h"
#include "vtkObjectFactory.h"
#include "vtkSQLiteDatabase.h"
#include "vtkSQLiteQuery.h"
#include "vtkSmartPointer.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkStringArray.h"
#include "vtkTable.h"

#include "vtkSQLiteToTableReader.h"

//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkSQLiteToTableReader);

//------------------------------------------------------------------------------
vtkSQLiteToTableReader::vtkSQLiteToTableReader() = default;

//------------------------------------------------------------------------------
vtkSQLiteToTableReader::~vtkSQLiteToTableReader() = default;

//------------------------------------------------------------------------------
int vtkSQLiteToTableReader::RequestData(
  vtkInformation*, vtkInformationVector**, vtkInformationVector* outputVector)
{
  // Make sure we have all the information we need to provide a vtkTable
  if (!this->Database)
  {
    vtkErrorMacro(<< "No open database connection");
    return 1;
  }
  if (!this->Database->IsA("vtkSQLiteDatabase"))
  {
    vtkErrorMacro(<< "Wrong type of database for this reader");
    return 1;
  }
  if (this->TableName.empty())
  {
    vtkErrorMacro(<< "No table selected");
    return 1;
  }

  vtkInformation* outInfo = outputVector->GetInformationObject(0);

  // Return all data in the first piece ...
  if (outInfo->Get(vtkStreamingDemandDrivenPipeline::UPDATE_PIECE_NUMBER()) > 0)
  {
    return 1;
  }

  vtkTable* const output = vtkTable::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()));

  // perform a query to get the names and types of the columns
  std::string queryStr = "pragma table_info(";
  queryStr += this->TableName;
  queryStr += ")";
  vtkSQLiteQuery* query = static_cast<vtkSQLiteQuery*>(this->Database->GetQueryInstance());
  query->SetQuery(queryStr.c_str());
  if (!query->Execute())
  {
    vtkErrorMacro(<< "Error performing 'pragma' query");
  }

  // use the results of the query to create columns of the proper name & type
  std::vector<std::string> columnTypes;
  while (query->NextRow())
  {
    std::string columnName = query->DataValue(1).ToString();
    std::string columnType = query->DataValue(2).ToString();
    columnTypes.push_back(columnType);
    if (columnType == "INTEGER")
    {
      vtkSmartPointer<vtkIntArray> column = vtkSmartPointer<vtkIntArray>::New();
      column->SetName(columnName.c_str());
      output->AddColumn(column);
    }
    else if (columnType == "REAL")
    {
      vtkSmartPointer<vtkDoubleArray> column = vtkSmartPointer<vtkDoubleArray>::New();
      column->SetName(columnName.c_str());
      output->AddColumn(column);
    }
    else
    {
      vtkSmartPointer<vtkStringArray> column = vtkSmartPointer<vtkStringArray>::New();
      column->SetName(columnName.c_str());
      output->AddColumn(column);
    }
  }

  // do a query to get the contents of the SQLite table
  queryStr = "SELECT * FROM ";
  queryStr += this->TableName;
  query->SetQuery(queryStr.c_str());
  if (!query->Execute())
  {
    vtkErrorMacro(<< "Error performing 'select all' query");
  }

  // use the results of the query to populate the columns
  while (query->NextRow())
  {
    for (int col = 0; col < query->GetNumberOfFields(); ++col)
    {
      if (columnTypes[col] == "INTEGER")
      {
        vtkIntArray* column = static_cast<vtkIntArray*>(output->GetColumn(col));
        column->InsertNextValue(query->DataValue(col).ToInt());
      }
      else if (columnTypes[col] == "REAL")
      {
        vtkDoubleArray* column = static_cast<vtkDoubleArray*>(output->GetColumn(col));
        column->InsertNextValue(query->DataValue(col).ToDouble());
      }
      else
      {
        vtkStringArray* column = static_cast<vtkStringArray*>(output->GetColumn(col));
        column->InsertNextValue(query->DataValue(col).ToString());
      }
    }
  }

  query->Delete();
  return 1;
}

//------------------------------------------------------------------------------
void vtkSQLiteToTableReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
