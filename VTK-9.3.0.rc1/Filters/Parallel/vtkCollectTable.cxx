// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright (c) Sandia Corporation
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkCollectTable.h"

#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMultiProcessController.h"
#include "vtkObjectFactory.h"
#include "vtkSocketController.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkTable.h"
#include "vtkVariant.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkCollectTable);

vtkCxxSetObjectMacro(vtkCollectTable, Controller, vtkMultiProcessController);
vtkCxxSetObjectMacro(vtkCollectTable, SocketController, vtkSocketController);

//------------------------------------------------------------------------------
vtkCollectTable::vtkCollectTable()
{
  this->PassThrough = 0;
  this->SocketController = nullptr;

  // Controller keeps a reference to this object as well.
  this->Controller = nullptr;
  this->SetController(vtkMultiProcessController::GetGlobalController());
}

//------------------------------------------------------------------------------
vtkCollectTable::~vtkCollectTable()
{
  this->SetController(nullptr);
  this->SetSocketController(nullptr);
}

//------------------------------------------------------------------------------
int vtkCollectTable::RequestUpdateExtent(vtkInformation* vtkNotUsed(request),
  vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  // get the info objects
  vtkInformation* inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation* outInfo = outputVector->GetInformationObject(0);

  inInfo->Set(vtkStreamingDemandDrivenPipeline::UPDATE_PIECE_NUMBER(),
    outInfo->Get(vtkStreamingDemandDrivenPipeline::UPDATE_PIECE_NUMBER()));
  inInfo->Set(vtkStreamingDemandDrivenPipeline::UPDATE_NUMBER_OF_PIECES(),
    outInfo->Get(vtkStreamingDemandDrivenPipeline::UPDATE_NUMBER_OF_PIECES()));
  inInfo->Set(vtkStreamingDemandDrivenPipeline::UPDATE_NUMBER_OF_GHOST_LEVELS(),
    outInfo->Get(vtkStreamingDemandDrivenPipeline::UPDATE_NUMBER_OF_GHOST_LEVELS()));

  return 1;
}

//------------------------------------------------------------------------------
int vtkCollectTable::RequestData(vtkInformation* vtkNotUsed(request),
  vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  // get the info objects
  vtkInformation* inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation* outInfo = outputVector->GetInformationObject(0);

  // get the input and output
  vtkTable* input = vtkTable::SafeDownCast(inInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkTable* output = vtkTable::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()));

  int numProcs, myId;
  int idx;

  if (this->Controller == nullptr && this->SocketController == nullptr)
  { // Running as a single process.
    output->ShallowCopy(input);
    return 1;
  }

  if (this->Controller == nullptr && this->SocketController != nullptr)
  { // This is a client.  We assume no data on client for input.
    if (!this->PassThrough)
    {
      vtkTable* table = vtkTable::New();
      this->SocketController->Receive(table, 1, 121767);
      output->ShallowCopy(table);
      table->Delete();
      table = nullptr;
      return 1;
    }
    // If not collected, output will be empty from initialization.
    return 0;
  }

  myId = this->Controller->GetLocalProcessId();
  numProcs = this->Controller->GetNumberOfProcesses();

  if (this->PassThrough)
  {
    // Just copy and return (no collection).
    output->ShallowCopy(input);
    return 1;
  }

  // Collect.
  if (myId == 0)
  {
    vtkTable* wholeTable = vtkTable::New();
    wholeTable->ShallowCopy(input);

    for (idx = 1; idx < numProcs; ++idx)
    {
      vtkTable* curTable = vtkTable::New();
      this->Controller->Receive(curTable, idx, 121767);
      vtkIdType numRows = curTable->GetNumberOfRows();
      vtkIdType numCols = curTable->GetNumberOfColumns();
      for (vtkIdType i = 0; i < numRows; i++)
      {
        vtkIdType curRow = wholeTable->InsertNextBlankRow();
        for (vtkIdType j = 0; j < numCols; j++)
        {
          wholeTable->SetValue(curRow, j, curTable->GetValue(i, j));
        }
      }
      curTable->Delete();
    }

    if (this->SocketController)
    { // Send collected data onto client.
      this->SocketController->Send(wholeTable, 1, 121767);
      // output will be empty.
    }
    else
    { // No client. Keep the output here.
      output->ShallowCopy(wholeTable);
    }
  }
  else
  {
    this->Controller->Send(input, 0, 121767);
  }

  return 1;
}

//------------------------------------------------------------------------------
void vtkCollectTable::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "PassThough: " << this->PassThrough << endl;
  os << indent << "Controller: (" << this->Controller << ")\n";
  os << indent << "SocketController: (" << this->SocketController << ")\n";
}
VTK_ABI_NAMESPACE_END
