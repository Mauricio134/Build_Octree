// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkPolyData2DVS.h"

const char *vtkPolyData2DVS =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"\n"
"// all variables that represent positions or directions have a suffix\n"
"// indicating the coordinate system they are in. The possible values are\n"
"// MC - Model Coordinates\n"
"// WC - WC world coordinates\n"
"// VC - View Coordinates\n"
"// DC - Display Coordinates\n"
"\n"
"in vec4 vertexWC;\n"
"\n"
"// material property values\n"
"//VTK::Color::Dec\n"
"\n"
"// Texture coordinates\n"
"//VTK::TCoord::Dec\n"
"\n"
"// Apple Bug\n"
"//VTK::PrimID::Dec\n"
"\n"
"// PointSize on GLES 3.0\n"
"//VTK::PointSizeGLES30::Dec\n"
"\n"
"// LineWidth on GLES 3.0\n"
"//VTK::LineWidthGLES30::Dec\n"
"\n"
"uniform mat4 WCVCMatrix;  // World to view matrix\n"
"\n"
"void main()\n"
"{\n"
"  //VTK::PointSizeGLES30::Impl\n"
"\n"
"  // Apple Bug\n"
"  //VTK::PrimID::Impl\n"
"\n"
"  gl_Position = WCVCMatrix*vertexWC;\n"
"  //VTK::LineWidthGLES30::Impl\n"
"  //VTK::TCoord::Impl\n"
"  //VTK::Color::Impl\n"
"}\n"
"";