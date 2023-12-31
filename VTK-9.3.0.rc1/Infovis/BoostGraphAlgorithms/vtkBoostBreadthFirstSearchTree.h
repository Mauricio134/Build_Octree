// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkBoostBreadthFirstSearchTree
 * @brief   Constructs a BFS tree from a graph
 *
 *
 *
 * This vtk class uses the Boost breadth_first_search
 * generic algorithm to perform a breadth first search from a given
 * a 'source' vertex on the input graph (a vtkGraph).
 * The result is a tree with root node corresponding to the start node
 * of the search.
 *
 * @sa
 * vtkGraph vtkBoostGraphAdapter
 */

#ifndef vtkBoostBreadthFirstSearchTree_h
#define vtkBoostBreadthFirstSearchTree_h

#include "vtkInfovisBoostGraphAlgorithmsModule.h" // For export macro
#include "vtkStdString.h"                         // For string type
#include "vtkVariant.h"                           // For variant type

#include "vtkTreeAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKINFOVISBOOSTGRAPHALGORITHMS_EXPORT vtkBoostBreadthFirstSearchTree : public vtkTreeAlgorithm
{
public:
  static vtkBoostBreadthFirstSearchTree* New();
  vtkTypeMacro(vtkBoostBreadthFirstSearchTree, vtkTreeAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Set the index (into the vertex array) of the
   * breadth first search 'origin' vertex.
   */
  void SetOriginVertex(vtkIdType index);

  /**
   * Set the breadth first search 'origin' vertex.
   * This method is basically the same as above
   * but allows the application to simply specify
   * an array name and value, instead of having to
   * know the specific index of the vertex.
   */
  void SetOriginVertex(vtkStdString arrayName, vtkVariant value);

  ///@{
  /**
   * Stores the graph vertex ids for the tree vertices in an array
   * named "GraphVertexId".  Default is off.
   */
  vtkSetMacro(CreateGraphVertexIdArray, bool);
  vtkGetMacro(CreateGraphVertexIdArray, bool);
  vtkBooleanMacro(CreateGraphVertexIdArray, bool);
  ///@}

  ///@{
  /**
   * Turn on this option to reverse the edges in the graph.
   */
  vtkSetMacro(ReverseEdges, bool);
  vtkGetMacro(ReverseEdges, bool);
  vtkBooleanMacro(ReverseEdges, bool);
  ///@}

protected:
  vtkBoostBreadthFirstSearchTree();
  ~vtkBoostBreadthFirstSearchTree() override;

  int FillInputPortInformation(int port, vtkInformation* info) override;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

private:
  vtkIdType OriginVertexIndex;
  char* ArrayName;
  vtkVariant OriginValue;
  bool ArrayNameSet;
  bool CreateGraphVertexIdArray;
  bool ReverseEdges;

  ///@{
  /**
   * Using the convenience function for set strings internally
   */
  vtkSetStringMacro(ArrayName);
  ///@}

  /**
   * This method is basically a helper function to find
   * the index of a specific value within a specific array
   */
  vtkIdType GetVertexIndex(vtkAbstractArray* abstract, vtkVariant value);

  vtkBoostBreadthFirstSearchTree(const vtkBoostBreadthFirstSearchTree&) = delete;
  void operator=(const vtkBoostBreadthFirstSearchTree&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
