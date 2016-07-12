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
* @file Analizzatore.h
* @brief This file contains the declarations of the functions used to scan the config file.
* @details These functions are implemented in analizzatore.c file (generated by flex).
* @author Daniele Berto
*/

#ifndef ANALIZZATORE_H
#define ANALIZZATORE_H

/**
* @brief AnalizzaInit function scans the file indicated in the second parameter searching 
* the informations to open the digitizer and puts them in the conf_object * mioconfig.
* It does not print recognized lines.
* @param mioconfig is where the informations are stored.
* @param file is the path of the configuration file. 
* @return int
*/
int AnalizzaInit (ConfObject * mioconfig, const char *file);

/**
* @brief AnalizzaSetup function scans the file indicated in the second parameter searching
* the information to setup the digitizer and puts the informations in the conf_object * mioconfig.
* It does not print recognized lines.
* @param mioconfig is where the informations are stored.
* @param file is the path of the configuration file.
* @return int
*/
int AnalizzaSetup (ConfObject * mioconfig, const char *file);

/**
* @brief AnalizzaInitPrint function scans the file indicated in the second parameter searching 
* the information to open the digitizer and puts the informations in the conf_object * mioconfig.
* It prints recognized lines.
* @param mioconfig is where the informations are stored.
* @param file is the path of the configuration file. 
* @return int
*/
int AnalizzaInitPrint (ConfObject * mioconfig, const char *file);

/**
* @brief AnalizzaSetupPrint function scans the file indicated in the second parameter searching 
* the information to setup the digitizer and puts the informations in the conf_object * mioconfig.
* It prints recognized lines.
* @param mioconfig is where the informations are stored.
* @param file is the path of the configuration file. 
* @return int
*/
int AnalizzaSetupPrint (ConfObject * mioconfig, const char *file);

/**
* @brief AnalizzaPrint function scans the file indicated in the second parameter searching 
* the information to setup the digitizer and prints them to the stdout.
* @param file is the path of the configuration file. 
* @return void
*/
void AnalizzaPrint (const char *file);

#endif
