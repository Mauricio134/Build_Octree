#!/usr/bin/env python
from vtkmodules.vtkIOImage import vtkImageReader
from vtkmodules.vtkImagingCore import (
    vtkImageMagnify,
    vtkImageShiftScale,
)
from vtkmodules.vtkInteractionImage import vtkImageViewer
import vtkmodules.vtkInteractionStyle
import vtkmodules.vtkRenderingFreeType
import vtkmodules.vtkRenderingOpenGL2
from vtkmodules.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

# Shift and scale an image (in that order)
# This filter is useful for converting to a lower precision data type.
# This script tests the clamp overflow feature.
reader = vtkImageReader()
reader.GetExecutive().SetReleaseDataFlag(0,0)
reader.SetDataByteOrderToLittleEndian()
reader.SetDataExtent(0,63,0,63,1,93)
reader.SetFilePrefix(VTK_DATA_ROOT + "/Data/headsq/quarter")
reader.SetDataMask(0x7fff)
shiftScale = vtkImageShiftScale()
shiftScale.SetInputConnection(reader.GetOutputPort())
shiftScale.SetShift(-1000.0)
shiftScale.SetScale(4.0)
shiftScale.SetOutputScalarTypeToUnsignedShort()
shiftScale.ClampOverflowOn()
shiftScale2 = vtkImageShiftScale()
shiftScale2.SetInputConnection(shiftScale.GetOutputPort())
shiftScale2.SetShift(0)
shiftScale2.SetScale(2.0)
mag = vtkImageMagnify()
mag.SetInputConnection(shiftScale2.GetOutputPort())
mag.SetMagnificationFactors(4,4,1)
mag.InterpolateOff()
viewer = vtkImageViewer()
viewer.SetInputConnection(mag.GetOutputPort())
viewer.SetColorWindow(1024)
viewer.SetColorLevel(512)
#make interface
#skipping source
# --- end of script --
