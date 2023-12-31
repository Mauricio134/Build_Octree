// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#ifndef vtkWrapPythonConstant_h
#define vtkWrapPythonConstant_h

#include "vtkParse.h"
#include "vtkParseData.h"
#include "vtkParseHierarchy.h"

/* generate code that adds a constant value to a python dict */
void vtkWrapPython_AddConstant(FILE* fp, const char* indent, const char* dictvar,
  const char* objvar, const char* scope, ValueInfo* val);

/* generate code that adds all public constants in a namespace */
void vtkWrapPython_AddPublicConstants(
  FILE* fp, const char* indent, const char* dictvar, const char* objvar, NamespaceInfo* data);

#endif /* vtkWrapPythonConstant_h */
/* VTK-HeaderTest-Exclude: vtkWrapPythonConstant.h */
