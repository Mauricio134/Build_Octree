#!/usr/bin/env python
from vtkmodules.vtkCommonCore import (
    vtkFloatArray,
    vtkPoints,
)
from vtkmodules.vtkCommonDataModel import (
    vtkHexagonalPrism,
    vtkHexahedron,
    vtkLine,
    vtkPentagonalPrism,
    vtkPixel,
    vtkPolyLine,
    vtkPolyVertex,
    vtkPolygon,
    vtkPyramid,
    vtkQuad,
    vtkTetra,
    vtkTriangle,
    vtkTriangleStrip,
    vtkUnstructuredGrid,
    vtkVertex,
    vtkVoxel,
    vtkWedge,
)
from vtkmodules.vtkFiltersCore import (
    vtkCellCenters,
    vtkGlyph3D,
    vtkHedgeHog,
)
from vtkmodules.vtkFiltersGeneral import vtkCellDerivatives
from vtkmodules.vtkFiltersSources import vtkSphereSource
from vtkmodules.vtkRenderingCore import (
    vtkActor,
    vtkDataSetMapper,
    vtkPolyDataMapper,
    vtkRenderWindow,
    vtkRenderWindowInteractor,
    vtkRenderer,
)
import vtkmodules.vtkInteractionStyle
import vtkmodules.vtkRenderingFreeType
import vtkmodules.vtkRenderingOpenGL2
from vtkmodules.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

# Demonstrates vtkCellDerivatives for all cell types
#
ren1 = vtkRenderer()
renWin = vtkRenderWindow()
renWin.AddRenderer(ren1)
iren = vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)

# create a scene with one of each cell type
# Voxel
voxelPoints = vtkPoints()
voxelPoints.SetNumberOfPoints(8)
voxelPoints.InsertPoint(0, 0, 0, 0)
voxelPoints.InsertPoint(1, 1, 0, 0)
voxelPoints.InsertPoint(2, 0, 1, 0)
voxelPoints.InsertPoint(3, 1, 1, 0)
voxelPoints.InsertPoint(4, 0, 0, 1)
voxelPoints.InsertPoint(5, 1, 0, 1)
voxelPoints.InsertPoint(6, 0, 1, 1)
voxelPoints.InsertPoint(7, 1, 1, 1)

aVoxel = vtkVoxel()
aVoxel.GetPointIds().SetId(0, 0)
aVoxel.GetPointIds().SetId(1, 1)
aVoxel.GetPointIds().SetId(2, 2)
aVoxel.GetPointIds().SetId(3, 3)
aVoxel.GetPointIds().SetId(4, 4)
aVoxel.GetPointIds().SetId(5, 5)
aVoxel.GetPointIds().SetId(6, 6)
aVoxel.GetPointIds().SetId(7, 7)

aVoxelGrid = vtkUnstructuredGrid()
aVoxelGrid.Allocate(1, 1)
aVoxelGrid.InsertNextCell(aVoxel.GetCellType(), aVoxel.GetPointIds())
aVoxelGrid.SetPoints(voxelPoints)

aVoxelMapper = vtkDataSetMapper()
aVoxelMapper.SetInputData(aVoxelGrid)

aVoxelActor = vtkActor()
aVoxelActor.SetMapper(aVoxelMapper)
aVoxelActor.GetProperty().BackfaceCullingOn()

# Hexahedron
hexahedronPoints = vtkPoints()
hexahedronPoints.SetNumberOfPoints(8)
hexahedronPoints.InsertPoint(0, 0, 0, 0)
hexahedronPoints.InsertPoint(1, 1, 0, 0)
hexahedronPoints.InsertPoint(2, 1, 1, 0)
hexahedronPoints.InsertPoint(3, 0, 1, 0)
hexahedronPoints.InsertPoint(4, 0, 0, 1)
hexahedronPoints.InsertPoint(5, 1, 0, 1)
hexahedronPoints.InsertPoint(6, 1, 1, 1)
hexahedronPoints.InsertPoint(7, 0, 1, 1)

aHexahedron = vtkHexahedron()
aHexahedron.GetPointIds().SetId(0, 0)
aHexahedron.GetPointIds().SetId(1, 1)
aHexahedron.GetPointIds().SetId(2, 2)
aHexahedron.GetPointIds().SetId(3, 3)
aHexahedron.GetPointIds().SetId(4, 4)
aHexahedron.GetPointIds().SetId(5, 5)
aHexahedron.GetPointIds().SetId(6, 6)
aHexahedron.GetPointIds().SetId(7, 7)

aHexahedronGrid = vtkUnstructuredGrid()
aHexahedronGrid.Allocate(1, 1)
aHexahedronGrid.InsertNextCell(aHexahedron.GetCellType(), aHexahedron.GetPointIds())
aHexahedronGrid.SetPoints(hexahedronPoints)

aHexahedronMapper = vtkDataSetMapper()
aHexahedronMapper.SetInputData(aHexahedronGrid)

aHexahedronActor = vtkActor()
aHexahedronActor.SetMapper(aHexahedronMapper)
aHexahedronActor.AddPosition(2, 0, 0)
aHexahedronActor.GetProperty().BackfaceCullingOn()

# Tetra
tetraPoints = vtkPoints()
tetraPoints.SetNumberOfPoints(4)
tetraPoints.InsertPoint(0, 0, 0, 0)
tetraPoints.InsertPoint(1, 1, 0, 0)
tetraPoints.InsertPoint(2, 0, 1, 0)
tetraPoints.InsertPoint(3, 1, 1, 1)

aTetra = vtkTetra()
aTetra.GetPointIds().SetId(0, 0)
aTetra.GetPointIds().SetId(1, 1)
aTetra.GetPointIds().SetId(2, 2)
aTetra.GetPointIds().SetId(3, 3)

aTetraGrid = vtkUnstructuredGrid()
aTetraGrid.Allocate(1, 1)
aTetraGrid.InsertNextCell(aTetra.GetCellType(), aTetra.GetPointIds())
aTetraGrid.SetPoints(tetraPoints)

aTetraMapper = vtkDataSetMapper()
aTetraMapper.SetInputData(aTetraGrid)

aTetraActor = vtkActor()
aTetraActor.SetMapper(aTetraMapper)
aTetraActor.AddPosition(4, 0, 0)
aTetraActor.GetProperty().BackfaceCullingOn()

# Wedge
wedgePoints = vtkPoints()
wedgePoints.SetNumberOfPoints(6)
wedgePoints.InsertPoint(0, 0, 1, 0)
wedgePoints.InsertPoint(1, 0, 0, 0)
wedgePoints.InsertPoint(2, 0, .5, .5)
wedgePoints.InsertPoint(3, 1, 1, 0)
wedgePoints.InsertPoint(4, 1, 0, 0)
wedgePoints.InsertPoint(5, 1, .5, .5)

aWedge = vtkWedge()
aWedge.GetPointIds().SetId(0, 0)
aWedge.GetPointIds().SetId(1, 1)
aWedge.GetPointIds().SetId(2, 2)
aWedge.GetPointIds().SetId(3, 3)
aWedge.GetPointIds().SetId(4, 4)
aWedge.GetPointIds().SetId(5, 5)

aWedgeGrid = vtkUnstructuredGrid()
aWedgeGrid.Allocate(1, 1)
aWedgeGrid.InsertNextCell(aWedge.GetCellType(), aWedge.GetPointIds())
aWedgeGrid.SetPoints(wedgePoints)

aWedgeMapper = vtkDataSetMapper()
aWedgeMapper.SetInputData(aWedgeGrid)

aWedgeActor = vtkActor()
aWedgeActor.SetMapper(aWedgeMapper)
aWedgeActor.AddPosition(6, 0, 0)
aWedgeActor.GetProperty().BackfaceCullingOn()

# Pyramid
pyramidPoints = vtkPoints()
pyramidPoints.SetNumberOfPoints(5)
pyramidPoints.InsertPoint(0, 0, 0, 0)
pyramidPoints.InsertPoint(1, 1, 0, 0)
pyramidPoints.InsertPoint(2, 1, 1, 0)
pyramidPoints.InsertPoint(3, 0, 1, 0)
pyramidPoints.InsertPoint(4, .5, .5, 1)

aPyramid = vtkPyramid()
aPyramid.GetPointIds().SetId(0, 0)
aPyramid.GetPointIds().SetId(1, 1)
aPyramid.GetPointIds().SetId(2, 2)
aPyramid.GetPointIds().SetId(3, 3)
aPyramid.GetPointIds().SetId(4, 4)

aPyramidGrid = vtkUnstructuredGrid()
aPyramidGrid.Allocate(1, 1)
aPyramidGrid.InsertNextCell(aPyramid.GetCellType(), aPyramid.GetPointIds())
aPyramidGrid.SetPoints(pyramidPoints)

aPyramidMapper = vtkDataSetMapper()
aPyramidMapper.SetInputData(aPyramidGrid)

aPyramidActor = vtkActor()
aPyramidActor.SetMapper(aPyramidMapper)
aPyramidActor.AddPosition(8, 0, 0)
aPyramidActor.GetProperty().BackfaceCullingOn()

# Pixel
pixelPoints = vtkPoints()
pixelPoints.SetNumberOfPoints(4)
pixelPoints.InsertPoint(0, 0, 0, 0)
pixelPoints.InsertPoint(1, 1, 0, 0)
pixelPoints.InsertPoint(2, 0, 1, 0)
pixelPoints.InsertPoint(3, 1, 1, 0)

aPixel = vtkPixel()
aPixel.GetPointIds().SetId(0, 0)
aPixel.GetPointIds().SetId(1, 1)
aPixel.GetPointIds().SetId(2, 2)
aPixel.GetPointIds().SetId(3, 3)

aPixelGrid = vtkUnstructuredGrid()
aPixelGrid.Allocate(1, 1)
aPixelGrid.InsertNextCell(aPixel.GetCellType(), aPixel.GetPointIds())
aPixelGrid.SetPoints(pixelPoints)

aPixelMapper = vtkDataSetMapper()
aPixelMapper.SetInputData(aPixelGrid)

aPixelActor = vtkActor()
aPixelActor.SetMapper(aPixelMapper)
aPixelActor.AddPosition(0, 0, 2)
aPixelActor.GetProperty().BackfaceCullingOn()

# Quad
quadPoints = vtkPoints()
quadPoints.SetNumberOfPoints(4)
quadPoints.InsertPoint(0, 0, 0, 0)
quadPoints.InsertPoint(1, 1, 0, 0)
quadPoints.InsertPoint(2, 1, 1, 0)
quadPoints.InsertPoint(3, 0, 1, 0)

aQuad = vtkQuad()
aQuad.GetPointIds().SetId(0, 0)
aQuad.GetPointIds().SetId(1, 1)
aQuad.GetPointIds().SetId(2, 2)
aQuad.GetPointIds().SetId(3, 3)

aQuadGrid = vtkUnstructuredGrid()
aQuadGrid.Allocate(1, 1)
aQuadGrid.InsertNextCell(aQuad.GetCellType(), aQuad.GetPointIds())
aQuadGrid.SetPoints(quadPoints)

aQuadMapper = vtkDataSetMapper()
aQuadMapper.SetInputData(aQuadGrid)

aQuadActor = vtkActor()
aQuadActor.SetMapper(aQuadMapper)
aQuadActor.AddPosition(2, 0, 2)
aQuadActor.GetProperty().BackfaceCullingOn()

# Triangle
trianglePoints = vtkPoints()
trianglePoints.SetNumberOfPoints(3)
trianglePoints.InsertPoint(0, 0, 0, 0)
trianglePoints.InsertPoint(1, 1, 0, 0)
trianglePoints.InsertPoint(2, .5, .5, 0)

triangleTCoords = vtkFloatArray()
triangleTCoords.SetNumberOfComponents(2)
triangleTCoords.SetNumberOfTuples(3)
triangleTCoords.InsertTuple2(0, 1, 1)
triangleTCoords.InsertTuple2(1, 2, 2)
triangleTCoords.InsertTuple2(2, 3, 3)

aTriangle = vtkTriangle()
aTriangle.GetPointIds().SetId(0, 0)
aTriangle.GetPointIds().SetId(1, 1)
aTriangle.GetPointIds().SetId(2, 2)

aTriangleGrid = vtkUnstructuredGrid()
aTriangleGrid.Allocate(1, 1)
aTriangleGrid.InsertNextCell(aTriangle.GetCellType(), aTriangle.GetPointIds())
aTriangleGrid.SetPoints(trianglePoints)
aTriangleGrid.GetPointData().SetTCoords(triangleTCoords)

aTriangleMapper = vtkDataSetMapper()
aTriangleMapper.SetInputData(aTriangleGrid)

aTriangleActor = vtkActor()
aTriangleActor.SetMapper(aTriangleMapper)
aTriangleActor.AddPosition(4, 0, 2)
aTriangleActor.GetProperty().BackfaceCullingOn()

# Polygon
polygonPoints = vtkPoints()
polygonPoints.SetNumberOfPoints(4)
polygonPoints.InsertPoint(0, 0, 0, 0)
polygonPoints.InsertPoint(1, 1, 0, 0)
polygonPoints.InsertPoint(2, 1, 1, 0)
polygonPoints.InsertPoint(3, 0, 1, 0)

aPolygon = vtkPolygon()
aPolygon.GetPointIds().SetNumberOfIds(4)
aPolygon.GetPointIds().SetId(0, 0)
aPolygon.GetPointIds().SetId(1, 1)
aPolygon.GetPointIds().SetId(2, 2)
aPolygon.GetPointIds().SetId(3, 3)

aPolygonGrid = vtkUnstructuredGrid()
aPolygonGrid.Allocate(1, 1)
aPolygonGrid.InsertNextCell(aPolygon.GetCellType(), aPolygon.GetPointIds())
aPolygonGrid.SetPoints(polygonPoints)

aPolygonMapper = vtkDataSetMapper()
aPolygonMapper.SetInputData(aPolygonGrid)

aPolygonActor = vtkActor()
aPolygonActor.SetMapper(aPolygonMapper)
aPolygonActor.AddPosition(6, 0, 2)
aPolygonActor.GetProperty().BackfaceCullingOn()

# Triangle strip
triangleStripPoints = vtkPoints()
triangleStripPoints.SetNumberOfPoints(5)
triangleStripPoints.InsertPoint(0, 0, 1, 0)
triangleStripPoints.InsertPoint(1, 0, 0, 0)
triangleStripPoints.InsertPoint(2, 1, 1, 0)
triangleStripPoints.InsertPoint(3, 1, 0, 0)
triangleStripPoints.InsertPoint(4, 2, 1, 0)

triangleStripTCoords = vtkFloatArray()
triangleStripTCoords.SetNumberOfComponents(2)
triangleStripTCoords.SetNumberOfTuples(3)
triangleStripTCoords.InsertTuple2(0, 1, 1)
triangleStripTCoords.InsertTuple2(1, 2, 2)
triangleStripTCoords.InsertTuple2(2, 3, 3)
triangleStripTCoords.InsertTuple2(3, 4, 4)
triangleStripTCoords.InsertTuple2(4, 5, 5)

aTriangleStrip = vtkTriangleStrip()
aTriangleStrip.GetPointIds().SetNumberOfIds(5)
aTriangleStrip.GetPointIds().SetId(0, 0)
aTriangleStrip.GetPointIds().SetId(1, 1)
aTriangleStrip.GetPointIds().SetId(2, 2)
aTriangleStrip.GetPointIds().SetId(3, 3)
aTriangleStrip.GetPointIds().SetId(4, 4)

aTriangleStripGrid = vtkUnstructuredGrid()
aTriangleStripGrid.Allocate(1, 1)
aTriangleStripGrid.InsertNextCell(aTriangleStrip.GetCellType(), aTriangleStrip.GetPointIds())
aTriangleStripGrid.SetPoints(triangleStripPoints)
aTriangleStripGrid.GetPointData().SetTCoords(triangleStripTCoords)

aTriangleStripMapper = vtkDataSetMapper()
aTriangleStripMapper.SetInputData(aTriangleStripGrid)

aTriangleStripActor = vtkActor()
aTriangleStripActor.SetMapper(aTriangleStripMapper)
aTriangleStripActor.AddPosition(8, 0, 2)
aTriangleStripActor.GetProperty().BackfaceCullingOn()

# Line
linePoints = vtkPoints()
linePoints.SetNumberOfPoints(2)
linePoints.InsertPoint(0, 0, 0, 0)
linePoints.InsertPoint(1, 1, 1, 0)

aLine = vtkLine()
aLine.GetPointIds().SetId(0, 0)
aLine.GetPointIds().SetId(1, 1)

aLineGrid = vtkUnstructuredGrid()
aLineGrid.Allocate(1, 1)
aLineGrid.InsertNextCell(aLine.GetCellType(), aLine.GetPointIds())
aLineGrid.SetPoints(linePoints)

aLineMapper = vtkDataSetMapper()
aLineMapper.SetInputData(aLineGrid)

aLineActor = vtkActor()
aLineActor.SetMapper(aLineMapper)
aLineActor.AddPosition(0, 0, 4)
aLineActor.GetProperty().BackfaceCullingOn()

# Polyline
polyLinePoints = vtkPoints()
polyLinePoints.SetNumberOfPoints(3)
polyLinePoints.InsertPoint(0, 0, 0, 0)
polyLinePoints.InsertPoint(1, 1, 1, 0)
polyLinePoints.InsertPoint(2, 1, 0, 0)

aPolyLine = vtkPolyLine()
aPolyLine.GetPointIds().SetNumberOfIds(3)
aPolyLine.GetPointIds().SetId(0, 0)
aPolyLine.GetPointIds().SetId(1, 1)
aPolyLine.GetPointIds().SetId(2, 2)

aPolyLineGrid = vtkUnstructuredGrid()
aPolyLineGrid.Allocate(1, 1)
aPolyLineGrid.InsertNextCell(aPolyLine.GetCellType(), aPolyLine.GetPointIds())
aPolyLineGrid.SetPoints(polyLinePoints)

aPolyLineMapper = vtkDataSetMapper()
aPolyLineMapper.SetInputData(aPolyLineGrid)

aPolyLineActor = vtkActor()
aPolyLineActor.SetMapper(aPolyLineMapper)
aPolyLineActor.AddPosition(2, 0, 4)
aPolyLineActor.GetProperty().BackfaceCullingOn()

# Vertex
vertexPoints = vtkPoints()
vertexPoints.SetNumberOfPoints(1)
vertexPoints.InsertPoint(0, 0, 0, 0)

aVertex = vtkVertex()
aVertex.GetPointIds().SetId(0, 0)

aVertexGrid = vtkUnstructuredGrid()
aVertexGrid.Allocate(1, 1)
aVertexGrid.InsertNextCell(aVertex.GetCellType(), aVertex.GetPointIds())
aVertexGrid.SetPoints(vertexPoints)

aVertexMapper = vtkDataSetMapper()
aVertexMapper.SetInputData(aVertexGrid)

aVertexActor = vtkActor()
aVertexActor.SetMapper(aVertexMapper)
aVertexActor.AddPosition(0, 0, 6)
aVertexActor.GetProperty().BackfaceCullingOn()

# Polyvertex
polyVertexPoints = vtkPoints()
polyVertexPoints.SetNumberOfPoints(3)
polyVertexPoints.InsertPoint(0, 0, 0, 0)
polyVertexPoints.InsertPoint(1, 1, 0, 0)
polyVertexPoints.InsertPoint(2, 1, 1, 0)

aPolyVertex = vtkPolyVertex()
aPolyVertex.GetPointIds().SetNumberOfIds(3)
aPolyVertex.GetPointIds().SetId(0, 0)
aPolyVertex.GetPointIds().SetId(1, 1)
aPolyVertex.GetPointIds().SetId(2, 2)

aPolyVertexGrid = vtkUnstructuredGrid()
aPolyVertexGrid.Allocate(1, 1)
aPolyVertexGrid.InsertNextCell(aPolyVertex.GetCellType(), aPolyVertex.GetPointIds())
aPolyVertexGrid.SetPoints(polyVertexPoints)

aPolyVertexMapper = vtkDataSetMapper()
aPolyVertexMapper.SetInputData(aPolyVertexGrid)

aPolyVertexActor = vtkActor()
aPolyVertexActor.SetMapper(aPolyVertexMapper)
aPolyVertexActor.AddPosition(2, 0, 6)
aPolyVertexActor.GetProperty().BackfaceCullingOn()

# Pentagonal prism
pentaPoints = vtkPoints()
pentaPoints.SetNumberOfPoints(10)
pentaPoints.InsertPoint(0, 0.25, 0.0, 0.0)
pentaPoints.InsertPoint(1, 0.75, 0.0, 0.0)
pentaPoints.InsertPoint(2, 1.0, 0.5, 0.0)
pentaPoints.InsertPoint(3, 0.5, 1.0, 0.0)
pentaPoints.InsertPoint(4, 0.0, 0.5, 0.0)
pentaPoints.InsertPoint(5, 0.25, 0.0, 1.0)
pentaPoints.InsertPoint(6, 0.75, 0.0, 1.0)
pentaPoints.InsertPoint(7, 1.0, 0.5, 1.0)
pentaPoints.InsertPoint(8, 0.5, 1.0, 1.0)
pentaPoints.InsertPoint(9, 0.0, 0.5, 1.0)

aPenta = vtkPentagonalPrism()
aPenta.GetPointIds().SetId(0, 0)
aPenta.GetPointIds().SetId(1, 1)
aPenta.GetPointIds().SetId(2, 2)
aPenta.GetPointIds().SetId(3, 3)
aPenta.GetPointIds().SetId(4, 4)
aPenta.GetPointIds().SetId(5, 5)
aPenta.GetPointIds().SetId(6, 6)
aPenta.GetPointIds().SetId(7, 7)
aPenta.GetPointIds().SetId(8, 8)
aPenta.GetPointIds().SetId(9, 9)

aPentaGrid = vtkUnstructuredGrid()
aPentaGrid.Allocate(1, 1)
aPentaGrid.InsertNextCell(aPenta.GetCellType(), aPenta.GetPointIds())
aPentaGrid.SetPoints(pentaPoints)

aPentaMapper = vtkDataSetMapper()
aPentaMapper.SetInputData(aPentaGrid)

aPentaActor = vtkActor()
aPentaActor.SetMapper(aPentaMapper)
aPentaActor.AddPosition(10, 0, 0)
aPentaActor.GetProperty().BackfaceCullingOn()

# Hexagonal prism
hexaPoints = vtkPoints()
hexaPoints.SetNumberOfPoints(12)
hexaPoints.InsertPoint(0, 0.0, 0.0, 0.0)
hexaPoints.InsertPoint(1, 0.5, 0.0, 0.0)
hexaPoints.InsertPoint(2, 1.0, 0.5, 0.0)
hexaPoints.InsertPoint(3, 1.0, 1.0, 0.0)
hexaPoints.InsertPoint(4, 0.5, 1.0, 0.0)
hexaPoints.InsertPoint(5, 0.0, 0.5, 0.0)
hexaPoints.InsertPoint(6, 0.0, 0.0, 1.0)
hexaPoints.InsertPoint(7, 0.5, 0.0, 1.0)
hexaPoints.InsertPoint(8, 1.0, 0.5, 1.0)
hexaPoints.InsertPoint(9, 1.0, 1.0, 1.0)
hexaPoints.InsertPoint(10, 0.5, 1.0, 1.0)
hexaPoints.InsertPoint(11, 0.0, 0.5, 1.0)

aHexa = vtkHexagonalPrism()
aHexa.GetPointIds().SetId(0, 0)
aHexa.GetPointIds().SetId(1, 1)
aHexa.GetPointIds().SetId(2, 2)
aHexa.GetPointIds().SetId(3, 3)
aHexa.GetPointIds().SetId(4, 4)
aHexa.GetPointIds().SetId(5, 5)
aHexa.GetPointIds().SetId(6, 6)
aHexa.GetPointIds().SetId(7, 7)
aHexa.GetPointIds().SetId(8, 8)
aHexa.GetPointIds().SetId(9, 9)
aHexa.GetPointIds().SetId(10, 10)
aHexa.GetPointIds().SetId(11, 11)

aHexaGrid = vtkUnstructuredGrid()
aHexaGrid.Allocate(1, 1)
aHexaGrid.InsertNextCell(aHexa.GetCellType(), aHexa.GetPointIds())
aHexaGrid.SetPoints(hexaPoints)

aHexaMapper = vtkDataSetMapper()
aHexaMapper.SetInputData(aHexaGrid)

aHexaActor = vtkActor()
aHexaActor.SetMapper(aHexaMapper)
aHexaActor.AddPosition(12, 0, 0)
aHexaActor.GetProperty().BackfaceCullingOn()

ren1.SetBackground(1, 1, 1)

ren1.AddActor(aVoxelActor)
aVoxelActor.GetProperty().SetDiffuseColor(1, 0, 0)

ren1.AddActor(aHexahedronActor)
aHexahedronActor.GetProperty().SetDiffuseColor(1, 1, 0)

ren1.AddActor(aTetraActor)
aTetraActor.GetProperty().SetDiffuseColor(0, 1, 0)

ren1.AddActor(aWedgeActor)
aWedgeActor.GetProperty().SetDiffuseColor(0, 1, 1)

ren1.AddActor(aPyramidActor)
aPyramidActor.GetProperty().SetDiffuseColor(1, 0, 1)

ren1.AddActor(aPixelActor)
aPixelActor.GetProperty().SetDiffuseColor(0, 1, 1)

ren1.AddActor(aQuadActor)
aQuadActor.GetProperty().SetDiffuseColor(1, 0, 1)

ren1.AddActor(aTriangleActor)
aTriangleActor.GetProperty().SetDiffuseColor(.3, 1, .5)

ren1.AddActor(aPolygonActor)
aPolygonActor.GetProperty().SetDiffuseColor(1, .4, .5)

ren1.AddActor(aTriangleStripActor)
aTriangleStripActor.GetProperty().SetDiffuseColor(.3, .7, 1)

ren1.AddActor(aLineActor)
aLineActor.GetProperty().SetDiffuseColor(.2, 1, 1)

ren1.AddActor(aPolyLineActor)
aPolyLineActor.GetProperty().SetDiffuseColor(1, 1, 1)

ren1.AddActor(aVertexActor)
aVertexActor.GetProperty().SetDiffuseColor(1, 1, 1)

ren1.AddActor(aPolyVertexActor)
aPolyVertexActor.GetProperty().SetDiffuseColor(1, 1, 1)

ren1.AddActor(aPentaActor)
aPentaActor.GetProperty().SetDiffuseColor(1, 1, 0)

ren1.AddActor(aHexaActor)
aHexaActor.GetProperty().SetDiffuseColor(1, 1, 0)

#
# get the cell center of each type and put a glyph there
#
ball = vtkSphereSource()
ball.SetRadius(.2)

cellType = ['aVoxel', 'aHexahedron', 'aWedge', 'aPyramid', 'aTetra',
              'aQuad', 'aTriangle', 'aTriangleStrip', 'aLine',
              'aPolyLine', 'aVertex', 'aPolyVertex', 'aPixel',
              'aPolygon', 'aPenta', 'aHexa']
for cell in cellType:
    N = eval(cell + 'Grid').GetNumberOfPoints()

    vn = cell + 'Scalar'
    exec(vn + ' = vtkFloatArray()')
    eval(vn).SetNumberOfTuples(N)
    eval(vn).SetNumberOfComponents(1)

    i = 0
    while i < N:
        eval(vn).SetValue(i, 0)
        i = i + 1

    eval(vn).SetValue(0, 4)

    eval(cell + 'Grid').GetPointData().SetScalars(eval(vn))

    for cell in cellType:
        exec(cell + 'derivs' + ' = vtkCellDerivatives()')
        eval(cell + 'derivs').SetInputData(eval(cell + 'Grid'))
        eval(cell + 'derivs').SetVectorModeToComputeGradient()

        exec(cell + 'Centers' + ' = vtkCellCenters()')
        eval(cell + 'Centers').SetInputConnection(eval(cell + 'derivs').GetOutputPort())
        eval(cell + 'Centers').VertexCellsOn()

        exec(cell + 'hog' + ' = vtkHedgeHog()')
        eval(cell + 'hog').SetInputConnection(eval(cell + 'Centers').GetOutputPort())

        exec(cell + 'mapHog' + ' = vtkPolyDataMapper()')
        eval(cell + 'mapHog').SetInputConnection(eval(cell + 'hog').GetOutputPort())
        eval(cell + 'mapHog').SetScalarModeToUseCellData()
        eval(cell + 'mapHog').ScalarVisibilityOff()

        exec(cell + 'hogActor' + ' = vtkActor()')
        eval(cell + 'hogActor').SetMapper(eval(cell + 'mapHog'))
        eval(cell + 'hogActor').GetProperty().SetColor(0, 1, 0)

        exec(cell + 'Glyph3D' + ' = vtkGlyph3D()')
        eval(cell + 'Glyph3D').SetInputConnection(eval(cell + 'Centers').GetOutputPort())
        eval(cell + 'Glyph3D').SetSourceData(ball.GetOutput())

        exec(cell + 'CentersMapper' + ' = vtkPolyDataMapper()')
        eval(cell + 'CentersMapper').SetInputConnection(eval(cell + 'Glyph3D').GetOutputPort())

        exec(cell + 'CentersActor' + ' = vtkActor()')
        eval(cell + 'CentersActor').SetMapper(eval(cell + 'CentersMapper'))

        eval(cell + 'hogActor').SetPosition(eval(cell + 'Actor').GetPosition())
        ren1.AddActor(eval(cell + 'hogActor'))
        eval(cell + 'hogActor').GetProperty().SetRepresentationToWireframe()


ren1.ResetCamera()
ren1.GetActiveCamera().Azimuth(30)
ren1.GetActiveCamera().Elevation(20)
ren1.GetActiveCamera().Dolly(3.0)
ren1.ResetCameraClippingRange()

renWin.SetSize(300, 150)

renWin.Render()

threshold = 0.18

# render the image
#
iren.Initialize()
iren.Start()
