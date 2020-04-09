#include "FileReaderAndWriter.hpp"

FileReaderAndWriter::FileReaderAndWriter()
{

}

//returns a queue with the given specs of the file to use in simOne
std::queue<int> FileReaderAndWriter::readFilesSimOne(std::string fileName)
{ 
    std::queue<int> specs;
    std::fstream file;
    file.open(fileName.c_str());
    int holder =0;
    
    while(file >> holder)
    {
        specs.push(holder);
    }
    return specs;
}

void FileReaderAndWriter::writeFilesSimOne(std::string fileName, Batches* batch, int batchNum)
{
    //Makes Linux directories 
    std::fstream file;
    std::ostringstream os; 
    std::queue<bool> checker;
    checker = batch->getBatch();

    
    if(fileName == "t1.txt")
    {
        if(mkdir("t1_Batches", 0777) ==-1)
        {

        }
            os << "t1_Batches/ds" << batchNum << ".txt";
            //std::cout << batchNum << std::endl;
            std::ofstream fout(os.str());

        while(!checker.empty())
        {
            if(checker.front())
            {
                fout << "G";
            }
            else 
            {
                fout << "B";
            }
            fout << std::endl;
            checker.pop();

        }
        fout.close();

    }

    if(fileName == "t2.txt")
    {
        if(mkdir("t2_Batches", 0777) == -1)
        {

        }
            os << "t2_Batches/ds" << batchNum << ".txt";
            //std::cout << batchNum << std::endl;
            std::ofstream fout(os.str());

        while(!checker.empty())
        {
            if(checker.front())
            {
                fout << "G";
            }
            else 
            {
                fout << "B";
            }
            fout << std::endl;
            checker.pop();

        }
        fout.close();

    }

    if(fileName == "t3.txt")
    {
        if(mkdir("t3_Batches", 0777) == -1)
        {

        }
            os << "t3_Batches/ds" << batchNum << ".txt";
            //std::cout << batchNum << std::endl;
            std::ofstream fout(os.str());

        while(!checker.empty())
        {
            if(checker.front())
            {
                fout << "G";
            }
            else 
            {
                fout << "B";
            }
            fout << std::endl;
            checker.pop();

        }
        fout.close();

    }

    if(fileName == "t4.txt")
    {
        if(mkdir("t4_Batches", 0777) == -1)
        {

        }
            os << "t4_Batches/ds" << batchNum << ".txt";
            //std::cout << batchNum << std::endl;
            std::ofstream fout(os.str());

        while(!checker.empty())
        {
            if(checker.front())
            {
                fout << "G";
            }
            else 
            {
                fout << "B";
            }
            fout << std::endl;
            checker.pop();

        }
        fout.close();

    }

}

void FileReaderAndWriter::analyzeDataSets(std::string filename, int itemsSampled, int numOfBatches)
{
    std::fstream file;
    std::ostringstream os;
    std::string item;
    bool badBatch =false;

    std::cout << "Analyszing Data Sets: \n";

    for(int i=0; i < numOfBatches; i++)
    {
        if(filename == "t1.txt")
        {
            os << "t1_Batches/ds" << i << ".txt";
            file.open(os.str().c_str());
            for(int j=0; j < itemsSampled; j++)
            {
                file >> item;
                if(item == "B")
                {
                    badBatch = true;
                    std::cout << "hello\n";
                }
            }
            if(badBatch)
            {
                std::cout << "batch # " << i << " is bad\n";
            }
            badBatch = false;
        }    
    }
    
}


    
