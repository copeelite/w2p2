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
#include<algorithm>
#include<vector>
using namespace std;
namespace sdds {
    PcPopulation* ptr = nullptr;
    //PcPopulation* pptr = nullptr;
    FILE *fptr;
    int totalPopulation{0};


    int totalData = 0;
    void printDuplicate(char line, int size)
    {
        for(int i = 0; i < size; i++)
        {
            cout << line;
        }
        cout << endl;
    }
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
    bool ifCorrectContent(){
        bool check = false;
        int curNum = 0;
        char str[4];
        check = fscanf(fptr, "%3[^\n],%d\n", str, &curNum) == 2;
        return check;
    }
    bool load(const char *filename)
    {
        bool test = false;
        if(openFile(filename))
        {
            test = true;
            if(!ifCorrectContent()){
                test = false;
                cout << "Error: incorrect number of records read; the "
                        "data is possibly corrupted!" << endl;
            }

        }
        else {
            cout << "Could not open data file: "<< filename << endl;

        }
        if(test)
        {
            totalData = load(ptr, fptr);
            bubble_sort(ptr);
        }


        return test;
    }

    void display(){
        cout << "Postal Code: population" << endl;
        printDuplicate('-', 25);


        for (int i = 0;  i < totalData+1; i++)
        {

            cout << i + 1 << "- ";
            display(ptr[i]);
        }
//            for(int i = 0, j = 1; i < totalData+1; i++, j++)
//            {
//                cout  <<j<< "- " << ptr[i].m_postalCode << ":  "<< *ptr[i].m_population  << endl;
//
//            }

        printDuplicate('-', 25);
        cout << "Population of Canada: " << totalPopulation << endl;

    }
    void display(const PcPopulation& pptr)
    {
        cout << pptr.m_postalCode << ":  " << *pptr.m_population <<  endl;
    }

    void deallocateMemory() {
        for(int i = 0; i < totalData+1; i++)
        {
            delete ptr[i].m_population;

            delete[] ptr[i].m_postalCode;
        }
        delete [] ptr;
        //delete[] pptr;
        ptr = nullptr;
        //pptr = nullptr;
    }




        int load(PcPopulation*& ptr, FILE* fptr)
    {
        int totalLines = noOfRecords();
        ptr = new PcPopulation[totalLines+1];
        //pptr = new PcPopulation[totalLines+1];
        bool flag = true;

        int i = 0;
        for(i = 0; i < totalLines+1 && flag; i++)
        {
            ptr[i].m_population = new int;
            ptr[i].m_postalCode = new char[4];
            fscanf(fptr, "%3[^\n],%d\n", ptr[i].m_postalCode,
                   ptr[i].m_population);
            totalPopulation+= *ptr[i].m_population;
        }


        closeFile();



        return totalLines;
    }


    void bubble_sort(PcPopulation*& aptr) {
        int i, j;
        PcPopulation temp;
        for (i = 0; i < totalData; i++)
        {
            for (j = 0; j < totalData; j++)
            {
                //display(ptr[j]);
                if (*aptr[j].m_population > *aptr[j + 1].m_population) {
                    temp = aptr[j];
                    aptr[j] = aptr[j+1];
                    aptr[j+1] = temp;
                }


            }

        }

    }


    }