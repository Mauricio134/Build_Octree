set(classes
  vtkPSimpleBondPerceiver)

vtk_object_factory_declare(
  BASE      vtkSimpleBondPerceiver
  OVERRIDE  vtkPSimpleBondPerceiver)

vtk_object_factory_configure(
  SOURCE_FILE vtk_object_factory_source
  HEADER_FILE vtk_object_factory_header
  EXPORT_MACRO "VTKDOMAINSPARALLELCHEMISTRY_EXPORT")

vtk_module_add_module(VTK::DomainsParallelChemistry
  CLASSES ${classes}
  SOURCES ${vtk_object_factory_source}
  PRIVATE_HEADERS ${vtk_object_factory_header})
vtk_add_test_mangling(VTK::DomainsParallelChemistry)
