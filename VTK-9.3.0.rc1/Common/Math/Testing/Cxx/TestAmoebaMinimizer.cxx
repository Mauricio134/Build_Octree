// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkAmoebaMinimizer.h"
#include <cmath>

// the function to be minimized
static void vtkFunctionToMinimize(void* arg)
{
  vtkAmoebaMinimizer* minimizer = static_cast<vtkAmoebaMinimizer*>(arg);

  double x = minimizer->GetParameterValue("x");
  double y = minimizer->GetParameterValue("y");
  double z = minimizer->GetParameterValue("z");

  double r = (x - 5) * (x - 5) + (y + 2) * (y + 2) + (z) * (z);

  minimizer->SetFunctionValue(r);
}

int TestAmoebaMinimizer(int argc, char*[])
{
  vtkAmoebaMinimizer* minimizer = vtkAmoebaMinimizer::New();

  minimizer->SetFunction(&vtkFunctionToMinimize, minimizer);
  minimizer->SetParameterValue("x", 0.0);
  minimizer->SetParameterScale("x", 2.0);
  minimizer->SetParameterValue("y", 0.0);
  minimizer->SetParameterScale("y", 2.0);
  minimizer->SetParameterValue("z", 0.0);
  minimizer->SetParameterScale("z", 2.0);

  minimizer->Minimize();

  double x = minimizer->GetParameterValue("x");
  double y = minimizer->GetParameterValue("y");
  double z = minimizer->GetParameterValue("z");

  double r = minimizer->GetFunctionValue();

  int iterations = minimizer->GetIterations();

  int maxiterations = minimizer->GetMaxIterations();

  int noconvergence = minimizer->Iterate();

  minimizer->Delete();

  // check parameters to make sure that they converged to the
  // correct values
  if (argc > 10 || fabs(x - 5.0) > 1e-4 || fabs(y + 2.0) > 1e-4 || fabs(z - 0.0) > 1e-4 ||
    r > 1e-4 || iterations >= maxiterations || noconvergence)
  {
    return 1;
  }

  return 0;
}
