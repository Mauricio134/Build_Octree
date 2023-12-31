// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

#include "vtkPruneTreeFilter.h"

#include "vtkCellData.h"
#include "vtkInformation.h"
#include "vtkMutableDirectedGraph.h"
#include "vtkObjectFactory.h"
#include "vtkOutEdgeIterator.h"
#include "vtkPointData.h"
#include "vtkSmartPointer.h"
#include "vtkStringArray.h"
#include "vtkTree.h"
#include "vtkTreeDFSIterator.h"

#include <utility>
#include <vector>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkPruneTreeFilter);

vtkPruneTreeFilter::vtkPruneTreeFilter()
{
  this->ParentVertex = 0;
  this->ShouldPruneParentVertex = true;
}

vtkPruneTreeFilter::~vtkPruneTreeFilter() = default;

void vtkPruneTreeFilter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "Parent: " << this->ParentVertex << endl;
}

int vtkPruneTreeFilter::RequestData(
  vtkInformation*, vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  vtkTree* inputTree = vtkTree::GetData(inputVector[0]);
  vtkTree* outputTree = vtkTree::GetData(outputVector);

  if (this->ParentVertex < 0 || this->ParentVertex >= inputTree->GetNumberOfVertices())
  {
    vtkErrorMacro("Parent vertex must be part of the tree "
      << this->ParentVertex << " >= " << inputTree->GetNumberOfVertices());
    return 0;
  }

  // Structure for building the tree.
  vtkSmartPointer<vtkMutableDirectedGraph> builder =
    vtkSmartPointer<vtkMutableDirectedGraph>::New();

  // Child iterator.
  vtkSmartPointer<vtkOutEdgeIterator> it = vtkSmartPointer<vtkOutEdgeIterator>::New();

  // Get the input and builder vertex and edge data.
  vtkDataSetAttributes* inputVertexData = inputTree->GetVertexData();
  vtkDataSetAttributes* inputEdgeData = inputTree->GetEdgeData();
  vtkDataSetAttributes* builderVertexData = builder->GetVertexData();
  vtkDataSetAttributes* builderEdgeData = builder->GetEdgeData();
  builderVertexData->CopyAllocate(inputVertexData);
  builderEdgeData->CopyAllocate(inputEdgeData);

  // Copy field data
  builder->GetFieldData()->DeepCopy(inputTree->GetFieldData());

  // Build a copy of the tree, skipping the parent vertex to remove.
  std::vector<std::pair<vtkIdType, vtkIdType>> vertStack;
  if (inputTree->GetRoot() != this->ParentVertex)
  {
    vertStack.emplace_back(inputTree->GetRoot(), builder->AddVertex());
  }
  while (!vertStack.empty())
  {
    vtkIdType tree_v = vertStack.back().first;
    vtkIdType v = vertStack.back().second;
    builderVertexData->CopyData(inputVertexData, tree_v, v);
    vertStack.pop_back();
    inputTree->GetOutEdges(tree_v, it);
    while (it->HasNext())
    {
      vtkOutEdgeType tree_e = it->Next();
      vtkIdType tree_child = tree_e.Target;
      if (this->ShouldPruneParentVertex)
      {
        if (tree_child != this->ParentVertex)
        {
          vtkIdType child = builder->AddVertex();
          vtkEdgeType e = builder->AddEdge(v, child);
          builderEdgeData->CopyData(inputEdgeData, tree_e.Id, e.Id);
          vertStack.emplace_back(tree_child, child);
        }
      }
      else
      {
        vtkIdType child = builder->AddVertex();
        vtkEdgeType e = builder->AddEdge(v, child);
        builderEdgeData->CopyData(inputEdgeData, tree_e.Id, e.Id);
        if (tree_child != this->ParentVertex)
        {
          vertStack.emplace_back(tree_child, child);
        }
        else
        {
          builderVertexData->CopyData(inputVertexData, tree_child, child);
        }
      }
    }
  }

  // Copy the structure into the output.
  if (!outputTree->CheckedShallowCopy(builder))
  {
    vtkErrorMacro(<< "Invalid tree structure.");
    return 0;
  }

  return 1;
}
VTK_ABI_NAMESPACE_END
