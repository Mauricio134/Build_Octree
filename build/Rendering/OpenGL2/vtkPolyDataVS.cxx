// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkPolyDataVS.h"

const char *vtkPolyDataVS =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"\n"
"in vec4 vertexMC;\n"
"\n"
"//VTK::CustomUniforms::Dec\n"
"\n"
"// frag position in VC\n"
"//VTK::PositionVC::Dec\n"
"\n"
"// optional normal declaration\n"
"//VTK::Normal::Dec\n"
"\n"
"// extra lighting parameters\n"
"//VTK::Light::Dec\n"
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
"// Apple Bug\n"
"//VTK::PrimID::Dec\n"
"\n"
"// Value raster\n"
"//VTK::ValuePass::Dec\n"
"\n"
"// picking support\n"
"//VTK::Picking::Dec\n"
"\n"
"// Surface with edges on GLES 3.0\n"
"//VTK::EdgesGLES30::Dec\n"
"\n"
"// PointSize on GLES 3.0\n"
"//VTK::PointSizeGLES30::Dec\n"
"\n"
"// LineWidth on GLES 3.0\n"
"//VTK::LineWidthGLES30::Dec\n"
"\n"
"void main()\n"
"{\n"
"  //VTK::PointSizeGLES30::Impl\n"
"\n"
"  //VTK::CustomBegin::Impl\n"
"\n"
"  //VTK::Color::Impl\n"
"\n"
"  //VTK::Normal::Impl\n"
"\n"
"  //VTK::TCoord::Impl\n"
"\n"
"  //VTK::Clip::Impl\n"
"\n"
"  //VTK::PrimID::Impl\n"
"\n"
"  //VTK::PositionVC::Impl\n"
"\n"
"  //VTK::LineWidthGLES30::Impl\n"
"\n"
"  //VTK::ValuePass::Impl\n"
"\n"
"  //VTK::Light::Impl\n"
"\n"
"  //VTK::Picking::Impl\n"
"\n"
"  //VTK::CustomEnd::Impl\n"
"\n"
"  //VTK::EdgesGLES30::Impl\n"
"}\n"
"";