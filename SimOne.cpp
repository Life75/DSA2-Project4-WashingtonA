#include "SimOne.hpp"


SimOne::SimOne()
{

}

void SimOne::genBatchChance()
{
    int randNum =0;
    srand((unsigned) time(NULL)); 
        for(int i=0; i < numOfBatches; i++)
        {
            randNum = rand() % 100 + 0;
            if(randNum <= percOfBadBatches)
            {
                batchChance.push(false);
                //std::cout << "Hello\n";
                //outputToConsole(i);
            }
            else batchChance.push(true);
        }
}

void SimOne::simulationProceed(std::string fileName)
{
    FileReaderAndWriter* test = new FileReaderAndWriter();
    std::queue<int> specs;
    std::queue<Batches*> holdBatches;
    
    specs = test->readFilesSimOne(fileName);

    numOfBatches = specs.front();
    specs.pop();

    int numOfItems = specs.front();
    specs.pop();

    percOfBadBatches = specs.front();
    specs.pop();

    int percOfBadItems = specs.front();
    specs.pop();

    int itemsSampled = specs.front();
    specs.pop();

    genBatchChance();

    for(int i=0; i < numOfBatches; i++)
    {
        Batches* batch;
        if(batchChance.front())
        {
            batch = new Batches(true, numOfItems, percOfBadItems);
        }
        else
        {
            batch = new Batches(false, numOfItems, percOfBadItems);
        }
        holdBatches.push(batch);
        batchChance.pop();
    }
    //test->writeFilesSimOne(fileName, holdBatches);
}