// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkTulipReader
 * @brief   Reads tulip graph files.
 *
 *
 * vtkTulipReader reads in files in the Tulip format.
 * Definition of the Tulip file format can be found online at:
 * http://tulip.labri.fr/tlpformat.php
 * An example is the following
 * <code>
 * (nodes 0 1 2 3 4 5 6 7 8 9)
 * (edge 0 0 1)
 * (edge 1 1 2)
 * (edge 2 2 3)
 * (edge 3 3 4)
 * (edge 4 4 5)
 * (edge 5 5 6)
 * (edge 6 6 7)
 * (edge 7 7 8)
 * (edge 8 8 9)
 * (edge 9 9 0)
 * (edge 10 0 5)
 * (edge 11 2 7)
 * (edge 12 4 9)
 * </code>
 * where "nodes" defines all the nodes ids in the graph, and "edge"
 * is a triple of edge id, source vertex id, and target vertex id.
 * The graph is read in as undirected graph. Pedigree ids are set on the output
 * graph's vertices and edges that match the node and edge ids defined in the
 * Tulip file.
 *
 * Clusters are output as a vtkAnnotationLayers on output port 1. Each cluster
 * name is used to create an annotation layer, and each cluster with that name
 * is added to the layer as a vtkSelectionNode. Nesting hierarchies are treated
 * as if they were flat. See vtkGraphAnnotationLayersFilter for an example of
 * how the clusters can be represented visually.
 *
 * @attention
 * Only string, int, and double properties are supported. Display information
 * is discarded.
 *
 * @par Thanks:
 * Thanks to Colin Myers, University of Leeds for extending this implementation.
 */

#ifndef vtkTulipReader_h
#define vtkTulipReader_h

#include "vtkIOInfovisModule.h" // For export macro
#include "vtkUndirectedGraphAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKIOINFOVIS_EXPORT vtkTulipReader : public vtkUndirectedGraphAlgorithm
{
public:
  static vtkTulipReader* New();
  vtkTypeMacro(vtkTulipReader, vtkUndirectedGraphAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * The Tulip file name.
   */
  vtkGetFilePathMacro(FileName);
  vtkSetFilePathMacro(FileName);
  ///@}

protected:
  vtkTulipReader();
  ~vtkTulipReader() override;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  /**
   * Set the outputs to vtkUndirectedGraph and vtkAnnotationLayers.
   */
  int FillOutputPortInformation(int port, vtkInformation* info) override;

private:
  char* FileName;

  vtkTulipReader(const vtkTulipReader&) = delete;
  void operator=(const vtkTulipReader&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif // vtkTulipReader_h
