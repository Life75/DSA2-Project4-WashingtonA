#ifndef SIMONE_HPP_
#define SIMONE_HPP_

#include <iostream>
#include <queue>
#include "Batches.hpp"
#include "FileReaderAndWriter.hpp"
//Banner
class SimOne
{
    private:
    int simulationNumber =0;
    int numOfBatches, numOfItems, percOfBadItems, itemsSampled, percOfBadBatches;
    std::queue<bool> batchChance;
    void genBatchChance();
    
    public:
    SimOne();
    void simulationProceed(std::string fileName);
    void Output();

};
#endif