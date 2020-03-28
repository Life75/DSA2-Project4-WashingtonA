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

void FileReaderAndWriter::writeFilesSimOne(std::string fileName, std::queue<Batches*> vect)
{
    //Makes Linux directories 
    std::fstream file;
    std::ostringstream os; 
    int batchNum =0;
  
    std::queue<bool> checker;
    while(!vect.empty())
    {
        checker =  vect.front()->getBatch();
        std::ofstream fout;
    
    if(fileName == "t1.txt")
    {
        if(mkdir("t1 Batches", 0777) ==-1)
        {

        }
        
        os << "t1 Batches/ds" << batchNum << ".txt";

        
        fout.open(os.str(), std::ios::out);
        while(!checker.empty())
        {
            if(checker.front())
            {
                fout << 'G' << std::endl;
            }
            else fout << 'B' << std::endl;
            checker.pop();
        }
        batchNum++;
    fout.close();
    vect.pop();
    }
    }
    
    /*
    if(fileName == "t2.txt")
        if(mkdir("t2 Batches", 0777) ==-1)
        {
            
        }

    if(fileName == "t3.txt")
        if(mkdir("t3 Batches", 0777) ==-1)
        {
            
        }

    if(fileName == "t4.txt")
        if(mkdir("t4 Batches", 0777) ==-1)
        {
            
        }
*/
    
}