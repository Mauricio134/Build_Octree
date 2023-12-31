// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkGlyphSource2D
 * @brief   create 2D glyphs represented by vtkPolyData
 *
 * vtkGlyphSource2D can generate a family of 2D glyphs each of which lies
 * in the x-y plane (i.e., the z-coordinate is zero). The class is a helper
 * class to be used with vtkGlyph2D and vtkXYPlotActor.
 *
 * To use this class, specify the glyph type to use and its
 * attributes. Attributes include its position (i.e., center point), scale,
 * color, and whether the symbol is filled or not (a polygon or closed line
 * sequence). You can also put a short line through the glyph running from -x
 * to +x (the glyph looks like it's on a line), or a cross.
 *
 * The simple arrow can also be double pointed and point inwards.
 */

#ifndef vtkGlyphSource2D_h
#define vtkGlyphSource2D_h

#include "vtkFiltersSourcesModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

#define VTK_NO_GLYPH 0
#define VTK_VERTEX_GLYPH 1
#define VTK_DASH_GLYPH 2
#define VTK_CROSS_GLYPH 3
#define VTK_THICKCROSS_GLYPH 4
#define VTK_TRIANGLE_GLYPH 5
#define VTK_SQUARE_GLYPH 6
#define VTK_CIRCLE_GLYPH 7
#define VTK_DIAMOND_GLYPH 8
#define VTK_ARROW_GLYPH 9
#define VTK_THICKARROW_GLYPH 10
#define VTK_HOOKEDARROW_GLYPH 11
#define VTK_EDGEARROW_GLYPH 12

#define VTK_MAX_CIRCLE_RESOLUTION 1024

VTK_ABI_NAMESPACE_BEGIN
class vtkPoints;
class vtkUnsignedCharArray;
class vtkCellArray;

class VTKFILTERSSOURCES_EXPORT vtkGlyphSource2D : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkGlyphSource2D, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct a vertex glyph centered at the origin, scale 1.0, white in
   * color, filled, with line segment passing through the point.
   */
  static vtkGlyphSource2D* New();

  ///@{
  /**
   * Set the center of the glyph. By default the center is (0,0,0).
   */
  vtkSetVector3Macro(Center, double);
  vtkGetVectorMacro(Center, double, 3);
  ///@}

  ///@{
  /**
   * Set the scale of the glyph. Note that the glyphs are designed
   * to fit in the (1,1) rectangle.
   */
  vtkSetClampMacro(Scale, double, 0.0, VTK_DOUBLE_MAX);
  vtkGetMacro(Scale, double);
  ///@}

  ///@{
  /**
   * Set the scale of optional portions of the glyph (e.g., the
   * dash and cross is DashOn() and CrossOn()).
   */
  vtkSetClampMacro(Scale2, double, 0.0, VTK_DOUBLE_MAX);
  vtkGetMacro(Scale2, double);
  ///@}

  ///@{
  /**
   * Set the color of the glyph. The default color is white.
   */
  vtkSetVector3Macro(Color, double);
  vtkGetVectorMacro(Color, double, 3);
  ///@}

  ///@{
  /**
   * Specify whether the glyph is filled (a polygon) or not (a
   * closed polygon defined by line segments). This only applies
   * to 2D closed glyphs.
   */
  vtkSetMacro(Filled, vtkTypeBool);
  vtkGetMacro(Filled, vtkTypeBool);
  vtkBooleanMacro(Filled, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Specify whether a short line segment is drawn through the
   * glyph. (This is in addition to the glyph. If the glyph type
   * is set to "Dash" there is no need to enable this flag.)
   */
  vtkSetMacro(Dash, vtkTypeBool);
  vtkGetMacro(Dash, vtkTypeBool);
  vtkBooleanMacro(Dash, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Specify whether a cross is drawn as part of the glyph. (This
   * is in addition to the glyph. If the glyph type is set to
   * "Cross" there is no need to enable this flag.)
   */
  vtkSetMacro(Cross, vtkTypeBool);
  vtkGetMacro(Cross, vtkTypeBool);
  vtkBooleanMacro(Cross, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Specify an angle (in degrees) to rotate the glyph around
   * the z-axis. Using this ivar, it is possible to generate
   * rotated glyphs (e.g., crosses, arrows, etc.)
   */
  vtkSetMacro(RotationAngle, double);
  vtkGetMacro(RotationAngle, double);
  ///@}

  ///@{
  /**
   * Specify the number of points that form the circular glyph.
   */
  vtkSetClampMacro(Resolution, int, 3, VTK_MAX_CIRCLE_RESOLUTION);
  vtkGetMacro(Resolution, int);
  ///@}

  ///@{
  /**
   * Specify the type of glyph to generate.
   */
  vtkSetClampMacro(GlyphType, int, VTK_NO_GLYPH, VTK_EDGEARROW_GLYPH);
  vtkGetMacro(GlyphType, int);
  void SetGlyphTypeToNone() { this->SetGlyphType(VTK_NO_GLYPH); }
  void SetGlyphTypeToVertex() { this->SetGlyphType(VTK_VERTEX_GLYPH); }
  void SetGlyphTypeToDash() { this->SetGlyphType(VTK_DASH_GLYPH); }
  void SetGlyphTypeToCross() { this->SetGlyphType(VTK_CROSS_GLYPH); }
  void SetGlyphTypeToThickCross() { this->SetGlyphType(VTK_THICKCROSS_GLYPH); }
  void SetGlyphTypeToTriangle() { this->SetGlyphType(VTK_TRIANGLE_GLYPH); }
  void SetGlyphTypeToSquare() { this->SetGlyphType(VTK_SQUARE_GLYPH); }
  void SetGlyphTypeToCircle() { this->SetGlyphType(VTK_CIRCLE_GLYPH); }
  void SetGlyphTypeToDiamond() { this->SetGlyphType(VTK_DIAMOND_GLYPH); }
  void SetGlyphTypeToArrow() { this->SetGlyphType(VTK_ARROW_GLYPH); }
  void SetGlyphTypeToThickArrow() { this->SetGlyphType(VTK_THICKARROW_GLYPH); }
  void SetGlyphTypeToHookedArrow() { this->SetGlyphType(VTK_HOOKEDARROW_GLYPH); }
  void SetGlyphTypeToEdgeArrow() { this->SetGlyphType(VTK_EDGEARROW_GLYPH); }
  ///@}

  ///@{
  /**
   * Set/get the desired precision for the output points.
   * vtkAlgorithm::SINGLE_PRECISION - Output single-precision floating point.
   * vtkAlgorithm::DOUBLE_PRECISION - Output double-precision floating point.
   */
  vtkSetMacro(OutputPointsPrecision, int);
  vtkGetMacro(OutputPointsPrecision, int);
  ///@}

  ///@{
  /**
   * Set/get the length of the tip(s) for VTK_ARROW_GLYPH.
   * If DoublePointed is on, the length is capped at 0.5.
   * Default is 0.3.
   */
  vtkSetClampMacro(TipLength, double, 0.0, 1.0);
  vtkGetMacro(TipLength, double);
  ///@}

  ///@{
  /**
   * Specify whether the arrow glyph should have two opposite tips.
   * Only applicable for VTK_ARROW_GLYPH.
   * Default is false.
   */
  vtkSetMacro(DoublePointed, bool);
  vtkGetMacro(DoublePointed, bool);
  vtkBooleanMacro(DoublePointed, bool);
  ///@}

  ///@{
  /**
   * Specify whether the arrow glyph should have its tip(s) pointing inwards.
   * Only applicable for VTK_ARROW_GLYPH.
   * Default is false.
   */
  vtkSetMacro(PointInwards, bool);
  vtkGetMacro(PointInwards, bool);
  vtkBooleanMacro(PointInwards, bool);
  ///@}

protected:
  vtkGlyphSource2D();
  ~vtkGlyphSource2D() override = default;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  double Center[3] = { 0.0, 0.0, 0.0 };
  double Scale = 1.0;
  double Scale2 = 1.5;
  double Color[3] = { 1.0, 1.0, 1.0 };
  vtkTypeBool Filled = true;
  vtkTypeBool Dash = false;
  vtkTypeBool Cross = false;
  int GlyphType = VTK_VERTEX_GLYPH;
  double RotationAngle = 0.0;
  int Resolution = 8;
  int OutputPointsPrecision = SINGLE_PRECISION;
  double TipLength = 0.3;
  bool DoublePointed = false;
  bool PointInwards = false;

  void TransformGlyph(vtkPoints* pts);
  void ConvertColor();
  unsigned char RGB[3];

  void CreateVertex(vtkPoints* pts, vtkCellArray* verts, vtkUnsignedCharArray* colors);
  void CreateDash(vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys,
    vtkUnsignedCharArray* colors, double scale);
  void CreateCross(vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys,
    vtkUnsignedCharArray* colors, double scale);
  void CreateThickCross(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateTriangle(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateSquare(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateCircle(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateDiamond(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateArrow(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateThickArrow(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateHookedArrow(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);
  void CreateEdgeArrow(
    vtkPoints* pts, vtkCellArray* lines, vtkCellArray* polys, vtkUnsignedCharArray* colors);

private:
  vtkGlyphSource2D(const vtkGlyphSource2D&) = delete;
  void operator=(const vtkGlyphSource2D&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
