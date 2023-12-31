// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkWebGLDataSet
 * @brief   vtkWebGLDataSet represent vertices, lines, polygons, and triangles.
 */

#ifndef vtkWebGLDataSet_h
#define vtkWebGLDataSet_h

#include "vtkObject.h"
#include "vtkWebGLExporterModule.h" // needed for export macro

#include "vtkWebGLObject.h" // Needed for the enum
#include <string>           // needed for md5

VTK_ABI_NAMESPACE_BEGIN
class VTKWEBGLEXPORTER_EXPORT vtkWebGLDataSet : public vtkObject
{
public:
  static vtkWebGLDataSet* New();
  vtkTypeMacro(vtkWebGLDataSet, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  void SetVertices(float* v, int size);
  void SetIndexes(short* i, int size);
  void SetNormals(float* n);
  void SetColors(unsigned char* c);
  void SetPoints(float* p, int size);
  void SetTCoords(float* t);
  void SetMatrix(float* m);
  void SetType(WebGLObjectTypes t);

  unsigned char* GetBinaryData();
  int GetBinarySize();
  void GenerateBinaryData();
  bool HasChanged();

  std::string GetMD5();

protected:
  vtkWebGLDataSet();
  ~vtkWebGLDataSet() override;

  int NumberOfVertices;
  int NumberOfPoints;
  int NumberOfIndexes;
  WebGLObjectTypes webGLType;

  float* Matrix;
  float* vertices;
  float* normals;
  short* indexes;
  float* points;
  float* tcoords;
  unsigned char* colors;
  unsigned char* binary; // Data in binary
  int binarySize;        // Size of the data in binary
  bool hasChanged;
  std::string MD5;

private:
  vtkWebGLDataSet(const vtkWebGLDataSet&) = delete;
  void operator=(const vtkWebGLDataSet&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
