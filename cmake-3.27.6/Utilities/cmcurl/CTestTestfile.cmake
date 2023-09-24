# CMake generated Testfile for 
# Source directory: /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Utilities/cmcurl
# Build directory: /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Utilities/cmcurl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[curl]=] "curltest" "http://open.cdash.org/user.php")
set_tests_properties([=[curl]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Utilities/cmcurl/CMakeLists.txt;1580;add_test;/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Utilities/cmcurl/CMakeLists.txt;0;")
subdirs("lib")
