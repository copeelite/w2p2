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
#include <cstdio>
namespace sdds {
    void bubble_sort(PcPopulation*& aptr);
    void printDuplicate(char line, int size);
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation
   // of the records in the file
    int noOfRecords();
    void display(const PcPopulation& pptr);
    int load(PcPopulation*& ptr, FILE* fptr);
    //bool read(PcPopulation& asmnt, FILE* fptr);
//    void quick_sort(int a[], int length);
//    void qsort(int a[], int low, int high);
//    int partition(PcPopulation a[], int low, int high);

}
#endif // !SDDS_FILE_H_
