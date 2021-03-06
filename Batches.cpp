#include "Batches.hpp"

Batches::Batches(bool checkBatch, int numOfItems, int percOfBadItems)
{
    this->checkBatch = checkBatch;
    this->numOfItems = numOfItems;
    this->percOfBadItems = percOfBadItems;
}

bool Batches::getCheckBatch()
{
    return checkBatch;
}

//replace the rand queue with a variable and a param for makeBatch() taking in a random # variable, go thru some incremental testing with this slow and steady 
void Batches::makeBatch(std::queue<int> randNumHolder)
{
    //if good fill queue with true so it'll print out all true for the batch
   // getRandomNum();
    if(checkBatch)
    {
        for(int i=0; i < numOfItems; i++)
        {
            batch.push(true);
        }
    }
    else 
    {
       
        for(int i=0; i < numOfItems; i++)
        {
            if(randNumHolder.front() <= percOfBadItems)
            {
                batch.push(false);
                numOfBadItems++;
            }
            else 
            {
                batch.push(true);
            }

            randNumHolder.pop();
        }
    }
}

std::queue<bool> Batches::getBatch()
{
    return batch;
}

int Batches::getNumOfItems()
{
    return numOfItems;
}

int Batches::getNumOfBadItems()
{
    return numOfBadItems;
}