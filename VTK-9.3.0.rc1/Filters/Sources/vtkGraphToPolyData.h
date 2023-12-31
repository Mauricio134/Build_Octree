// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkGraphToPolyData
 * @brief   convert a vtkGraph to vtkPolyData
 *
 *
 * Converts a vtkGraph to a vtkPolyData.  This assumes that the points
 * of the graph have already been filled (perhaps by vtkGraphLayout),
 * and converts all the edge of the graph into lines in the polydata.
 * The vertex data is passed along to the point data, and the edge data
 * is passed along to the cell data.
 *
 * Only the owned graph edges (i.e. edges with ghost level 0) are copied
 * into the vtkPolyData.
 */

#ifndef vtkGraphToPolyData_h
#define vtkGraphToPolyData_h

#include "vtkFiltersSourcesModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKFILTERSSOURCES_EXPORT vtkGraphToPolyData : public vtkPolyDataAlgorithm
{
public:
  static vtkGraphToPolyData* New();
  vtkTypeMacro(vtkGraphToPolyData, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Create a second output containing points and orientation vectors
   * for drawing arrows or other glyphs on edges.  This output should be
   * set as the first input to vtkGlyph3D to place glyphs on the edges.
   * vtkGlyphSource2D's VTK_EDGEARROW_GLYPH provides a good glyph for
   * drawing arrows.
   * Default value is off.
   */
  vtkSetMacro(EdgeGlyphOutput, bool);
  vtkGetMacro(EdgeGlyphOutput, bool);
  vtkBooleanMacro(EdgeGlyphOutput, bool);
  ///@}

  ///@{
  /**
   * The position of the glyph point along the edge.
   * 0 puts a glyph point at the source of each edge.
   * 1 puts a glyph point at the target of each edge.
   * An intermediate value will place the glyph point between the source and target.
   * The default value is 1.
   */
  vtkSetMacro(EdgeGlyphPosition, double);
  vtkGetMacro(EdgeGlyphPosition, double);
  ///@}

protected:
  vtkGraphToPolyData();
  ~vtkGraphToPolyData() override = default;

  bool EdgeGlyphOutput;
  double EdgeGlyphPosition;
  bool ArcEdges;
  vtkIdType NumberOfArcSubdivisions;

  /**
   * Convert the vtkGraph into vtkPolyData.
   */
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  /**
   * Set the input type of the algorithm to vtkGraph.
   */
  int FillInputPortInformation(int port, vtkInformation* info) override;

private:
  vtkGraphToPolyData(const vtkGraphToPolyData&) = delete;
  void operator=(const vtkGraphToPolyData&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
