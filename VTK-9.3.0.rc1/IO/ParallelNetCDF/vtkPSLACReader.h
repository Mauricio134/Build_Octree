// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

/**
 * @class   vtkPSLACReader
 *
 *
 *
 * Extends the vtkSLACReader to read in partitioned pieces.  Due to the nature
 * of the data layout, this reader only works in a data parallel mode where
 * each process in a parallel job simultaneously attempts to read the piece
 * corresponding to the local process id.
 *
 */

#ifndef vtkPSLACReader_h
#define vtkPSLACReader_h

#include "vtkIOParallelNetCDFModule.h" // For export macro
#include "vtkSLACReader.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkMultiProcessController;

class VTKIOPARALLELNETCDF_EXPORT vtkPSLACReader : public vtkSLACReader
{
public:
  vtkTypeMacro(vtkPSLACReader, vtkSLACReader);
  static vtkPSLACReader* New();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * The controller used to communicate partition data.  The number of pieces
   * requested must agree with the number of processes, the piece requested must
   * agree with the local process id, and all process must invoke
   * ProcessRequests of this filter simultaneously.
   */
  vtkGetObjectMacro(Controller, vtkMultiProcessController);
  virtual void SetController(vtkMultiProcessController*);
  ///@}

protected:
  vtkPSLACReader();
  ~vtkPSLACReader() override;

  vtkMultiProcessController* Controller;

  int RequestInformation(vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) override;

  int RequestData(vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) override;

  int CheckTetrahedraWinding(int meshFD) override;
  int ReadConnectivity(
    int meshFD, vtkMultiBlockDataSet* surfaceOutput, vtkMultiBlockDataSet* volumeOutput) override;
  int ReadCoordinates(int meshFD, vtkMultiBlockDataSet* output) override;
  int ReadMidpointCoordinates(
    int meshFD, vtkMultiBlockDataSet* output, MidpointCoordinateMap& map) override;
  int ReadMidpointData(int meshFD, vtkMultiBlockDataSet* output, MidpointIdMap& map) override;
  int RestoreMeshCache(vtkMultiBlockDataSet* surfaceOutput, vtkMultiBlockDataSet* volumeOutput,
    vtkMultiBlockDataSet* compositeOutput) override;
  int ReadFieldData(const int* modeFDArray, int numModeFDs, vtkMultiBlockDataSet* output) override;

  int ReadTetrahedronInteriorArray(int meshFD, vtkIdTypeArray* connectivity) override;
  int ReadTetrahedronExteriorArray(int meshFD, vtkIdTypeArray* connectivity) override;

  int MeshUpToDate() override;

  /**
   * Reads point data arrays.  Called by ReadCoordinates and ReadFieldData.
   */
  vtkSmartPointer<vtkDataArray> ReadPointDataArray(int ncFD, int varId) override;

  class vtkInternal;
  vtkInternal* PInternal;

  ///@{
  /**
   * The number of pieces and the requested piece to load.  Synonymous with
   * the number of processes and the local process id.
   */
  int NumberOfPieces;
  int RequestedPiece;
  ///@}

  /**
   * The number of points defined in the mesh file.
   */
  vtkIdType NumberOfGlobalPoints;

  /**
   * The number of midpoints defined in the mesh file
   */
  vtkIdType NumberOfGlobalMidpoints;

  ///@{
  /**
   * The start/end points read by the given process.
   */
  vtkIdType StartPointRead(int process)
  {
    return process * (this->NumberOfGlobalPoints / this->NumberOfPieces + 1);
  }
  vtkIdType EndPointRead(int process)
  {
    vtkIdType result = this->StartPointRead(process + 1);
    if (result > this->NumberOfGlobalPoints)
      result = this->NumberOfGlobalPoints;
    return result;
  }
  ///@}

  ///@{
  /**
   * Piece information from the last call.
   */
  int NumberOfPiecesCache;
  int RequestedPieceCache;
  ///@}

private:
  vtkPSLACReader(const vtkPSLACReader&) = delete;
  void operator=(const vtkPSLACReader&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif // vtkPSLACReader_h
