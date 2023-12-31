// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtk_hdf5_h
#define vtk_hdf5_h

/* Use the hdf5 library configured for VTK.  */
#define VTK_MODULE_USE_EXTERNAL_vtkhdf5 0

#define H5_USE_110_API

#if VTK_MODULE_USE_EXTERNAL_vtkhdf5
#define vtkhdf5_is_parallel 0
#if vtkhdf5_is_parallel
#include <vtk_mpi.h>
#endif
#undef vtkhdf5_is_parallel

# include <hdf5.h>
# include <hdf5_hl.h>
#else
# include <vtkhdf5/src/hdf5.h>
# include <vtkhdf5/hl/src/hdf5_hl.h>
#endif

#endif
