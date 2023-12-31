// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkUniformGridPartitioner.h"
#include "vtkExtentRCBPartitioner.h"
#include "vtkIndent.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMultiBlockDataSet.h"
#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkStructuredData.h"
#include "vtkStructuredExtent.h"
#include "vtkUniformGrid.h"

#include <cassert>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkUniformGridPartitioner);

//------------------------------------------------------------------------------
vtkUniformGridPartitioner::vtkUniformGridPartitioner()
{
  this->NumberOfPartitions = 2;
  this->NumberOfGhostLayers = 0;
  this->DuplicateNodes = 1;
}

//------------------------------------------------------------------------------
vtkUniformGridPartitioner::~vtkUniformGridPartitioner() = default;

//------------------------------------------------------------------------------
void vtkUniformGridPartitioner::PrintSelf(std::ostream& oss, vtkIndent indent)
{
  this->Superclass::PrintSelf(oss, indent);
  oss << "NumberOfPartitions: " << this->NumberOfPartitions << std::endl;
  oss << "NumberOfGhostLayers: " << this->NumberOfGhostLayers << std::endl;
  oss << "DuplicateNodes: " << this->DuplicateNodes << std::endl;
}

//------------------------------------------------------------------------------
int vtkUniformGridPartitioner::FillInputPortInformation(int vtkNotUsed(port), vtkInformation* info)
{
  info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkImageData");
  return 1;
}

//------------------------------------------------------------------------------
int vtkUniformGridPartitioner::FillOutputPortInformation(int vtkNotUsed(port), vtkInformation* info)
{
  info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkMultiBlockDataSet");
  return 1;
}

//------------------------------------------------------------------------------
int vtkUniformGridPartitioner::RequestData(vtkInformation* vtkNotUsed(request),
  vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  // STEP 0: Get input object
  vtkInformation* input = inputVector[0]->GetInformationObject(0);
  assert("pre: input information object is nullptr" && (input != nullptr));

  vtkImageData* grd = vtkImageData::SafeDownCast(input->Get(vtkDataObject::DATA_OBJECT()));
  assert("pre: input grid is nullptr!" && (grd != nullptr));

  // STEP 1: Get output object
  vtkInformation* output = outputVector->GetInformationObject(0);
  assert("pre: output information object is nullptr" && (output != nullptr));
  vtkMultiBlockDataSet* multiblock =
    vtkMultiBlockDataSet::SafeDownCast(output->Get(vtkDataObject::DATA_OBJECT()));
  assert("pre: multiblock grid is nullptr!" && (multiblock != nullptr));

  // STEP 2: Get the global extent
  int extent[6];
  int dims[3];
  grd->GetDimensions(dims);
  grd->GetExtent(extent);

  // STEP 3: Setup extent partitioner
  vtkExtentRCBPartitioner* extentPartitioner = vtkExtentRCBPartitioner::New();
  assert("pre: extent partitioner is nullptr" && (extentPartitioner != nullptr));
  extentPartitioner->SetGlobalExtent(extent);
  extentPartitioner->SetNumberOfPartitions(this->NumberOfPartitions);
  extentPartitioner->SetNumberOfGhostLayers(this->NumberOfGhostLayers);
  if (this->DuplicateNodes == 1)
  {
    extentPartitioner->DuplicateNodesOn();
  }
  else
  {
    extentPartitioner->DuplicateNodesOff();
  }

  // STEP 4: Partition
  extentPartitioner->Partition();

  // STEP 5: Extract partitions into a multi-block dataset.
  multiblock->SetNumberOfBlocks(extentPartitioner->GetNumExtents());

  // Set the whole extent of the grid
  multiblock->GetInformation()->Set(vtkStreamingDemandDrivenPipeline::WHOLE_EXTENT(), extent, 6);

  unsigned int blockIdx = 0;
  for (; blockIdx < multiblock->GetNumberOfBlocks(); ++blockIdx)
  {
    int ext[6];
    extentPartitioner->GetPartitionExtent(blockIdx, ext);

    double origin[3];
    int ijk[3];
    ijk[0] = ext[0];
    ijk[1] = ext[2];
    ijk[2] = ext[4];

    int subdims[3];
    vtkStructuredExtent::GetDimensions(ext, subdims);

    vtkIdType pntIdx = vtkStructuredData::ComputePointId(dims, ijk);

    grd->GetPoint(pntIdx, origin);

    vtkUniformGrid* subgrid = vtkUniformGrid::New();
    subgrid->SetOrigin(origin);
    subgrid->SetSpacing(grd->GetSpacing());
    subgrid->SetDimensions(subdims);

    // Set the global extent for each block
    vtkInformation* metadata = multiblock->GetMetaData(blockIdx);
    assert("pre: metadata is nullptr" && (metadata != nullptr));
    metadata->Set(vtkDataObject::PIECE_EXTENT(), ext, 6);

    multiblock->SetBlock(blockIdx, subgrid);
    subgrid->Delete();
  } // END for all blocks

  extentPartitioner->Delete();
  return 1;
}
VTK_ABI_NAMESPACE_END
