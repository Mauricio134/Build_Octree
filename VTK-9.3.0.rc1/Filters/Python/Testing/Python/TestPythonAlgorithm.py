from vtkmodules.vtkCommonDataModel import vtkImageData
from vtkmodules.vtkCommonExecutionModel import vtkStreamingDemandDrivenPipeline
from vtkmodules.vtkFiltersPython import vtkPythonAlgorithm
from vtkmodules.vtkFiltersSources import vtkSphereSource
from vtkmodules.vtkImagingCore import vtkRTAnalyticSource
from vtkmodules.util import vtkAlgorithm as vta
from vtkmodules.test import Testing

class TestPythonAlgorithm(Testing.vtkTest):
    def testSource(self):
        class MyAlgorithm(vta.VTKAlgorithm):
            def __init__(self):
                vta.VTKAlgorithm.__init__(self, nInputPorts=0, outputType='vtkImageData')
                self.Wavelet = vtkRTAnalyticSource()

            def RequestInformation(self, vtkself, request, inInfo, outInfo):
                self.Wavelet.UpdateInformation()
                wOutInfo = self.Wavelet.GetOutputInformation(0)
                vtkSDDP = vtkStreamingDemandDrivenPipeline
                outInfo.GetInformationObject(0).Set(vtkSDDP.WHOLE_EXTENT(), wOutInfo.Get(vtkSDDP.WHOLE_EXTENT()), 6)
                return 1

            def RequestData(self, vtkself, request, inInfo, outInfo):
                self.Wavelet.Update()
                out = self.GetOutputData(outInfo, 0)
                out.ShallowCopy(self.Wavelet.GetOutput())
                return 1

        ex = vtkPythonAlgorithm()
        ex.SetPythonObject(MyAlgorithm())

        ex.Update()

        w = vtkRTAnalyticSource()
        w.Update()

        output = ex.GetOutputDataObject(0)
        self.assertEqual(output.GetPointData().GetScalars().GetRange(),\
            w.GetOutput().GetPointData().GetScalars().GetRange())
        vtkSDDP = vtkStreamingDemandDrivenPipeline
        self.assertEqual(ex.GetOutputInformation(0).Get(vtkSDDP.WHOLE_EXTENT()),\
            w.GetOutputInformation(0).Get(vtkSDDP.WHOLE_EXTENT()))

    def testSource2(self):
        class MyAlgorithm(vta.VTKPythonAlgorithmBase):
            def __init__(self):
                vta.VTKPythonAlgorithmBase.__init__(self, nInputPorts=0, outputType='vtkImageData')
                self.Wavelet = vtkRTAnalyticSource()

            def RequestInformation(self, request, inInfo, outInfo):
                self.Wavelet.UpdateInformation()
                wOutInfo = self.Wavelet.GetOutputInformation(0)
                vtkSDDP = vtkStreamingDemandDrivenPipeline
                outInfo.GetInformationObject(0).Set(
                    vtkSDDP.WHOLE_EXTENT(), wOutInfo.Get(vtkSDDP.WHOLE_EXTENT()), 6)
                return 1

            def RequestData(self, request, inInfo, outInfo):
                self.Wavelet.Update()
                out = vtkImageData.GetData(outInfo)
                out.ShallowCopy(self.Wavelet.GetOutput())
                return 1

        ex = MyAlgorithm()

        ex.Update()

        w = vtkRTAnalyticSource()
        w.Update()

        output = ex.GetOutputDataObject(0)
        self.assertEqual(output.GetPointData().GetScalars().GetRange(),\
            w.GetOutput().GetPointData().GetScalars().GetRange())
        vtkSDDP = vtkStreamingDemandDrivenPipeline
        self.assertEqual(ex.GetOutputInformation(0).Get(vtkSDDP.WHOLE_EXTENT()),\
            w.GetOutputInformation(0).Get(vtkSDDP.WHOLE_EXTENT()))

    def testFilter(self):
        class MyAlgorithm(vta.VTKAlgorithm):
            def RequestData(self, vtkself, request, inInfo, outInfo):
                inp = self.GetInputData(inInfo, 0, 0)
                out = self.GetOutputData(outInfo, 0)
                out.ShallowCopy(inp)
                return 1

        sphere = vtkSphereSource()

        ex = vtkPythonAlgorithm()
        ex.SetPythonObject(MyAlgorithm())

        ex.SetInputConnection(sphere.GetOutputPort())

        ex.Update()

        output = ex.GetOutputDataObject(0)
        ncells = output.GetNumberOfCells()
        self.assertNotEqual(ncells, 0)
        self.assertEqual(ncells, sphere.GetOutput().GetNumberOfCells())
        self.assertEqual(output.GetBounds(), sphere.GetOutput().GetBounds())

    def testFilter2(self):
        class MyAlgorithm(vta.VTKPythonAlgorithmBase):
            def __init__(self):
                vta.VTKPythonAlgorithmBase.__init__(self)
            def RequestData(self, request, inInfo, outInfo):
                inp = self.GetInputData(inInfo, 0, 0)
                out = self.GetOutputData(outInfo, 0)
                out.ShallowCopy(inp)
                return 1

        sphere = vtkSphereSource()

        ex = MyAlgorithm()
        ex.SetInputConnection(sphere.GetOutputPort())

        ex.Update()

        output = ex.GetOutputDataObject(0)
        ncells = output.GetNumberOfCells()
        self.assertNotEqual(ncells, 0)
        self.assertEqual(ncells, sphere.GetOutput().GetNumberOfCells())
        self.assertEqual(output.GetBounds(), sphere.GetOutput().GetBounds())

if __name__ == "__main__":
    Testing.main([(TestPythonAlgorithm, 'test')])
