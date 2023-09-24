# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfreetype-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfreetype-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkfreetype-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkfreetype-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfreetype-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtkfreetype/include" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/ft2build.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/vtk_freetype_mangle.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtkfreetype/include/freetype" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/freetype.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftadvanc.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftbbox.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftbdf.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftbitmap.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftbzip2.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftcache.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftcid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftcolor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftdriver.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/fterrdef.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/fterrors.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftfntfmt.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftgasp.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftglyph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftgxval.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftgzip.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftimage.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftincrem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftlcdfil.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftlist.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftlogging.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftlzw.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftmac.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftmm.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftmodapi.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftmoderr.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftotval.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftoutln.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftparams.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftpfr.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftrender.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftsizes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftsnames.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftstroke.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftsynth.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftsystem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/fttrigon.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/fttypes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ftwinfnt.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/t1tables.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/ttnameid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/tttables.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/tttags.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtkfreetype/include/freetype/config" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftconfig.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftheader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftmodule.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftoption.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftstdlib.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/integer-types.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/mac-support.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/freetype/vtkfreetype/include/freetype/config/public-macros.h"
    )
endif()

