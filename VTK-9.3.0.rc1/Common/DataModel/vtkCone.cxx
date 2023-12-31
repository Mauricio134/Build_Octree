// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkCone.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkCone);

// Construct cone with angle of 45 degrees.
vtkCone::vtkCone()
{
  this->Angle = 45.0;
}

// Evaluate cone equation.
double vtkCone::EvaluateFunction(double x[3])
{
  double tanTheta = tan(vtkMath::RadiansFromDegrees(this->Angle));
  return x[1] * x[1] + x[2] * x[2] - x[0] * x[0] * tanTheta * tanTheta;
}

// Evaluate cone normal.
void vtkCone::EvaluateGradient(double x[3], double g[3])
{
  double tanTheta = tan(vtkMath::RadiansFromDegrees(this->Angle));
  g[0] = -2.0 * x[0] * tanTheta * tanTheta;
  g[1] = 2.0 * x[1];
  g[2] = 2.0 * x[2];
}

void vtkCone::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Angle: " << this->Angle << "\n";
}
VTK_ABI_NAMESPACE_END
