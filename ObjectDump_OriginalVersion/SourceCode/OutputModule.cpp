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
* @file OutputModule.cpp 
*/

#include "DefineGeneral.h"
#include "ConfObject.h"
#include "ApplicationSetup.h"
#include "OutputModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

OutputModule *
  OutputModule::outputmodule_pInstance = NULL;

OutputModule *
OutputModule::Instance ()
{
  if (!outputmodule_pInstance)	// Only allow one instance of class to be generated.
    outputmodule_pInstance = new OutputModule ();

  return outputmodule_pInstance;
}

OutputModule::OutputModule ()
{
  OutputModule::OutputModuleSockidOff();
  OutputModule::OutputModuleStdoutOn();

  bzero (buffer, STANDARDBUFFERLIMIT);

  int i;
  for (i = 0; i < 100; i++)
    sockid_array[i] = -1;
}

void
OutputModule::StdOutInsert (const char *string)
{
  bzero (buffer, STANDARDBUFFERLIMIT);
  strncpy (buffer, string, STANDARDBUFFERLIMIT);
}

void
OutputModule::StdOutInsertLex (char *string, int length)
{
  bzero (buffer, STANDARDBUFFERLIMIT);
  strncpy (buffer, string, STANDARDBUFFERLIMIT);
}

void
OutputModule::StdOutPrint ()
{
  output_module_application_setup = ApplicationSetup::Instance ();

//fprintf(stderr, "Codice dell'ultimo carattere: %d\n", buffer[strlen(buffer)-1]);

  if ((output_module_application_setup->input_mode == 2
       || output_module_application_setup->input_mode == 0)
      && output_module_stdout == 1)
    {
      //if (buffer[strlen(buffer)-1] == 10)
      fprintf (stdout, "%s", buffer);
      //else if(buffer[strlen(buffer)-1] != 10){
      //      fprintf(stdout, "%s", buffer);
      //if (strlen(buffer) > 1) fprintf (stdout, "\n");
      //}
    }
}  //void OutputModule::StdOutPrint()

int
OutputModule::TcpUserArrayInsert (int sockid)
{
  int i;
  for (i = 0; i < 100; i++)
    {
      if (sockid_array[i] == -1)
	{
	  sockid_array[i] = sockid;
	  return 0;
	}
    }
  return 1;
}  //int OutputModule::TcpUserArrayInsert(int sockid)



int
OutputModule::TcpUserArrayDelete (int sockid)
{
  int i;
  for (i = 0; i < 100; i++)
    {
      if (sockid_array[i] == sockid)
	{
	  sockid_array[i] = -1;
	  return 0;
	}
    }
  return 1;
}  //int OutputModule::TcpUserArrayDelete(int sockid)


int
OutputModule::TcpUserArraySendStdOut ()
{
  int i;
  output_module_application_setup = ApplicationSetup::Instance ();

  if (output_module_application_setup->input_mode == 2
      || output_module_application_setup->input_mode == 1)
    {
      for (i = 0; i < 100; i++)
	{
	  if (sockid_array[i] > -1
	      && sockid_array[i] == output_module_sockid)
	    {
	      send (sockid_array[i], buffer, 1000, 0);	//usleep(5000); 
	    }	//if(sockid_array[i]>-1)
	}   //for(i=0; i<100; i++)
    }

  return 0;
}   //int OutputModule::TcpUserArraySendStdOut(StdOut * stdout_arg)

 void OutputModule::Output(const char * string){

OutputModule::StdOutInsert (string); 
OutputModule::StdOutPrint(); 
OutputModule::TcpUserArraySendStdOut ();

}


void OutputModule::OutputFlex(const char * string, int length)
{
char * new_line_string = (char*)malloc(length+1); 
strcpy(new_line_string, string); 
new_line_string[length] = new_line_string[length -1]; 
new_line_string[length -1] = '\n'; 
OutputModule::StdOutInsertLex(new_line_string, length); 
usleep(5000); 
OutputModule::StdOutPrint(); 
OutputModule::TcpUserArraySendStdOut(); 
free(new_line_string);
}

void OutputModule::OutputModuleStdoutOn(){
output_module_stdout = 1;
}

void OutputModule::OutputModuleStdoutOff(){
output_module_stdout = -1;
}

void OutputModule::OutputModuleSockidOn(int sockid)
{
output_module_sockid = sockid;
}

void OutputModule::OutputModuleSockidOff(){
output_module_sockid = -1;
}
