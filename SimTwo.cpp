#include "SimTwo.hpp"

SimTwo::SimTwo()
{
    std::queue<Infer*> ex;
    FileReaderAndWriter* object = new FileReaderAndWriter();
    ex = object->SimTwoFileReader();
    numOfDays = object->getNumOfDays();
    numOfCategories = object->getNumOfCategories();

    for(int i=0; i < numOfCategories; i++)
    {
        arr.push_back(ex.front());
        ex.pop();
   
    }

}

void SimTwo::randNumGen()
{
    int randNum =0;
  
    srand((unsigned) time(NULL));
    
    for(int i=0; i < numOfDays; i++)
    {
        randNum = rand() % 100 + 0;
        randNumHolder.push(randNum);
    }

}

double SimTwo::proceedSimulation()
{
    double total=0;
    int sumNum =0;
    

    for(int i =0; i < numOfCategories; i++)
    {
        arr[i]->randNumGen();
        total += arr[i]->getMean() * (arr[i]->getProb()/100.0);
        
    }

    return total;
}

double SimTwo::AModel()
{
    double total =0;
    for(int i=0; i < numOfCategories; i++)
    {
        total += arr[i]->getMeanAModel();
    }
    
    return total;
}

void SimTwo::Output()
{
    double sim = proceedSimulation();
    
    double Amodel = AModel();
    std::cout << "Simulated days: " << numOfDays << std::endl;
    std::cout << "Number of categories: " << numOfCategories << std::endl;
    std::cout << "Ranges and occurences in each range:\n ";

    for(int i=0; i < numOfCategories; i++)
    {
        std::cout << arr[i]->getStartInter() << "-" << arr[i]->getEndInter() <<": " << arr[i]->getProb() << std::endl;
    } 
    
    std::cout << "Units of measure: ml "<< std::endl;
    std::cout << "Analytical model: " << Amodel << "." << " Expected value is in the ";
    int j=0;
    for(int i=0; i < numOfCategories; i++)
    {
        if(arr[i]->check(Amodel))
        {
            j = i;
            std::cout << arr[i]->getStartInter() << "-" << arr[i]->getEndInter();
        }
    }
    std::cout << " ml range " << std::endl;

    if(sim < arr[j]->getEndInter())
    {
        sim = sim - 1500;
    }

    std::cout << "Simulation: " << sim << " Expected value is in the " << arr[j]->getStartInter() << "-" << arr[j]->getEndInter() << " ml range" << std::endl;

}

