#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include <cstdio>
namespace sdds {

    struct PcPopulation {
        char* m_postalCode;
        int* m_population;

    };


    void display();
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_