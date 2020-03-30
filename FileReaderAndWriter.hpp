#ifndef FilEREADERANDWRITER_HPP_
#define FilEREADERANDWRITER_HPP_
#include <iostream>
#include <queue>
#include <fstream>
#include "Batches.hpp"
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>

class FileReaderAndWriter
{
    private:
  
    public:
    FileReaderAndWriter();
    std::queue<int> readFilesSimOne(std::string fileName);
    void writeFilesSimOne( std::string fileName,  Batches* batch, int batchNum);
};
#endif 