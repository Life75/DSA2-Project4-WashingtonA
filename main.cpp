#include "FileReaderAndWriter.hpp"
#include "Batches.hpp"
#include "SimTwo.hpp"
#include "SimOne.hpp"
#include "Infer.hpp"
/*
Banner Austyn Washington 
4/10/2020
Computes the data given from the text files and prints them out from main 
*/

int main()
{
    SimTwo* simTwo = new SimTwo();
    SimOne* simOne = new SimOne();

    simOne->Output();
    simTwo->Output();
}