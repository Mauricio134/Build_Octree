// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkExtractPolyDataGeometry
 * @brief   extract vtkPolyData cells that lies either entirely inside or outside of a specified
 * implicit function
 *
 *
 * vtkExtractPolyDataGeometry extracts from its input vtkPolyData all cells
 * that are either completely inside or outside of a specified implicit
 * function. This filter is specialized to vtkPolyData. On output the
 * filter generates vtkPolyData.
 *
 * To use this filter you must specify an implicit function. You must also
 * specify whether to extract cells laying inside or outside of the implicit
 * function. (The inside of an implicit function is the negative values
 * region.) An option exists to extract cells that are neither inside nor
 * outside (i.e., boundary).
 *
 * Note that this filter also has the option to directly pass all points or cull
 * the points that do not satisfy the implicit function test. Passing all points
 * is a tad faster, but then points remain that do not pass the test and may mess
 * up subsequent glyphing operations and so on. By default points are culled.
 *
 * A more general version of this filter is available for arbitrary
 * vtkDataSet input (see vtkExtractGeometry).
 *
 * @sa
 * vtkExtractGeometry vtkClipPolyData vtkImplicitFunction
 */

#ifndef vtkExtractPolyDataGeometry_h
#define vtkExtractPolyDataGeometry_h

#include "vtkFiltersExtractionModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkImplicitFunction;

class VTKFILTERSEXTRACTION_EXPORT vtkExtractPolyDataGeometry : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkExtractPolyDataGeometry, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct object with ExtractInside turned on.
   */
  static vtkExtractPolyDataGeometry* New();

  /**
   * Return the MTime taking into account changes to the implicit function
   */
  vtkMTimeType GetMTime() override;

  ///@{
  /**
   * Specify the implicit function for inside/outside checks.
   */
  virtual void SetImplicitFunction(vtkImplicitFunction*);
  vtkGetObjectMacro(ImplicitFunction, vtkImplicitFunction);
  ///@}

  ///@{
  /**
   * Boolean controls whether to extract cells that are inside of implicit
   * function (ExtractInside == 1) or outside of implicit function
   * (ExtractInside == 0).
   */
  vtkSetMacro(ExtractInside, vtkTypeBool);
  vtkGetMacro(ExtractInside, vtkTypeBool);
  vtkBooleanMacro(ExtractInside, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Boolean controls whether to extract cells that are partially inside.
   * By default, ExtractBoundaryCells is off.
   */
  vtkSetMacro(ExtractBoundaryCells, vtkTypeBool);
  vtkGetMacro(ExtractBoundaryCells, vtkTypeBool);
  vtkBooleanMacro(ExtractBoundaryCells, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Boolean controls whether points are culled or simply passed through
   * to the output.
   */
  vtkSetMacro(PassPoints, vtkTypeBool);
  vtkGetMacro(PassPoints, vtkTypeBool);
  vtkBooleanMacro(PassPoints, vtkTypeBool);
  ///@}

protected:
  vtkExtractPolyDataGeometry(vtkImplicitFunction* f = nullptr);
  ~vtkExtractPolyDataGeometry() override;

  // Usual data generation method
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  vtkImplicitFunction* ImplicitFunction;
  vtkTypeBool ExtractInside;
  vtkTypeBool ExtractBoundaryCells;
  vtkTypeBool PassPoints;

  vtkIdType InsertPointInMap(vtkIdType i, vtkPoints* inPts, vtkPoints* newPts, vtkIdType* pointMap);

private:
  vtkExtractPolyDataGeometry(const vtkExtractPolyDataGeometry&) = delete;
  void operator=(const vtkExtractPolyDataGeometry&) = delete;
};

///@{
/**
 * When not passing points, have to use a point map to keep track of things.
 */
inline vtkIdType vtkExtractPolyDataGeometry::InsertPointInMap(
  vtkIdType i, vtkPoints* inPts, vtkPoints* newPts, vtkIdType* pointMap)
{
  double x[3];
  inPts->GetPoint(i, x);
  pointMap[i] = newPts->InsertNextPoint(x);
  return pointMap[i];
}
///@}

VTK_ABI_NAMESPACE_END
#endif
