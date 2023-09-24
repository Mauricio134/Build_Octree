if(NOT EXISTS "/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/install_manifest.txt\"")
endif()

file(READ "/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/install_manifest.txt" files)
string(REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if(EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/Users/mauricioapaza/Desktop/Build_Octree/cmake-3.27.6/Bootstrap.cmk/cmake" ARGS "-E rm -f \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if("${rm_retval}" STREQUAL 0)
    else()
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()
