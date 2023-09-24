//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef vtk_m_rendering_testing_Testing_h
#define vtk_m_rendering_testing_Testing_h


#include <vtkm/cont/DataSet.h>
#include <vtkm/cont/Error.h>
#include <vtkm/cont/Logging.h>
#include <vtkm/cont/RuntimeDeviceTracker.h>
#include <vtkm/cont/testing/Testing.h>

#include <vtkm/filter/image_processing/ImageDifference.h>
#include <vtkm/internal/Configure.h>
#include <vtkm/io/FileUtils.h>
#include <vtkm/io/ImageUtils.h>

#include <vtkm/rendering/View.h>

// Because the testing directory is reserved for test executables and not
// libraries, the vtkm_rendering_testing module has to put this file in
// vtkm/rendering/testlib instead of vtkm/rendering/testing where you normally
// would expect it.
#include <vtkm/rendering/testlib/vtkm_rendering_testing_export.h>

#include <fstream>
#include <sstream>
#include <vector>

/// \brief Tests multiple image files against a provided view for differences.
///
/// This function tests multiple files provided via fileNames against the rendered
/// canvas generated by the provided view using the ImageDifference filter. If one
/// of the provided images is within the error threshold for the image difference
/// this function will return true. Otherwise the view is too different from the images
/// and this will return false with corresponding error messages.
///
/// This function will generate an image if the provided file is missing. If a file is
/// missing the image will be generated for that file and the test will continue.
///
VTKM_RENDERING_TESTING_EXPORT TestEqualResult
test_equal_images(vtkm::rendering::View& view,
                  const std::vector<std::string>& fileNames,
                  const vtkm::IdComponent& averageRadius = 0,
                  const vtkm::IdComponent& pixelShiftRadius = 0,
                  const vtkm::FloatDefault& allowedPixelErrorRatio = 0.00025f,
                  const vtkm::FloatDefault& threshold = 0.05f,
                  const bool& writeDiff = true,
                  const bool& returnOnPass = true);

/// \brief Tests multiple image files against a provided canvas for differences.
///
/// This function tests multiple files provided via fileNames against the rendered
/// canvas using the ImageDifference filter. If one of the provided images is within
/// the error threshold for the image difference this function will return true.
/// Otherwise the view is too different from the images and this will return false
/// with corresponding error messages.
///
/// The canvas must already be rendered when this is called.
///
/// This function will generate an image if the provided file is missing. If a file is
/// missing the image will be generated for that file and the test will continue.
///
VTKM_RENDERING_TESTING_EXPORT TestEqualResult
test_equal_images(const vtkm::rendering::Canvas& canvas,
                  const std::vector<std::string>& fileNames,
                  const vtkm::IdComponent& averageRadius = 0,
                  const vtkm::IdComponent& pixelShiftRadius = 0,
                  const vtkm::FloatDefault& allowedPixelErrorRatio = 0.00025f,
                  const vtkm::FloatDefault& threshold = 0.05f,
                  const bool& writeDiff = true,
                  const bool& returnOnPass = true);

/// \brief Tests multiple image files against a provided image for differences.
///
/// This function tests multiple files provided via fileNames against the provided
/// rendered image using the ImageDifference filter. If one of the provided images
/// is within the error threshold for the image difference this function will return
/// true. Otherwise the view is too different from the images and this will return
/// false with corresponding error messages.
///
/// The provided `DataSet` must contain a `CellSetStructured<2>` and its first field
/// must be the colors to compare.
///
/// This function will generate an image if the provided file is missing. If a file is
/// missing the image will be generated for that file and the test will continue.
///
VTKM_RENDERING_TESTING_EXPORT TestEqualResult
test_equal_images(const vtkm::cont::DataSet& generatedImage,
                  const std::vector<std::string>& fileNames,
                  const vtkm::IdComponent& averageRadius = 0,
                  const vtkm::IdComponent& pixelShiftRadius = 0,
                  const vtkm::FloatDefault& allowedPixelErrorRatio = 0.00025f,
                  const vtkm::FloatDefault& threshold = 0.05f,
                  const bool& writeDiff = true,
                  const bool& returnOnPass = true);

/// \brief Tests multiple image files against a provided image for differences.
///
/// This form of `test_equal_images` takes a single filename and searches for a list
/// of files that match that name or that name with numbers appended to it. It then
/// calls the equivalent `test_equal_images` with the list of files found.
///
/// The `ImageType` can be any type of object that other forms of `test_equal_images`
/// accept such as a `View`, a `Canvas`, or a `DataSet` containing an image.
///
template <typename ImageType>
inline TestEqualResult test_equal_images(
  ImageType&& image,
  const std::string& fileName,
  const vtkm::IdComponent& averageRadius = 0,
  const vtkm::IdComponent& pixelShiftRadius = 0,
  const vtkm::FloatDefault& allowedPixelErrorRatio = 0.00025f,
  const vtkm::FloatDefault& threshold = 0.05f,
  const bool& writeDiff = true)
{
  std::vector<std::string> fileNames;

  // Check to see if there are multiple versions of the file of the format filenName#.png.
  auto found = fileName.rfind(".");
  auto prefix = fileName.substr(0, found);
  auto suffix = fileName.substr(found, fileName.length());

  for (int i = 0;; i++)
  {
    std::ostringstream fileNameStream;
    fileNameStream << prefix << i << suffix;
    std::ifstream check(vtkm::cont::testing::Testing::RegressionImagePath(fileNameStream.str()));
    if (!check.good())
    {
      VTKM_LOG_S(vtkm::cont::LogLevel::Info,
                 "Stopped filename search at: " << fileNameStream.str() << ", beginning testing");
      break;
    }
    fileNames.push_back(fileNameStream.str());
  }

  // Check to see the filename without a number exists.
  {
    std::ifstream check(vtkm::cont::testing::Testing::RegressionImagePath(fileName));
    if (check.good())
    {
      fileNames.push_back(fileName);
    }
  }

  // Make sure at least one file exists
  if (fileNames.empty())
  {
    fileNames.push_back(fileName);
  }

  return test_equal_images(std::forward<ImageType>(image),
                           fileNames,
                           averageRadius,
                           pixelShiftRadius,
                           allowedPixelErrorRatio,
                           threshold,
                           writeDiff);
}

#endif // vtk_m_rendering_testing_Testing_h