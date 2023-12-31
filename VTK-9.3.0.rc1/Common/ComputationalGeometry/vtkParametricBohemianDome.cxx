// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkParametricBohemianDome.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkParametricBohemianDome);
//----------------------------------------------------------------------------//
vtkParametricBohemianDome::vtkParametricBohemianDome()
  : A(0.5)
  , B(1.5)
  , C(1.0)
{
  // Preset triangulation parameters
  this->MinimumU = -vtkMath::Pi();
  this->MaximumU = vtkMath::Pi();
  this->MinimumV = -vtkMath::Pi();
  this->MaximumV = vtkMath::Pi();

  this->JoinU = 1;
  this->JoinV = 1;
  this->TwistU = 0;
  this->TwistV = 1;
  this->ClockwiseOrdering = 0;
  this->DerivativesAvailable = 1;
}

//----------------------------------------------------------------------------//
vtkParametricBohemianDome::~vtkParametricBohemianDome() = default;

//----------------------------------------------------------------------------//
void vtkParametricBohemianDome::Evaluate(double uvw[3], double Pt[3], double Duvw[9])
{
  // Copy the parameters out of the vector, for the sake of convenience.
  double u = uvw[0];
  double v = uvw[1];

  // We're only going to need the u and v partial derivatives.
  // The w partial derivatives are not needed.
  double* Du = Duvw;
  double* Dv = Duvw + 3;

  // Instead of a bunch of calls to the trig library,
  // just call it once and store the results.
  double cosu = cos(u);
  double sinu = sin(u);
  double cosv = cos(v);
  double sinv = sin(v);

  // Location of the point. This parametrization was taken from:
  // http://mathworld.wolfram.com/BohemianDome.html
  Pt[0] = this->A * cosu;
  Pt[1] = this->A * sinu + this->B * cosv;
  Pt[2] = this->C * sinv;

  // The derivative with respect to u:
  Du[0] = -this->A * sinu;
  Du[1] = this->A * cosu;
  Du[2] = 0.;

  // The derivative with respect to v:
  Dv[0] = 0.;
  Dv[1] = -this->B * sinv;
  Dv[2] = this->C * cosv;
}

//----------------------------------------------------------------------------//
double vtkParametricBohemianDome::EvaluateScalar(double*, double*, double*)
{
  return 0;
}

//----------------------------------------------------------------------------//
void vtkParametricBohemianDome::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
