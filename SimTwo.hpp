#ifndef SIMTWO_HPP_
#define SIMTWO_HPP_



#include <iostream>
#include "Infer.hpp"
#include "FileReaderAndWriter.hpp"
#include <queue>

/*
Banner Austyn Washington 
4/10/2020
Computes the data given from FileReaderAndWriter passed through the file. Does the analytical and simulated models and then properly places
them in Output() for display  
*/
class SimTwo
{
    private:
    int numOfDays;
    int numOfCategories;
    std::vector<Infer*> arr;
    std::queue<int> randNumHolder;

    public:
    SimTwo();
    void randNumGen();
    void proceedAnalyticalModel();
    double proceedSimulation();
    double AModel();
    void Output();


};
#endif