#ifndef INFER_HPP_
#define INFER_HPP_

#include <iostream>
#include <sstream>
#include <queue>
/*
Banner Austyn Washington 
4/10/2020
Holds the value of the intervals and categories and calculating their respected mean values through the random generator also computes the analytical model data as well
Holds mostly getter and setters for retrievel and testing.
*/
class Infer 
{
    private:
    int category;
    int startInter;
    int endInter;
    int prob;
    int numOfDays;
    int mean;
    std::string units;
    std::queue<int> randNumHolder;
    public:
    Infer();
    void setCategory(int category);
    void randNumGen();
    void setData(std::string text); //parse in coming data 
    void parseData(std::string text);
    void setStartInter(int num);
    void setEndInter(int num);
    int getStartInter();
    int getEndInter();
    int getCategory();
    void setMean(int num);
    int getProb();
    double getMean();
    bool check(int num);
    double getMeanAModel();
    std::string getUnits();

};
#endif