#ifndef BATCHES_HPP_
#define BATCHES_HPP_

#include <iostream>
#include <queue>

/*
Banner Austyn Washington 
4/10/2020
Holds the data for the batches to create and generate random items 
*/
class Batches
{
    private:
    //std::queue<int> randNumHolder;
    std::queue<bool> batch;
    int numOfItems=0;
    bool checkBatch = true;
    int percOfBadItems=0;
    int numOfBadItems =0;

    
    public:
    Batches(bool checkBatch, int numOfItems, int percOfBadItems);
    bool getCheckBatch();
    void getRandomNum(); 
    std::queue<bool> getBatch();
    int getNumOfItems();
    int getNumOfBadItems();
    void makeBatch(std::queue<int> randNumHolder);


};
#endif 