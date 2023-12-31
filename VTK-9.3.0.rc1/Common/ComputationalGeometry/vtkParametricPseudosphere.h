// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkParametricPseudosphere
 * @brief   Generate a pseudosphere.
 *
 * vtkParametricPseudosphere generates a parametric pseudosphere. The
 * pseudosphere is generated as a surface of revolution of the tractrix about
 * it's asymptote, and is a surface of constant negative Gaussian curvature.
 * You can find out more about this interesting surface at
 * <a href="http://mathworld.wolfram.com/Pseudosphere.html">Math World</a>.
 * @par Thanks:
 * Tim Meehan
 */

#ifndef vtkParametricPseudosphere_h
#define vtkParametricPseudosphere_h

#include "vtkCommonComputationalGeometryModule.h" // For export macro
#include "vtkParametricFunction.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCOMPUTATIONALGEOMETRY_EXPORT vtkParametricPseudosphere : public vtkParametricFunction
{
public:
  vtkTypeMacro(vtkParametricPseudosphere, vtkParametricFunction);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct a pseudosphere surface with the following parameters:
   * (MinimumU, MaximumU) = (-5., 5.),
   * (MinimumV, MaximumV) = (-pi, pi),
   * JoinU = 0, JoinV = 1,
   * TwistU = 0, TwistV = 0;
   * ClockwiseOrdering = 0,
   * DerivativesAvailable = 1,
   */
  static vtkParametricPseudosphere* New();

  /**
   * Return the parametric dimension of the class.
   */
  int GetDimension() override { return 2; }

  /**
   * Pseudosphere surface.

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
  vtkParametricPseudosphere();
  ~vtkParametricPseudosphere() override;

private:
  vtkParametricPseudosphere(const vtkParametricPseudosphere&) = delete;
  void operator=(const vtkParametricPseudosphere&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
