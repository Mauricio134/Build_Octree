#!/usr/bin/env python
from vtkmodules.vtkCommonCore import (
    vtkMath,
    vtkPoints,
)
from vtkmodules.vtkCommonDataModel import (
    vtkCellArray,
    vtkPolyData,
)
from vtkmodules.vtkCommonComputationalGeometry import vtkCardinalSpline
from vtkmodules.vtkFiltersCore import (
    vtkGlyph3D,
    vtkTubeFilter,
)
from vtkmodules.vtkFiltersSources import vtkSphereSource
from vtkmodules.vtkRenderingCore import (
    vtkActor,
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

# Now create the RenderWindow, Renderer and Interactor
#
ren1 = vtkRenderer()
renWin = vtkRenderWindow()
renWin.AddRenderer(ren1)
iren = vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)

math = vtkMath()

numberOfInputPoints = 30

aSplineX = vtkCardinalSpline()
aSplineY = vtkCardinalSpline()
aSplineZ = vtkCardinalSpline()

# generate random points

inputPoints = vtkPoints()
i = 0
while i < numberOfInputPoints:
    x = math.Random(0, 1)
    y = math.Random(0, 1)
    z = math.Random(0, 1)
    aSplineX.AddPoint(i, x)
    aSplineY.AddPoint(i, y)
    aSplineZ.AddPoint(i, z)
    inputPoints.InsertPoint(i, x, y, z)
    i += 1

inputData = vtkPolyData()
inputData.SetPoints(inputPoints)

balls = vtkSphereSource()
balls.SetRadius(.01)
balls.SetPhiResolution(10)
balls.SetThetaResolution(10)

glyphPoints = vtkGlyph3D()
glyphPoints.SetInputData(inputData)
glyphPoints.SetSourceConnection(balls.GetOutputPort())

glyphMapper = vtkPolyDataMapper()
glyphMapper.SetInputConnection(glyphPoints.GetOutputPort())

glyph = vtkActor()
glyph.SetMapper(glyphMapper)
glyph.GetProperty().SetDiffuseColor(1, 0.4, 0.4)
glyph.GetProperty().SetSpecular(.3)
glyph.GetProperty().SetSpecularPower(30)

ren1.AddActor(glyph)

# create a polyline
points = vtkPoints()
profileData = vtkPolyData()

numberOfOutputPoints = 400
offset = 1.0
def fit ():
    points.Reset()
    i = 0
    while i < numberOfOutputPoints:
        t = (numberOfInputPoints - offset) / (numberOfOutputPoints - 1) * i
        points.InsertPoint(i, aSplineX.Evaluate(t), aSplineY.Evaluate(t), aSplineZ.Evaluate(t))
        i += 1

    profileData.Modified()

fit()

lines = vtkCellArray()
lines.InsertNextCell(numberOfOutputPoints)

i = 0
while i < numberOfOutputPoints:
    lines.InsertCellPoint(i)
    i += 1

profileData.SetPoints(points)
profileData.SetLines(lines)

profileTubes = vtkTubeFilter()
profileTubes.SetNumberOfSides(8)
profileTubes.SetInputData(profileData)
profileTubes.SetRadius(.005)

profileMapper = vtkPolyDataMapper()
profileMapper.SetInputConnection(profileTubes.GetOutputPort())

profile = vtkActor()
profile.SetMapper(profileMapper)
profile.GetProperty().SetDiffuseColor(1, 1, 0.6)
profile.GetProperty().SetSpecular(.3)
profile.GetProperty().SetSpecularPower(30)

ren1.AddActor(profile)
ren1.ResetCamera()
ren1.GetActiveCamera().Dolly(1.5)
ren1.ResetCameraClippingRange()

renWin.SetSize(400, 400)
# render the image
#
iren.Initialize()

def opened (aSplineX, aSplineY, aSplineZ):
    offset = 1.0
    aSplineX.ClosedOff()
    aSplineY.ClosedOff()
    aSplineZ.ClosedOff()
    fit()
    renWin.Render()

def varyLeft (aSplineX, aSplineY, aSplineZ):
    left = -1
    while left <= 1:
        aSplineX.SetLeftValue(left)
        aSplineY.SetLeftValue(left)
        aSplineZ.SetLeftValue(left)
        fit()
        renWin.Render()
        left += 0.05


def varyRight (aSplineX, aSplineY, aSplineZ):
    right = -1
    while right <= 1:
        aSplineX.SetRightValue(right)
        aSplineY.SetRightValue(right)
        aSplineZ.SetRightValue(right)
        fit()
        renWin.Render()
        right += 0.05


def constraint (value, aSplineX, aSplineY, aSplineZ):
    aSplineX.SetLeftConstraint(value)
    aSplineY.SetLeftConstraint(value)
    aSplineZ.SetLeftConstraint(value)
    aSplineX.SetRightConstraint(value)
    aSplineY.SetRightConstraint(value)
    aSplineZ.SetRightConstraint(value)

def closed (aSplineX, aSplineY, aSplineZ):
    offset = 0.0
    aSplineX.ClosedOn()
    aSplineY.ClosedOn()
    aSplineZ.ClosedOn()
    fit()
    renWin.Render()

#iren.Start()
