# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkTuple.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkAmoebaMinimizer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkFFT.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkFunctionSet.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkInitialValueProblemSolver.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkMatrix3x3.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkMatrix4x4.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkPolynomialSolversUnivariate.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkQuaternionInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkRungeKutta2.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkRungeKutta4.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkRungeKutta45.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkQuaternion.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Common/Math/vtkCommonMathModule.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkReservoirSampler.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkFFT.txx"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/vtkQuaternion.txx"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkCommonMath-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkCommonMath-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonMath-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonMath-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonMath-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonMath-9.3.1.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/mauricioapaza/Desktop/Build_octree/build/lib"
        -add_rpath "@loader_path"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonMath-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkCommonMath" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Math/LICENSE")
endif()

