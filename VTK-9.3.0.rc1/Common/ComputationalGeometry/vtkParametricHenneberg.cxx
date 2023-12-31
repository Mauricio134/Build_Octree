// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkParametricHenneberg.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkParametricHenneberg);
//----------------------------------------------------------------------------//
vtkParametricHenneberg::vtkParametricHenneberg()
{
  // Preset triangulation parameters
  this->MinimumU = -1.0;
  this->MaximumU = 1.0;
  this->MinimumV = -vtkMath::Pi() / 2.;
  this->MaximumV = vtkMath::Pi() / 2.;

  this->JoinU = 0;
  this->JoinV = 0;
  this->TwistU = 0;
  this->TwistV = 0;
  this->ClockwiseOrdering = 0;
  this->DerivativesAvailable = 1;
}

//----------------------------------------------------------------------------//
vtkParametricHenneberg::~vtkParametricHenneberg() = default;

//----------------------------------------------------------------------------//
void vtkParametricHenneberg::Evaluate(double uvw[3], double Pt[3], double Duvw[9])
{
  // Copy the parameters out of the vector, for the sake of convenience.
  double u = uvw[0];
  double v = uvw[1];

  // We're only going to need the u and v partial derivatives.
  // The w partial derivatives are not needed.
  double* Du = Duvw;
  double* Dv = Duvw + 3;

  // Location of the point. This parametrization was taken from:
  // http://mathworld.wolfram.com/HennebergsMinimalSurface.html
  Pt[0] = 2. * sinh(u) * cos(v) - 2. / 3. * sinh(3. * u) * cos(3. * v);
  Pt[1] = 2. * sinh(u) * sin(v) + 2. / 3. * sinh(3. * u) * sin(3. * v);
  Pt[2] = 2. * cosh(2. * u) * cos(2. * v);

  // The derivative with respect to u:
  Du[0] = 2. * cosh(u) * cos(v) - 2. * cosh(3. * u) * cos(3. * v);
  Du[1] = 2. * cosh(u) * sin(v) + 2. * cosh(3. * u) * sin(3. * v);
  Du[2] = 4. * sinh(2. * u) * cos(2. * v);

  // The derivative with respect to v:
  Dv[0] = -2. * sinh(u) * sin(v) + 2. * sinh(3. * u) * sin(3. * v);
  Dv[1] = 2. * sinh(u) * cos(v) + 2. * sinh(3. * u) * cos(3. * v);
  Dv[2] = -4. * cosh(2. * u) * sin(2. * v);
}

//----------------------------------------------------------------------------//
double vtkParametricHenneberg::EvaluateScalar(double*, double*, double*)
{
  return 0;
}

//----------------------------------------------------------------------------//
void vtkParametricHenneberg::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
