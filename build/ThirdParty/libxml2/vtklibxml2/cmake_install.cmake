# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtklibxml2/include/libxml" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/c14n.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/catalog.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/chvalid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/debugXML.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/dict.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/encoding.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/entities.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/globals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/hash.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/HTMLparser.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/HTMLtree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/list.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/nanoftp.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/nanohttp.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/parser.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/parserInternals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/pattern.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/relaxng.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/SAX.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/SAX2.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/schemasInternals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/schematron.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/threads.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/tree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/uri.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/valid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/vtk_libxml2_mangle.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xinclude.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xlink.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlIO.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlautomata.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlerror.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlexports.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlmemory.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlmodule.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlreader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlregexp.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlsave.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlschemas.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlschemastypes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlstring.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlunicode.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xmlwriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xpath.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xpathInternals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/libxml2/vtklibxml2/include/libxml/xpointer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtklibxml2-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtklibxml2-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtklibxml2-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtklibxml2-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtklibxml2-9.3.dylib")
endif()

