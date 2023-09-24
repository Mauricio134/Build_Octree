# CMake generated Testfile for 
# Source directory: /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6
# Build directory: /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/EnforceConfig.cmake")
add_test([=[SystemInformationNew]=] "/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/bin/cmake" "--system-information" "-G" "Unix Makefiles")
set_tests_properties([=[SystemInformationNew]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/CMakeLists.txt;519;add_test;/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/CMakeLists.txt;0;")
subdirs("Source/kwsys")
subdirs("Utilities/std")
subdirs("Utilities/KWIML")
subdirs("Utilities/cmlibrhash")
subdirs("Utilities/cmzlib")
subdirs("Utilities/cmcurl")
subdirs("Utilities/cmnghttp2")
subdirs("Utilities/cmexpat")
subdirs("Utilities/cmbzip2")
subdirs("Utilities/cmzstd")
subdirs("Utilities/cmliblzma")
subdirs("Utilities/cmlibarchive")
subdirs("Utilities/cmjsoncpp")
subdirs("Utilities/cmlibuv")
subdirs("Source/CursesDialog/form")
subdirs("Utilities/cmcppdap")
subdirs("Source")
subdirs("Utilities")
subdirs("Tests")
subdirs("Auxiliary")
