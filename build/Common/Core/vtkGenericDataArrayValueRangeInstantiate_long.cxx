// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// We only compile the 64-bit integer range compulation for value types
// of long, unsigned long, long long, and unsigned long log.  All others
// reuse the double-precision vtkDataArray::GetRange version, since they
// won't lose precision.

#define VTK_GDA_VALUERANGE_INSTANTIATING
#include "vtkGenericDataArray.h"

#include "vtkDataArrayPrivate.txx"

#include "vtkAOSDataArrayTemplate.h"
#include "vtkSOADataArrayTemplate.h"

#ifdef VTK_USE_SCALED_SOA_ARRAYS
#include "vtkScaledSOADataArrayTemplate.h"
#endif

namespace vtkDataArrayPrivate
{
VTK_ABI_NAMESPACE_BEGIN
VTK_INSTANTIATE_VALUERANGE_VALUETYPE(long)
VTK_ABI_NAMESPACE_END
}
