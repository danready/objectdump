// GNU General Public License Agreement
// Copyright (C) 2015-2016 Daniele Berto daniele.fratello@gmail.com
//
// objectDump is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software Foundation. 
// You must retain a copy of this licence in all copies. 
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License for more details.
// ---------------------------------------------------------------------------------

/**
* @file LogFile.h 
*/

/**
* @brief The LogFile singleton is used to write the error codes retrieved by the CAENDigitizer function to the logfile indicates by the 
* log_file_path attribute. Using the "more" command, the user prints the content of the log file.
* @author Daniele Berto
*/

#include <stdio.h>

class LogFile
{
private:
  /**
  * @brief The ret_debug variable takes note of the error code retrieved by the "DigitizerErrorObjectDebuggingLog" method.
  */
  int ret_debug;

  /**
  * @brief The can_write variable indicates if the LogFile singleton can print an error message if some errore occured.
  */
  int can_write;

  /**
  * @brief the flag variable indicates if the LogFile singleton can print the message "Some error occurred".
  */
  int flag;

  /**
  * @brief The log_file_punt is a file pointer to the log_file.
  */
  FILE *log_file_punt;

  /**
  * @brief The log_file_pInstance is used to implement the singleton design pattern.
  */
  static LogFile *log_file_pInstance;

  /**
  * @brief The log_file_pInstance is used to implement the singleton design pattern.
  */
  DigitizerErrorObject my_error;

public:
  /**
  * @brief The log_file_path stores the path of the log file.
  */
  const char *log_file_path;

  /**
  * @brief The "Instance()" method returns a pointer to the LogFile instance.
  */
  static LogFile *Instance ();

  /**
  * @brief The LogFileSet method copies the log_file_arg parameter to the log_file_path and opens it using the log_file_punt file pointer.
  */
  void LogFileSet (const char *log_file_arg);

  /**
  * @brief The LogFileWrite method prints the meaning of the CAEN_DGTZ_ErrorCode ret_arg to the log file.
  * @param ret_arg is the CAEN_DGTZ_ErrorCode being written on the log file.
  * @param file is the path of the file in which the functions that generated the error code where located.
  * @param func is the name of the function in which the functions that generated the error code where located.
  * @param line is the line number of the functions that generated the error code.
  * @return void.
  */
  void LogFileWrite (CAEN_DGTZ_ErrorCode ret_arg, const char *file,
		     const char *func, int line);

  /**
  * @brief The LogFileWriteString method prints the string parameter to the log file.
  */
  void LogFileWriteString (const char *string);

  /**
  * @brief The LogFileRead method prints the content of the log file.
  */
  void LogFileRead ();

  /**
  * @brief The LogFileMessageOn method sets to 1 the flag attribute allowing the object to print the message "Some error occurred".
  */
  void LogFileMessageOn ();

  /**
  * @brief The LogFileMessageOff method sets to 0 the flag attribute disallowing the object to print the message "Some error occurred".
  */
  void LogFileMessageOff ();
};
