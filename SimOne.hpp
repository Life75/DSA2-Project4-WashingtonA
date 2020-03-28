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
    int numOfBatches =0;
    int percOfBadBatches =0;
    std::queue<bool> batchChance;
    void genBatchChance();
    
    public:
    SimOne();
    void simulationProceed(std::string fileName);

};
#endif