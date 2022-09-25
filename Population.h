#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include <cstdio>
namespace sdds {

    struct PcPopulation {
        char* m_postalCode;
        int* m_population;

    };

    bool load(const char *filename);
    void display();
    void deallocateMemory();
    void sort();

}
#endif // SDDS_POPULATION_H_