cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Rect)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  FiltersSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Rect: Unable to find the VTK build folder.")
endif()

set(SOURCES
    main.cpp
    RTree.cpp
    RTree.h
)

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(Rect MACOSX_BUNDLE ${SOURCES} )
  target_link_libraries(Rect PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS Rect
  MODULES ${VTK_LIBRARIES}
)