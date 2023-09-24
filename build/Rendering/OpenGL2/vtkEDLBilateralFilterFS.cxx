// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkEDLBilateralFilterFS.h"

const char *vtkEDLBilateralFilterFS =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-FileCopyrightText: Copyright (c) Sandia Corporation, Kitware Inc\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"/*----------------------------------------------------------------------\n"
"Acknowledgement:\n"
"This algorithm is the result of joint work by Electricité de France,\n"
"CNRS, Collège de France and Université J. Fourier as part of the\n"
"Ph.D. thesis of Christian BOUCHENY.\n"
"------------------------------------------------------------------------*/\n"
"//////////////////////////////////////////////////////////////////////////\n"
"//\n"
"//\n"
"//  Bilateral filtering\n"
"//\n"
"//  C.B. - 16 aout 2008\n"
"//\n"
"//    IN:\n"
"//      s2_I - Image to blur\n"
"//      s2_D - Modulating depth image\n"
"//\n"
"//    OUT:\n"
"//      Filtered image\n"
"//\n"
"//////////////////////////////////////////////////////////////////////////\n"
"\n"
"// the output of this shader\n"
"//VTK::Output::Dec\n"
"\n"
"in vec2 tcoordVC;\n"
"\n"
"/****************************************************/\n"
"uniform sampler2D   s2_I;\n"
"uniform sampler2D   s2_D;\n"
"uniform float       SX;\n"
"uniform float       SY;\n"
"uniform int         N;\n"
"// filter size (full width, necessarily odd, like 3, 5...)\n"
"uniform float       sigma;\n"
"/****************************************************/\n"
"\n"
"/****************************************************/\n"
"vec3    C;\n"
"float   z;\n"
"float   sigmaz = 0.005;\n"
"/****************************************************/\n"
"\n"
"void main (void)\n"
"{\n"
"  C = texture2D(s2_I, tcoordVC.st).rgb;\n"
"  z = texture2D(s2_D, tcoordVC.st).r;\n"
"\n"
"  float ALL = 0.;       // sum of all weights\n"
"  vec3  RES = vec3(0.); // sum of all contributions\n"
"  int   hN  = N/2;      // filter half width\n"
"  vec2  coordi = vec2(0.,0.);\n"
"  vec3  Ci;\n"
"  float zi;\n"
"  float dist;\n"
"  float dz;\n"
"  float Fi,Gi;\n"
"\n"
"  int   c,d;\n"
"  for(c=-hN;c<hN+1;c++)\n"
"  {\n"
"    for(d=-hN;d<hN+1;d++)\n"
"    {\n"
"    coordi = vec2(float(c)*SX,float(d)*SY);\n"
"    Ci = texture2D(s2_I, tcoordVC.st+coordi).rgb;\n"
"    zi = texture2D(s2_D, tcoordVC.st+coordi).r;\n"
"\n"
"    dist = clamp( float(c*c+d*d)/float(hN*hN) , 0., 1. );\n"
"    dz   = (z-zi)*(z-zi);\n"
"\n"
"    Fi = exp(-dist*dist/(2.* sigma*sigma));\n"
"    Gi = exp(-dz*dz/(2.* sigmaz*sigmaz));\n"
"\n"
"    RES += Ci * Fi * Gi;\n"
"    ALL += Fi * Gi;\n"
"    }\n"
"  }\n"
"  RES /= ALL;\n"
"\n"
"  gl_FragData[0] = vec4( RES , z );\n"
"}\n"
"";
