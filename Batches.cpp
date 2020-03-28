#include "Batches.hpp"

Batches::Batches(bool checkBatch, int numOfItems, int percOfBadItems)
{
    this->checkBatch = checkBatch;
    this->numOfItems = numOfItems;
    this->percOfBadItems = percOfBadItems;
}

void Batches::getRandomNum()
{
    if(randNumHolder.empty())
    {
        srand((unsigned) time(NULL)); 
        for(int i=0; i < numOfItems; i++)
        {
            int randNum = rand() % 100 + 0;
            //std::cout << randNum << std::endl;
            randNumHolder.push(randNum);
        }
    }
}

bool Batches::getCheckBatch()
{
    return checkBatch;
}

std::queue<bool> Batches::getBatch()
{
    //if good fill queue with true so it'll print out all true for the batch
    getRandomNum();
    std::queue<bool> batch;
    if(checkBatch)
    {
        for(int i=0; i < numOfItems; i++)
        {
            batch.push(true);
        }
    }
    else 
    {
        for(int i= 0; i < numOfItems; i++)
        {
            if(randNumHolder.front() <= percOfBadItems)
            {
                batch.push(false);
            }
            else batch.push(true);
            randNumHolder.pop();
        }
    }
    return batch;
}

