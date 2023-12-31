// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkParametricConicSpiral
 * @brief   Generate conic spiral surfaces that resemble sea-shells.
 *
 * vtkParametricConicSpiral generates conic spiral surfaces. These can resemble sea shells, or
 * may look like a torus "eating" its own tail.
 *
 * For further information about this surface, please consult the
 * technical description "Parametric surfaces" in http://www.vtk.org/publications
 * in the "VTK Technical Documents" section in the VTk.org web pages.
 *
 * @par Thanks:
 * Andrew Maclean andrew.amaclean@gmail.com for creating and contributing the
 * class.
 *
 */

#ifndef vtkParametricConicSpiral_h
#define vtkParametricConicSpiral_h

#include "vtkCommonComputationalGeometryModule.h" // For export macro
#include "vtkParametricFunction.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCOMPUTATIONALGEOMETRY_EXPORT vtkParametricConicSpiral : public vtkParametricFunction
{
public:
  vtkTypeMacro(vtkParametricConicSpiral, vtkParametricFunction);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct a conic spiral surface with the following parameters:
   * MinimumU = 0, MaximumU = 2Pi,
   * MinimumV = 0, MaximumV = 2Pi,
   * JoinU = 0, JoinV = 0,
   * TwistU = 0, TwistV = 0,
   * ClockwiseOrdering = 0,
   * DerivativesAvailable = 1,
   * A = 0.2, B = 1.0, C = 0.1, N = 2.
   */
  static vtkParametricConicSpiral* New();

  /**
   * Return the parametric dimension of the class.
   */
  int GetDimension() override { return 2; }

  ///@{
  /**
   * Set/Get the scale factor.
   * Default = 0.2
   */
  vtkSetMacro(A, double);
  vtkGetMacro(A, double);
  ///@}

  ///@{
  /**
   * Set/Get the A function coefficient.
   * See the definition in Parametric surfaces referred to above.
   * Default is 1.
   */
  vtkSetMacro(B, double);
  vtkGetMacro(B, double);
  ///@}

  ///@{
  /**
   * Set/Get the B function coefficient.
   * See the definition in Parametric surfaces referred to above.
   * Default is 0.1.
   */
  vtkSetMacro(C, double);
  vtkGetMacro(C, double);
  ///@}

  ///@{
  /**
   * Set/Get the C function coefficient.
   * See the definition in Parametric surfaces referred to above.
   * Default is 2.
   */
  vtkSetMacro(N, double);
  vtkGetMacro(N, double);
  ///@}

  /**
   * A conic spiral surface.

   * This function performs the mapping \f$f(u,v) \rightarrow (x,y,x)\f$, returning it
   * as Pt. It also returns the partial derivatives Du and Dv.
   * \f$Pt = (x, y, z), Du = (dx/du, dy/du, dz/du), Dv = (dx/dv, dy/dv, dz/dv)\f$ .
   * Then the normal is \f$N = Du X Dv\f$ .
   */
  void Evaluate(double uvw[3], double Pt[3], double Duvw[9]) override;

  /**
   * Calculate a user defined scalar using one or all of uvw, Pt, Duvw.

   * uvw are the parameters with Pt being the cartesian point,
   * Duvw are the derivatives of this point with respect to u, v and w.
   * Pt, Duvw are obtained from Evaluate().

   * This function is only called if the ScalarMode has the value
   * vtkParametricFunctionSource::SCALAR_FUNCTION_DEFINED

   * If the user does not need to calculate a scalar, then the
   * instantiated function should return zero.
   */
  double EvaluateScalar(double uvw[3], double Pt[3], double Duvw[9]) override;

protected:
  vtkParametricConicSpiral();
  ~vtkParametricConicSpiral() override;

  // Variables
  double A;
  double B;
  double C;
  double N;

private:
  vtkParametricConicSpiral(const vtkParametricConicSpiral&) = delete;
  void operator=(const vtkParametricConicSpiral&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
