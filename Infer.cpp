#include "Infer.hpp"

Infer::Infer()
{
    category = 0;
    startInter =-1;
    endInter =-1;
    prob = -1;
    numOfDays = -1;
}


void Infer::randNumGen()
{
    int randNum =0;
  
    srand((unsigned) time(NULL));
    for(int i=0; i < prob; i++)
    {
        randNum = rand() % endInter + startInter;
        randNumHolder.push(randNum);
    }

}

void Infer::setCategory(int num)
{
    this->category = num;
}

void Infer::setData(std::string text)
{
    if(text != "ml")
    {
        parseData(text);
    }
    else
    {
        
        units = text;
    }
}

void Infer::parseData(std::string text)
{
    std::stringstream check1(text);
    std::string data;
    std::vector <std::string> tokens;
    while(getline(check1, data, ':'))
    {
        tokens.push_back(data);
    }
    

    data = tokens[1];

    prob = stoi(data); 
    data = tokens[0];
    tokens.clear();
    check1.str("");

    
    std::stringstream check2(data);
    std::string example;
    while(getline(check2, example, '-'))
    {
        tokens.push_back(example);
    }

    startInter = stoi(tokens[0]);
    endInter = stoi(tokens[1]);
}

bool Infer::check(int num)
{
    if(num >= startInter && num <= endInter)
    {
        return true;
    } 
    else return false;
     
}

int Infer::getStartInter()
{
    return startInter;
}



int Infer::getCategory()
{
    return category;
}

int Infer::getEndInter()
{
    return endInter;
}

int Infer::getProb()
{
    return prob;
}

void Infer::setStartInter(int num)
{
    startInter = num;
}

void Infer::setEndInter(int num)
{
    endInter = num;
}

double Infer::getMean()
{
    double total =0;
    for(int i=0; i < prob; i++)
    {
        total += randNumHolder.front();
        randNumHolder.pop();
    }
    total = total / (double)prob;
    return total;
}

void Infer::setMean(int num)
{
     mean = num;
} 

double Infer::getMeanAModel()
{
    double total =0;
    total = ((startInter + endInter) / 2) * ((double)(prob) /100);
    return total;
}

std::string Infer::getUnits()
{
    return units;
}