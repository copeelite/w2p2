#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
    int totalPopulation{0};
    PcPopulation* aptr = nullptr;

    void printDuplicate(char line, int size)
    {
        for(int i = 0; i < size; i++)
        {
            cout << line;
        }
        cout << endl;
    }

    bool load(const char *filename){
        bool test = false;
        if(openFile(filename))
        {
            test = readTesters();
            if(test){
                //int totalRec = read(aptr);
                //totalRec = 15;
                int readTotalRec = read(aptr);
                cout << readTotalRec;

            }
        }
        else {
            cout << "Could not open data file: "<< filename << endl;

        }
        return test;




    }
    void display(const PcPopulation& a){
         cout << *a.m_postalCode<< ":  " << a.m_population << endl;
    }
    void display(){
        cout << "Postal Code: population" << endl;
        printDuplicate('-', 25);

        printDuplicate('-', 25);
        cout << "Population of Canada: " << totalPopulation;

    }

    void deallocateMemory(){
        for (int i = 0; i < 15; i++)
        {




        }

        delete[] aptr;
        aptr = nullptr;
    }
}