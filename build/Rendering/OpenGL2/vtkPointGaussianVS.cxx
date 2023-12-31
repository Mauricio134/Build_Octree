// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkPointGaussianVS.h"

const char *vtkPointGaussianVS =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"// this shader implements imposters in OpenGL for Spheres\n"
"\n"
"in vec4 vertexMC;\n"
"in float radiusMC;\n"
"out float radiusVCVSOutput;\n"
"\n"
"// optional normal declaration\n"
"//VTK::Normal::Dec\n"
"\n"
"// Texture coordinates\n"
"//VTK::TCoord::Dec\n"
"\n"
"// material property values\n"
"//VTK::Color::Dec\n"
"\n"
"// clipping plane vars\n"
"//VTK::Clip::Dec\n"
"\n"
"// camera and actor matrix values\n"
"//VTK::Camera::Dec\n"
"\n"
"// picking support\n"
"//VTK::Picking::Dec\n"
"\n"
"void main()\n"
"{\n"
"  //VTK::Color::Impl\n"
"\n"
"  //VTK::Normal::Impl\n"
"\n"
"  //VTK::TCoord::Impl\n"
"\n"
"  //VTK::Clip::Impl\n"
"\n"
"  radiusVCVSOutput = radiusMC;\n"
"\n"
"  gl_Position = MCVCMatrix * vertexMC;\n"
"\n"
"  //VTK::Picking::Impl\n"
"}\n"
"";
