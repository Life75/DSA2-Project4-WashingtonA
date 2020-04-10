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
    int numOfBadBatches =0;
    int numOfBatches, numOfItems, percOfBadItems, itemsSampled, percOfBadBatches;
    std::queue<bool> batchChance;
    std::queue<int> randNumHolder;
    void genBatchChance();
    
    public:
    SimOne();
    SimOne(int numOfBatches, int numOfItems);
    void simulationProceed(std::string fileName);
    void randGen();
    std::queue<int> randGenParser();
    void Output();

};
#endif