#ifndef BATCHES_HPP_
#define BATCHES_HPP_

#include <iostream>
#include <queue>

//Banner
class Batches
{
    private:
    std::queue<int> randNumHolder;
    int numOfItems=0;
    bool checkBatch = true;
    int percOfBadItems=0;
    
    public:
    Batches(bool checkBatch, int numOfItems, int percOfBadItems);
    bool getCheckBatch();
    void getRandomNum(); 
    std::queue<bool> getBatch();
    int getNumOfItems();

};
#endif 