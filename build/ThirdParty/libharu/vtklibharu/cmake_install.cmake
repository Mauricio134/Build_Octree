# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/libharu/vtklibharu/src/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtklibharu/include" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_types.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_consts.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_version.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_annotation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_catalog.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_conf.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_destination.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_doc.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_encoder.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_encrypt.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_encryptdict.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_error.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_ext_gstate.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_font.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_fontdef.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_gstate.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_image.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_info.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_list.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_mmgr.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_objects.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_outline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_pages.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_page_label.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_streams.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_u3d.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_utils.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_pdfa.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_3dmeasure.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/hpdf_exdata.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libharu/vtklibharu/include/vtk_haru_mangle.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/libharu/vtklibharu/include/hpdf_config.h"
    )
endif()

