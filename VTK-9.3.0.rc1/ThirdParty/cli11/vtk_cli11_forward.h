// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtk_cli11_forward_h
#define vtk_cli11_forward_h

// VTK_MODULE_USE_EXTERNAL_VTK_cli11 is defined in this header,
// so include it.
#include <vtk_cli11_external.h>

#if VTK_MODULE_USE_EXTERNAL_VTK_cli11
// using external CLI11, no mangling needed.

#else

// CLI may get already defined if `vtk_cli11.h` was included,
// hence this check to avoid redefinition.
#if !defined(CLI)
// mangle the namespace.
#define CLI VTK_CLI
#endif // !defined(CLI)

#endif // VTK_MODULE_USE_EXTERNAL_VTK_cli11

#endif
