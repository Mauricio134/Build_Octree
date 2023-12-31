// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkParametricEllipsoid.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include <cmath>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkParametricEllipsoid);

//------------------------------------------------------------------------------
vtkParametricEllipsoid::vtkParametricEllipsoid()
  : XRadius(1)
  , YRadius(1)
  , ZRadius(1)
{
  // Preset triangulation parameters
  this->MinimumU = 0;
  this->MaximumU = 2.0 * vtkMath::Pi();
  this->MinimumV = 0;
  this->MaximumV = vtkMath::Pi();

  this->JoinU = 1;
  this->JoinV = 0;
  this->TwistU = 0;
  this->TwistV = 0;
  this->ClockwiseOrdering = 0;
  this->DerivativesAvailable = 1;
}

//------------------------------------------------------------------------------
vtkParametricEllipsoid::~vtkParametricEllipsoid() = default;

//------------------------------------------------------------------------------
void vtkParametricEllipsoid::Evaluate(double uvw[3], double Pt[3], double Duvw[9])
{
  double u = uvw[0];
  double v = uvw[1];
  double* Du = Duvw;
  double* Dv = Duvw + 3;

  for (int i = 0; i < 3; ++i)
  {
    Pt[i] = Du[i] = Dv[i] = 0;
  }

  double cu = cos(u);
  double su = sin(u);
  double cv = cos(v);
  double sv = sin(v);

  // The point
  Pt[0] = this->XRadius * sv * cu;
  Pt[1] = this->YRadius * sv * su;
  Pt[2] = this->ZRadius * cv;

  // The derivatives are:
  Du[0] = -this->XRadius * sv * su;
  Du[1] = this->YRadius * sv * cu;
  Du[2] = 0;
  Dv[0] = this->XRadius * cv * cu;
  Dv[1] = this->YRadius * cv * su;
  Dv[2] = -this->ZRadius * sv;
}

//------------------------------------------------------------------------------
double vtkParametricEllipsoid::EvaluateScalar(double*, double*, double*)
{
  return 0;
}

//------------------------------------------------------------------------------
void vtkParametricEllipsoid::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "X scale factor: " << this->XRadius << "\n";
  os << indent << "Y scale factor: " << this->YRadius << "\n";
  os << indent << "Z scale factor: " << this->ZRadius << "\n";
}
VTK_ABI_NAMESPACE_END
