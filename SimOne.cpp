#include "SimOne.hpp"


SimOne::SimOne()
{

}

SimOne::SimOne(int numOfBatches, int numOfItems)
{
    numOfBatches = numOfBatches;
    numOfItems = numOfItems;
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

/*
Create a function to create rand for batches and weave it thru into the Batches class giving better random results because every function call to  getRandNum is good enough randoming 
so numOfBatches * 
*/

void SimOne::randGen()
{
    int totalRand = numOfBatches * numOfItems;
    if(randNumHolder.empty())
    {
        srand((unsigned) time(NULL));
        for(int i=0; i < totalRand; i++)
        {
            int randNum = rand() % 100 + 0;
            randNumHolder.push(randNum);
         //   std::cout << i << "\n";
        }
    }
}
//parses the data and returns a queue for it 
std::queue<int> SimOne::randGenParser()
{
    std::queue<int> parse;
    int rand =0;
    for(int i=0; i < numOfItems; i++)
    {
        rand = randNumHolder.front();
        parse.push(rand);
        randNumHolder.pop();
    }
    return parse;
}

void SimOne::simulationProceed(std::string fileName)
{
    simulationNumber++;
    FileReaderAndWriter* test = new FileReaderAndWriter();
    std::queue<int> specs;
    std::queue<Batches*> holdBatches;
    numOfBadBatches =0;
    
    specs = test->readFilesSimOne(fileName);

    numOfBatches = specs.front();
    specs.pop();

    numOfItems = specs.front();
    specs.pop();

    percOfBadBatches = specs.front();
    specs.pop();

    percOfBadItems = specs.front();
    specs.pop();

    itemsSampled = specs.front();
    specs.pop();

    genBatchChance();
    randGen();


    std::cout << "Simulation " << simulationNumber << ": \n";
    std::cout << "Number of items in each batch: " << numOfItems << std::endl;
    std::cout << "Percentage of batches containing bad items: " << percOfBadBatches << "%" << std::endl;
    std::cout << "Percentage of items that are bad in a bad set: " << percOfBadItems << "%" << std::endl;
    std::cout << "Items sampled from each set: " << itemsSampled << std::endl;
    
    std::cout << std::endl;
    std::cout << "Generating data sets: \n";
    std::cout << std::endl;

    for(int i=0; i < numOfBatches; i++)
    {
        Batches* batch;
        if(batchChance.front())
        {
            batch = new Batches(true, numOfItems, percOfBadItems);
            batch->makeBatch(randGenParser());
        }
        else
        {
            batch = new Batches(false, numOfItems, percOfBadItems);
            numOfBadBatches++;
            batch->makeBatch(randGenParser());
          
            std::cout << "Create bad set batch # " << i << ", totBad = " << batch->getNumOfBadItems()
            << " total = " << numOfItems << " badpct = " << percOfBadItems << "%" << std::endl;
        }
        holdBatches.push(batch);
        test->writeFilesSimOne(fileName, batch, i);
        batchChance.pop();
    }
    std::cout << "Total bad sets = " << numOfBadBatches << std::endl;
    std::cout << std::endl;
}

void SimOne::Output()
{
    FileReaderAndWriter* test = new FileReaderAndWriter();
    
    simulationProceed("t1.txt"); 
    test->analyzeDataSets("t1.txt", itemsSampled, numOfBatches, percOfBadItems, numOfBadBatches);
    
    simulationProceed("t2.txt");
    test->analyzeDataSets("t2.txt", itemsSampled, numOfBatches, percOfBadItems, numOfBadBatches);
    
    simulationProceed("t3.txt");
    test->analyzeDataSets("t3.txt", itemsSampled, numOfBatches, percOfBadItems, numOfBadBatches);

    simulationProceed("t4.txt");
    test->analyzeDataSets("t4.txt", itemsSampled, numOfBatches, percOfBadItems, numOfBadBatches);
}