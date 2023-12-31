// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkFillHolesFilter
 * @brief   identify and fill holes in meshes
 *
 * vtkFillHolesFilter is a filter that identifies and fills holes in
 * input vtkPolyData meshes. Holes are identified by locating
 * boundary edges, linking them together into loops, and then
 * triangulating the resulting loops. Note that you can specify
 * an approximate limit to the size of the hole that can be filled.
 *
 * @warning
 * Note that any mesh with boundary edges by definition has a
 * topological hole. This even includes a reactangular grid
 * (e.g., the output of vtkPlaneSource). In such situations, if
 * the outer hole is filled, retriangulation of the hole will cause
 * geometric overlap of the mesh. This can be prevented by using
 * the hole size instance variable to prevent the larger holes
 * from being triangulated.
 *
 * @warning
 * Note this filter only operates on polygons and triangle strips.
 * Vertices and polylines are passed through untouched.
 */

#ifndef vtkFillHolesFilter_h
#define vtkFillHolesFilter_h

#include "vtkFiltersModelingModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkAbstractTransform;

class VTKFILTERSMODELING_EXPORT vtkFillHolesFilter : public vtkPolyDataAlgorithm
{
public:
  ///@{
  /**
   * Standard methods for instantiation, type information and printing.
   */
  static vtkFillHolesFilter* New();
  vtkTypeMacro(vtkFillHolesFilter, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;
  ///@}

  ///@{
  /**
   * Specify the maximum hole size to fill. This is represented as a radius
   * to the bounding circumsphere containing the hole.  Note that this is an
   * approximate area; the actual area cannot be computed without first
   * triangulating the hole.
   */
  vtkSetClampMacro(HoleSize, double, 0.0, VTK_FLOAT_MAX);
  vtkGetMacro(HoleSize, double);
  ///@}

protected:
  vtkFillHolesFilter();
  ~vtkFillHolesFilter() override;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  double HoleSize;

private:
  vtkFillHolesFilter(const vtkFillHolesFilter&) = delete;
  void operator=(const vtkFillHolesFilter&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
