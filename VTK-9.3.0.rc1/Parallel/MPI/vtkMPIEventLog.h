// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkMPIEventLog
 * @brief   Class for logging and timing.
 *
 *
 * This class is wrapper around MPE event logging functions
 * (available from Argonne National Lab/Missippi State
 * University). It allows users to create events with names
 * and log them. Different log file formats can be generated
 * by changing MPE's configuration. Some of these formats are
 * binary (for examples SLOG and CLOG) and can be analyzed with
 * viewers from ANL. ALOG is particularly useful since it is
 * text based and can be processed with simple scripts.
 *
 * @sa
 * vtkTimerLog vtkMPIController vtkMPICommunicator
 */

#ifndef vtkMPIEventLog_h
#define vtkMPIEventLog_h

#include "vtkObject.h"
#include "vtkParallelMPIModule.h" // For export macro

VTK_ABI_NAMESPACE_BEGIN
class VTKPARALLELMPI_EXPORT vtkMPIEventLog : public vtkObject
{
public:
  vtkTypeMacro(vtkMPIEventLog, vtkObject);

  /**
   * Construct a vtkMPIEventLog with the following initial state:
   * Processes = 0, MaximumNumberOfProcesses = 0.
   */
  static vtkMPIEventLog* New();

  /**
   * Used to initialize the underlying mpe event.
   * HAS TO BE CALLED BY ALL PROCESSES before any event
   * logging is done.
   * It takes a name and a description for the graphical
   * representation, for example, "red:vlines3". See
   * mpe documentation for details.
   * Returns 0 on MPI failure (or aborts depending on
   * MPI error handlers)
   */
  int SetDescription(const char* name, const char* desc);

  ///@{
  /**
   * These methods have to be called once on all processors
   * before and after invoking any logging events.
   * The name of the logfile is given by fileName.
   * See mpe documentation for file formats.
   */
  static void InitializeLogging();
  static void FinalizeLogging(VTK_FILEPATH const char* fileName);
  ///@}

  ///@{
  /**
   * Issue start and stop events for this log entry.
   */
  void StartLogging();
  void StopLogging();
  ///@}

  void PrintSelf(ostream& os, vtkIndent indent) override;

protected:
  vtkMPIEventLog();
  ~vtkMPIEventLog() override;

  static int LastEventId;
  int Active;
  int BeginId;
  int EndId;

private:
  vtkMPIEventLog(const vtkMPIEventLog&) = delete;
  void operator=(const vtkMPIEventLog&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
