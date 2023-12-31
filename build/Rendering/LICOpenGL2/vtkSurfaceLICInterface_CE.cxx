// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkSurfaceLICInterface_CE.h"

const char *vtkSurfaceLICInterface_CE =
"//VTK::System::Dec\n"
"\n"
"\n"
"// color contrast enhance stage implemented via histogram stretching\n"
"// on lightness channel. if the min and max are tweaked it can generate\n"
"// out-of-range values these will be clamped in 0 to 1\n"
"\n"
"// the output of this shader\n"
"//VTK::Output::Dec\n"
"\n"
"uniform sampler2D texGeomColors; // scalars + lighting\n"
"uniform sampler2D texLIC;        // image lic, mask\n"
"uniform sampler2D texHSLColors;  // hsla colors\n"
"\n"
"uniform float     uLMin;         // min lightness over all fragments\n"
"uniform float     uLMaxMinDiff;  // max - min lightness over all fragments\n"
"\n"
"in vec2 tcoordVC;\n"
"\n"
"vec3 HSLToRGB(vec3 HSL)\n"
"{\n"
"  vec3 RGB;\n"
"  float v;\n"
"  float h = HSL.x;\n"
"  float sl = HSL.y;\n"
"  float l = HSL.z;\n"
"\n"
"  v = (l <= 0.5) ? (l * (1.0 + sl)) : (l + sl - l * sl);\n"
"  if (v <= 0) {\n"
"    RGB = vec3(0.0,0.0,0.0);\n"
"  } else {\n"
"    float m;\n"
"    int sextant;\n"
"    float fract, vsf, mid1, mid2;\n"
"\n"
"    m = l + l - v;\n"
"    h *= 6.0;\n"
"    sextant = int(h);\n"
"    fract = h - sextant;\n"
"\n"
"    vsf = (v - m) * fract;\n"
"    mid1 = m + vsf;\n"
"    mid2 = v - vsf;\n"
"    switch (sextant) {\n"
"      case 0: RGB.r = v; RGB.g = mid1; RGB.b = m; break;\n"
"      case 1: RGB.r = mid2; RGB.g = v; RGB.b = m; break;\n"
"      case 2: RGB.r = m; RGB.g = v; RGB.b = mid1; break;\n"
"      case 3: RGB.r = m; RGB.g = mid2; RGB.b = v; break;\n"
"      case 4: RGB.r = mid1; RGB.g = m; RGB.b = v; break;\n"
"      case 5: RGB.r = v; RGB.g = m; RGB.b = mid2; break;\n"
"    }\n"
"  }\n"
"  return RGB;\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"  // lookup hsl color , mask\n"
"  vec4 fragColor = texture2D(texHSLColors, tcoordVC.st);\n"
"\n"
"  // don't modify masked fragments (masked => lic.g==1)\n"
"  vec4 lic = texture2D(texLIC, tcoordVC.st);\n"
"  if (lic.g==0.0)\n"
"    {\n"
"    // normalize lightness channel\n"
"    fragColor.z = clamp((fragColor.z - uLMin)/uLMaxMinDiff, 0.0, 1.0);\n"
"    }\n"
"\n"
"  // back into rgb space\n"
"  fragColor.rgb = HSLToRGB(fragColor.xyz);\n"
"\n"
"  // add alpha\n"
"  vec4 geomColor = texture2D(texGeomColors, tcoordVC.st);\n"
"  fragColor.a = geomColor.a;\n"
"\n"
"  gl_FragData[0] = fragColor;\n"
"}\n"
"";
