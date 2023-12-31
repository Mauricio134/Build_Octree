// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

/*
To add a test you must define a subclass of vtkRTTest and implement the
pure virtual functions. Then in the main section at the bottom of this
file add your test to the tests to be run and rebuild. See some of the
existing tests to get an idea of what to do.
*/

#include "vtkRenderTimingTests.h"

/*=========================================================================
The main entry point
=========================================================================*/
int main(int argc, char* argv[])
{
  // create the timing framework
  vtkRenderTimings a;

  // add the tests
  a.TestsToRun.push_back(new surfaceTest("Surface", false, false));
  a.TestsToRun.push_back(new surfaceTest("SurfaceColored", true, false));
  a.TestsToRun.push_back(new surfaceTest("SurfaceWithNormals", false, true));
  a.TestsToRun.push_back(new surfaceTest("SurfaceColoredWithNormals", true, true));

  a.TestsToRun.push_back(new glyphTest("Glyphing"));

  a.TestsToRun.push_back(new moleculeTest("Molecule"));
  a.TestsToRun.push_back(new moleculeTest("MoleculeAtomsOnly", true));

  a.TestsToRun.push_back(new volumeTest("Volume", false));
  a.TestsToRun.push_back(new volumeTest("VolumeWithShading", true));

  a.TestsToRun.push_back(new depthPeelingTest("DepthPeeling", false));
  a.TestsToRun.push_back(new depthPeelingTest("DepthPeelingWithNormals", true));

  a.TestsToRun.push_back(new manyActorTest("ManyActors"));

  // process them
  return a.ParseCommandLineArguments(argc, argv);
}
