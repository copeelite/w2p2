/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Population.h"
namespace sdds {

    int strlen(const char* str);
    void strcpy(char* des, const char* src, int len=-1);
    int strcmp(const char* s1, const char* s2);
    int getTotalLine(FILE *ffptr);
    bool read(int population, char* code, FILE * fptr);
    bool readTesters();
    int read(PcPopulation* &aptr);
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();
    bool read(PcPopulation& asmnt, FILE* ffptr);
}
#endif // !SDDS_FILE_H_
