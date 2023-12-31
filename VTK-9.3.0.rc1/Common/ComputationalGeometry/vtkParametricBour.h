// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkParametricBour
 * @brief   Generate Bour's minimal surface.
 *
 * vtkParametricBour generates Bour's minimal surface parametrically. More
 * information can be found at
 * <a href="http://en.wikipedia.org/wiki/Bour%27s_minimal_surface">Wikipedia</a>.
 * @par Thanks:
 * Tim Meehan
 */

#ifndef vtkParametricBour_h
#define vtkParametricBour_h

#include "vtkCommonComputationalGeometryModule.h" // For export macro
#include "vtkParametricFunction.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCOMPUTATIONALGEOMETRY_EXPORT vtkParametricBour : public vtkParametricFunction
{
public:
  vtkTypeMacro(vtkParametricBour, vtkParametricFunction);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct Bour's minimal surface with the following parameters:
   * (MinimumU, MaximumU) = (0., 1.),
   * (MinimumV, MaximumV) = (0., 4.*pi),
   * JoinU = 0, JoinV = 0,
   * TwistU = 0, TwistV = 0;
   * ClockwiseOrdering = 0,
   * DerivativesAvailable = 1,
   */
  static vtkParametricBour* New();

  /**
   * Return the parametric dimension of the class.
   */
  int GetDimension() override { return 2; }

  /**
   * Bour's minimal surface.

   * This function performs the mapping \f$f(u,v) \rightarrow (x,y,x)\f$, returning it
   * as Pt. It also returns the partial derivatives Du and Dv.
   * \f$Pt = (x, y, z), D_u\vec{f} = (dx/du, dy/du, dz/du), D_v\vec{f} = (dx/dv, dy/dv, dz/dv)\f$ .
   * Then the normal is \f$N = D_u\vec{f} \times D_v\vec{f}\f$ .
   */
  void Evaluate(double uvw[3], double Pt[3], double Duvw[9]) override;

  /**
   * Calculate a user defined scalar using one or all of uvw, Pt, Duvw.
   * This method simply returns 0.
   */
  double EvaluateScalar(double uvw[3], double Pt[3], double Duvw[9]) override;

protected:
  vtkParametricBour();
  ~vtkParametricBour() override;

private:
  vtkParametricBour(const vtkParametricBour&) = delete;
  void operator=(const vtkParametricBour&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
