/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"
#include "Population.h"
#include <iostream>
using namespace std;
namespace sdds {
    int strlen(const char* str) {
        int len = 0;
        while(str[len]) {
            len++;
        }
        return len;
    }
    void strcpy(char* des, const char* src, int len) {
        int i;
        for(i = 0; src[i] && (len < 0 || i < len); i++) {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    int strcmp(const char* s1, const char* s2) {
        int i;
        for(i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

   FILE* fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file 
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Closes the open file
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(int population, char* code, FILE * fptr){
        bool success = false;
        success = fscanf(fptr, "%3[^\n],%d", code, &population) == 2;
        if(success)
        {
            return success;
        }
        return success;
    }
    bool readTesters(){
        bool test = false;
        int i;
        char str[4];
        if(read(i, str, fptr)){
            test = true;
        }
        else{
            cout << "Error: incorrect number of records read; "
                    "the data is possibly corrupted!" << endl;
            test = false;
        }
        return test;
    }
    //I create cout lines function by the way I can understand
    int getTotalLine(FILE *ffptr)
    {
       int numberOfLine{0};
       char ch;
       do{
           ch= fgetc(ffptr);
           if(ch == '\n') numberOfLine++;
       }while(ch!=EOF);
       return numberOfLine;
    }
    int read(PcPopulation* &aptr) {
        int i = 0;
        int totalRecords = getTotalLine(fptr);
        //cout << totalRecords;
        int tempRecords{};
        aptr = new PcPopulation[totalRecords];
        bool flag = true;
        for (i = 0; i < totalRecords && flag; i++)
        {

            if (read(aptr[i], fptr)) {
                tempRecords++;
            }
            else {
                flag = false;
            }

        }
        return tempRecords;
   }
    bool read(PcPopulation &asmnt)
    {

        int tempNum{0};
        char tempString[4];
        bool readSuccess = read(tempNum, tempString, fptr);

        if (readSuccess) {
            *asmnt.m_population = tempNum;
            asmnt.m_postalCode = new char[strlen(tempString)+1];
            strcpy(asmnt.m_postalCode, tempString);
            return true;
        }
        else{
            return false;
        }



    }
}