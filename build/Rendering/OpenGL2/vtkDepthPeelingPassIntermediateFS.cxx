// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDepthPeelingPassIntermediateFS.h"

const char *vtkDepthPeelingPassIntermediateFS =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"\n"
"in vec2 texCoord;\n"
"uniform sampler2D translucentRGBATexture;\n"
"uniform sampler2D currentRGBATexture;\n"
"\n"
"uniform int lastpass;\n"
"\n"
"// the output of this shader\n"
"//VTK::Output::Dec\n"
"\n"
"void main()\n"
"{\n"
"  // current is what is most recently rendered\n"
"  // translucent is what is in FRONT of it\n"
"  // we render front to back\n"
"  vec4 t1Color = texture2D(translucentRGBATexture, texCoord);\n"
"  vec4 t2Color = texture2D(currentRGBATexture, texCoord);\n"
"  gl_FragData[0].a = t1Color.a + t2Color.a * (1.0-t1Color.a);\n"
"  if (gl_FragData[0].a > 0.0)\n"
"    {\n"
"    if (lastpass == 1)\n"
"      {\n"
"      gl_FragData[0].rgb = (t1Color.rgb*t1Color.a + t2Color.rgb*(1.0-t1Color.a))/gl_FragData[0].a;\n"
"      }\n"
"    else\n"
"      {\n"
"      gl_FragData[0].rgb = (t1Color.rgb*t1Color.a + t2Color.rgb*t2Color.a*(1.0-t1Color.a))/gl_FragData[0].a;\n"
"      }\n"
"    }\n"
"  else\n"
"    {\n"
"    gl_FragData[0].rgb = vec3(0.0,0.0,0.0);\n"
"    }\n"
"}\n"
"";
