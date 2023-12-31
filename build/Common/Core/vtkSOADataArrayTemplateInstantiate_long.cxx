// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// This file generates an instantiation of vtkSOADataArrayTemplate.
// For AoS arrays, this is done in the more derived classes, for example
// compiling vtkFloatArray.cxx instantiates vtkAOSDataArrayTemplate<float>.

#define VTK_SOA_DATA_ARRAY_TEMPLATE_INSTANTIATING
#include "vtkSOADataArrayTemplate.txx"

VTK_SOA_DATA_ARRAY_TEMPLATE_INSTANTIATE(long);
