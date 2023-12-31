// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkCellGridGS_DGHex.h"

const char *vtkCellGridGS_DGHex =
"//VTK::System::Dec\n"
"\n"
"// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"// SPDX-License-Identifier: BSD-3-Clause\n"
"// Template for the cellgrid mapper geometry shader\n"
"\n"
"// look up cell points, types and vertex positions from texture buffers.\n"
"uniform isamplerBuffer cellConnectivity;\n"
"uniform isamplerBuffer sideConnectivity;\n"
"uniform isamplerBuffer faceConnectivity;\n"
"uniform samplerBuffer cellParametrics;\n"
"uniform samplerBuffer vertexPositions;\n"
"\n"
"// vtkActor may be given custom uniforms.\n"
"//VTK::CustomUniforms::Dec\n"
"\n"
"// camera and actor matrix values\n"
"//VTK::Camera::Dec\n"
"\n"
"// Position of vertex in view coordinates.\n"
"//VTK::PositionVC::Dec\n"
"\n"
"// Color output per vertex in the rendered primitives.\n"
"//VTK::Color::Dec\n"
"\n"
"// The normal of the output primitive in view coordinates.\n"
"//VTK::Normal::Dec\n"
"\n"
"layout(points) in;\n"
"layout(triangle_strip, max_vertices = 6) out; // TODO: use string substitution for this\n"
"\n"
"// Input from vertex shader\n"
"in int vtkCellSideId[]; // size 1\n"
"\n"
"// send cell ID to fragment shader\n"
"flat out int vtkCellIdGSOutput;\n"
"\n"
"// Custom output for fragment shader\n"
"out vec3 pCoordGSOutput;\n"
"\n"
"//----------------------------------------------------------------\n"
"vec3 ComputeNormal(in vec3 p1, in vec3 p2, in vec3 p3)\n"
"{\n"
"  vec3 delta32 = p3 - p2;\n"
"  vec3 delta12 = p1 - p2;\n"
"  return cross(delta32, delta12);\n"
"}\n"
"\n"
"//----------------------------------------------------------------\n"
"/**\n"
" * Draws triangle strips for the sideId'th face of a linear hexahedron.\n"
" * sideId - index of the face which will be rendered as two triangles - [0, 5]\n"
" * cellId - index of the vtk cell whose faces we shall render - [0, numCells]\n"
" */\n"
"void DrawHexFace(in int sideId, in int cellId)\n"
"{\n"
"  // split each face into two triangles.\n"
"  // 0----3   0          0---3\n"
"  // |    |   | \\         \\  |\n"
"  // |    | ->|  \\    +    \\ |\n"
"  // |    |   |   \\         \\|\n"
"  // 1----2   1----2         2\n"
"  ivec3 triPtIds[2];\n"
"  triPtIds[0] = ivec3(0, 1, 2);\n"
"  triPtIds[1] = ivec3(0, 2, 3);\n"
"\n"
"  int cellLocalPtIds[4], cellGlobalPtIds[4];\n"
"  vec3 coords[4];\n"
"  for (int i = 0; i < 4; ++i)\n"
"  {\n"
"    cellLocalPtIds[i] = texelFetch(faceConnectivity, sideId * 4 + i).r;\n"
"    cellGlobalPtIds[i] = texelFetch(cellConnectivity, cellId * 8 + cellLocalPtIds[i]).r;\n"
"    coords[i] = texelFetch(vertexPositions, cellGlobalPtIds[i]).xyz;\n"
"  }\n"
"\n"
"  vec3 n = ComputeNormal(coords[0], coords[1], coords[2]);\n"
"  if (length(n) == 0.0)\n"
"  {\n"
"    n = ComputeNormal(coords[1], coords[2], coords[3]);\n"
"  }\n"
"  if (length(n) == 0.0)\n"
"  {\n"
"    n.z = 1.0f;\n"
"  }\n"
"\n"
"  //VTK::Normal::Impl\n"
"\n"
"  for (int triId = 0; triId < 2; ++triId)\n"
"  {\n"
"    for (int i = 0; i < 3; ++i)\n"
"    {\n"
"      int triPtId = triPtIds[triId][i];\n"
"      int localPtId = cellLocalPtIds[triPtId];\n"
"      int globalPtId = cellGlobalPtIds[triPtId];\n"
"\n"
"      vec4 vertexMC = vec4(texelFetch(vertexPositions, globalPtId).xyz, 1.0f);\n"
"\n"
"      //VTK::PositionVC::Impl\n"
"\n"
"      //VTK::Color::Impl\n"
"\n"
"      pCoordGSOutput = texelFetch(cellParametrics, localPtId).xyz;\n"
"      EmitVertex();\n"
"    }\n"
"    EndPrimitive();\n"
"  }\n"
"}\n"
"\n"
"//----------------------------------------------------------------\n"
"void main()\n"
"{\n"
"  int cellId = texelFetch(sideConnectivity, 2 * vtkCellSideId[0]).r;\n"
"  int sideId = texelFetch(sideConnectivity, 2 * vtkCellSideId[0] + 1).r;\n"
"  vtkCellIdGSOutput = cellId;\n"
"  DrawHexFace(sideId, cellId);\n"
"}\n"
"";
