set(classes
  vtkReebGraphSimplificationFilter
  vtkReebGraphSurfaceSkeletonFilter
  vtkReebGraphToJoinSplitTreeFilter
  vtkReebGraphVolumeSkeletonFilter
  vtkUnstructuredGridToReebGraphFilter)

vtk_module_add_module(VTK::FiltersReebGraph
  CLASSES ${classes})

vtk_module_find_package(PRIVATE
  PACKAGE Boost)
vtk_module_link(VTK::FiltersReebGraph
  PRIVATE
    "$<BUILD_INTERFACE:Boost::boost>")
vtk_add_test_mangling(VTK::FiltersReebGraph)
