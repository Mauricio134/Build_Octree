// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkQtTreeRingLabelMapper
 * @brief   draw text labels on a tree map
 *
 *
 * vtkQtTreeRingLabelMapper is a mapper that renders text on a tree map.
 * A tree map is a vtkTree with an associated 4-tuple array
 * used for storing the boundary rectangle for each vertex in the tree.
 * The user must specify the array name used for storing the rectangles.
 *
 * The mapper iterates through the tree and attempts and renders a label
 * inside the vertex's rectangle as long as the following conditions hold:
 * 1. The vertex level is within the range of levels specified for labeling.
 * 2. The label can fully fit inside its box.
 * 3. The label does not overlap an ancestor's label.
 *
 * @sa
 * vtkLabeledDataMapper
 *
 * @par Thanks:
 * Thanks to Jason Shepherd from
 * Sandia National Laboratories for help in developing this class.
 */

#ifndef vtkQtTreeRingLabelMapper_h
#define vtkQtTreeRingLabelMapper_h

#include "vtkLabeledDataMapper.h"
#include "vtkRenderingQtModule.h" // For export macro

class QImage;

VTK_ABI_NAMESPACE_BEGIN

class vtkQImageToImageSource;
class vtkCoordinate;
class vtkDoubleArray;
class vtkPlaneSource;
class vtkPolyDataMapper2D;
class vtkRenderer;
class vtkStringArray;
class vtkTexture;
class vtkTextureMapToPlane;
class vtkTree;

class VTKRENDERINGQT_EXPORT vtkQtTreeRingLabelMapper : public vtkLabeledDataMapper
{
public:
  static vtkQtTreeRingLabelMapper* New();
  vtkTypeMacro(vtkQtTreeRingLabelMapper, vtkLabeledDataMapper);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Draw the text to the screen at each input point.
   */
  void RenderOpaqueGeometry(vtkViewport* viewport, vtkActor2D* actor) override;
  void RenderOverlay(vtkViewport* viewport, vtkActor2D* actor) override;
  ///@}

  /**
   * The input to this filter.
   */
  virtual vtkTree* GetInputTree();

  /**
   * The name of the 4-tuple array used for
   */
  virtual void SetSectorsArrayName(const char* name);

  ///@{
  /**
   * Set/Get the text property. Note that multiple type text properties
   * (set with a second integer parameter) are not currently supported,
   * but are provided to avoid compiler warnings.
   */
  void SetLabelTextProperty(vtkTextProperty* p) override;
  vtkTextProperty* GetLabelTextProperty() override { return this->LabelTextProperty; }
  void SetLabelTextProperty(vtkTextProperty* p, int type) override
  {
    this->Superclass::SetLabelTextProperty(p, type);
  }
  vtkTextProperty* GetLabelTextProperty(int type) override
  {
    return this->Superclass::GetLabelTextProperty(type);
  }
  ///@}

  ///@{
  /**
   * Set/Get the name of the text rotation array.
   */
  vtkSetStringMacro(TextRotationArrayName);
  vtkGetStringMacro(TextRotationArrayName);
  ///@}

  /**
   * Return the object's MTime. This is overridden to include
   * the timestamp of its internal class.
   */
  vtkMTimeType GetMTime() override;

  void SetRenderer(vtkRenderer* ren)
  {
    if (this->Renderer != ren)
    {
      this->Renderer = ren;
      this->Modified();
    }
  }
  vtkRenderer* GetRenderer() { return this->Renderer; }

protected:
  vtkQtTreeRingLabelMapper();
  ~vtkQtTreeRingLabelMapper() override;
  void LabelTree(vtkTree* tree, vtkDataArray* sectorInfo, vtkDataArray* numericData,
    vtkStringArray* stringData, int activeComp, int numComps, vtkViewport* viewport);
  void GetVertexLabel(vtkIdType vertex, vtkDataArray* numericData, vtkStringArray* stringData,
    int activeComp, int numComps, char* string, size_t stringSize);

  // Returns true if the center of the sector is in the window
  // along with the pixel dimensions (width, height)  of the sector
  bool PointInWindow(double* sinfo, double* newDim, double* textPosDC, vtkViewport* viewport);

  vtkViewport* CurrentViewPort;
  vtkCoordinate* VCoord;
  vtkQImageToImageSource* QtImageSource;
  vtkPlaneSource* PlaneSource;
  vtkRenderer* Renderer;
  vtkTextProperty* LabelTextProperty;
  vtkTexture* LabelTexture;
  vtkTextureMapToPlane* TextureMapToPlane;
  char* TextRotationArrayName;
  vtkPolyDataMapper2D* polyDataMapper;
  QImage* QtImage;
  int WindowSize[2];

private:
  vtkQtTreeRingLabelMapper(const vtkQtTreeRingLabelMapper&) = delete;
  void operator=(const vtkQtTreeRingLabelMapper&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
