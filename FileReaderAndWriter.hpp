#ifndef FilEREADERANDWRITER_HPP_
#define FilEREADERANDWRITER_HPP_
#include <iostream>
#include <queue>
#include <fstream>
#include "Batches.hpp"
#include "Infer.hpp"
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>
/*
Banner Austyn Washington 
4/10/2020
Reads the data from the text files and passes them to other classes for review. Prints the data as well that's recieved from the classes 
*/
class FileReaderAndWriter
{
    private:
    int numOfDays, numOfCategories;
  
    public:
    FileReaderAndWriter();
    std::queue<int> readFilesSimOne(std::string fileName);
    void writeFilesSimOne( std::string fileName,  Batches* batch, int batchNum);
    void analyzeDataSets(std::string fileName, int itemsSampled, int numOfBatches, int percOfBadItems, int numOfBadBatches);
    std::queue<Infer*> SimTwoFileReader();
    int getNumOfDays();
    int getNumOfCategories();

};
#endif 