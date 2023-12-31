#!/bin/bash
#
#  Author: Darren Weber
#
#  Copy this script to somewhere on your computer and edit it,
#  setting the paths in the variables
#  vtkExamplePath, vtkTestingPath and vtkSourcePath
#  to wherever you have installed VTK.

if [ $# -lt 1 ]; then
    echo "$0 'search term' ['search term' ...]"
    exit 1
fi

#
# Search the CXX and Python files
#
# You may need to set the paths for these variables.
vtkExamplePath="/opt/local/share/vtk/examples"
vtkTestingPath="/opt/local/share/vtk/testing"
vtkSourcePath="/opt/local/share/vtk"

for term in $@; do
    echo
    echo "Search term: ${term}"
    for vtkPath in "${vtkExamplePath}" "${vtkTestingPath}" "${vtkSourcePath}" ; do
        if [ ! -d ${vtkPath} ]; then
            echo "Path not found: ${vtkPath}"
        else
            echo "Searching VTK files in: ${vtkPath}"
            cxxFiles=$(find ${vtkPath} -name "*.cxx")
            grep -l -E -e ${term} ${cxxFiles}
            pyFiles=$(find ${vtkPath} -name "*.py")
            grep -l -E -e ${term} ${pyFiles}
      fi
    done
done
