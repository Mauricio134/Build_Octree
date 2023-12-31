// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright (c) Sandia Corporation
// SPDX-License-Identifier: BSD-3-Clause

/**
 * @class   vtkQtTableRepresentation
 * @brief   set up a vtkTable in a Qt model
 *
 *
 *
 * This class is a wrapper around vtkQtTableModelAdapter.  It
 * performs the following functions:
 *
 * <ul>
 * <li>Keep track of the key column, first data column, and last data column.
 *     Populate the appropriate ivars on the Qt adapter.
 * <li>Assign colors to each of the data series using a vtkLookupTable.
 *     A default lookup table is provided or the user can supply one
 *     using SetColorTable().
 * </ul>
 *
 * The user must supply the following items:
 * <ul>
 * <li>the name of the column that contains the series names,
 * <li>the names of the first and last data columns
 *     (this range should not contain the key column), and
 * <li>(optionally) a vtkLookupTable to use when assigning colors.
 * </ul>
 *
 *
 * @warning
 * Call SetInputConnection with a table connection
 * BEFORE the representation is added to a view or strange things
 * may happen, including segfaults.
 */

#ifndef vtkQtTableRepresentation_h
#define vtkQtTableRepresentation_h

#include "vtkDataRepresentation.h"
#include "vtkViewsQtModule.h" // For export macro

VTK_ABI_NAMESPACE_BEGIN
class vtkDoubleArray;
class vtkLookupTable;
class vtkQtTableModelAdapter;

// ----------------------------------------------------------------------

class VTKVIEWSQT_EXPORT vtkQtTableRepresentation : public vtkDataRepresentation
{
public:
  vtkTypeMacro(vtkQtTableRepresentation, vtkDataRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Set/get the lookup table that will be used to determine colors
   * for each series.  The table's range should be [0, 1).
   */
  void SetColorTable(vtkLookupTable* t);
  vtkGetObjectMacro(ColorTable, vtkLookupTable);
  ///@}

  ///@{
  /**
   * Set/get the name of the column that contains series names.  This
   * must be called BEFORE the representation is added to a view.
   */
  void SetKeyColumn(const char* col);
  char* GetKeyColumn();
  ///@}

  ///@{
  /**
   * Set/get the name of the first data column.  This must be called
   * BEFORE the representation is added to a view.
   */
  vtkSetStringMacro(FirstDataColumn);
  vtkGetStringMacro(FirstDataColumn);
  ///@}

  ///@{
  /**
   * Set/get the name of the last data column.  This must be called
   * BEFORE the representation is added to a view.
   */
  vtkSetStringMacro(LastDataColumn);
  vtkGetStringMacro(LastDataColumn);
  ///@}

protected:
  vtkQtTableRepresentation();
  ~vtkQtTableRepresentation() override;

  /**
   * Update the table representation
   */
  void UpdateTable();

  vtkSetStringMacro(KeyColumnInternal);
  vtkGetStringMacro(KeyColumnInternal);

  // ----------------------------------------------------------------------
  vtkQtTableModelAdapter* ModelAdapter;
  vtkLookupTable* ColorTable;
  vtkDoubleArray* SeriesColors;
  char* KeyColumnInternal;
  char* FirstDataColumn;
  char* LastDataColumn;

  /**
   * Prepare the input connections to this representation.
   */
  int RequestData(vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) override;

  virtual void ResetModel();
  virtual void CreateSeriesColors();

  /**
   * This should set the model type to DATA, METADATA or FULL
   * depending on what you want.
   */
  virtual void SetModelType() {}

private:
  vtkQtTableRepresentation(const vtkQtTableRepresentation&) = delete;
  void operator=(const vtkQtTableRepresentation&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
