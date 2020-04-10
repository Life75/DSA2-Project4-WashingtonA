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
                fout << 'G';
            }
            else 
            {
                fout << 'B';
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

void FileReaderAndWriter::analyzeDataSets(std::string filename, int itemsSampled, int numOfBatches, int percOfBadItems, int numOfBadBatches)
{
    std::fstream file;
    char item = 'B';
    bool badBatch =false;
    std::string nameOfFile;
    double numOfFoundBadBatches =0;

    std::cout << "Analyszing Data Sets: \n";
    //std::cout << numOfBatches;
    for(int i=0; i < numOfBatches; i++)
    {   
        if(filename == "t1.txt")
        {
            std::ostringstream os;
            os << "t1_Batches/ds" << i << ".txt";            
            nameOfFile = os.str();
        }

        if(filename == "t2.txt")
        {
            std::ostringstream os;
            os << "t2_Batches/ds" << i << ".txt";            
            nameOfFile = os.str();
        }

        if(filename == "t3.txt")
        {
            std::ostringstream os;
            os << "t3_Batches/ds" << i << ".txt";            
            nameOfFile = os.str();
        }

        if(filename == "t4.txt")
        {
            std::ostringstream os;
            os << "t4_Batches/ds" << i << ".txt";            
            nameOfFile = os.str();
        }
            file.open(nameOfFile);
            
            int j=0;
            for(int k =0; k < itemsSampled; k++)
            {
                file >> item;
                if(item == 'B')
                {
                    badBatch = true;
                }
            }
            if (badBatch)
            {
                std::cout << "Bad Batch # " << i << "  \n";
                badBatch = false; 
                numOfFoundBadBatches++;
            }

            file.close();   
    }
    double percDoubBadItems = 0;
    double percentageOfBadItems =0;
    double baseCalc =0;
    double exponent =0;
    double pFailure =0;
    double percentageOfActualBadBatches =0;

    percDoubBadItems += percOfBadItems;
    percentageOfBadItems += percDoubBadItems / 100;
    baseCalc += 1 - percentageOfBadItems;
    exponent += itemsSampled;
    pFailure += pow(baseCalc, exponent);   
    percentageOfActualBadBatches +=  numOfFoundBadBatches /numOfBadBatches; 
    
    std::cout << "Base: " << baseCalc << " exponent: " << exponent << std::endl;
    std::cout << "P(failure to detect bad batch) = " << pFailure <<std::endl;
    std::cout << "Percentage of bad batches actually detected = " << percentageOfActualBadBatches << std::endl;


    
}


    
