#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct PcPopulation {

        char* m_postalCode;
        int* m_population;
    };

    void printDuplicate(char line, int size);
    bool load(const char filename[]);
    void display();
    void deallocateMemory();
    void display(const PcPopulation& a);

}
#endif // SDDS_POPULATION_H_