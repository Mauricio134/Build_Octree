// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkGraphEdge
 * @brief   Representation of a single graph edge.
 *
 *
 * A heavy-weight (vtkObject subclass) graph edge object that may be used
 * instead of the vtkEdgeType struct, for use with wrappers.
 * The edge contains the source and target vertex ids, and the edge id.
 *
 * @sa
 * vtkGraph
 */

#ifndef vtkGraphEdge_h
#define vtkGraphEdge_h

#include "vtkCommonDataModelModule.h" // For export macro
#include "vtkObject.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONDATAMODEL_EXPORT vtkGraphEdge : public vtkObject
{
public:
  static vtkGraphEdge* New();
  vtkTypeMacro(vtkGraphEdge, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * The source of the edge.
   */
  vtkSetMacro(Source, vtkIdType);
  vtkGetMacro(Source, vtkIdType);
  ///@}

  ///@{
  /**
   * The target of the edge.
   */
  vtkSetMacro(Target, vtkIdType);
  vtkGetMacro(Target, vtkIdType);
  ///@}

  ///@{
  /**
   * The id of the edge.
   */
  vtkSetMacro(Id, vtkIdType);
  vtkGetMacro(Id, vtkIdType);
  ///@}

protected:
  vtkGraphEdge();
  ~vtkGraphEdge() override;

  vtkIdType Source;
  vtkIdType Target;
  vtkIdType Id;

private:
  vtkGraphEdge(const vtkGraphEdge&) = delete;
  void operator=(const vtkGraphEdge&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
