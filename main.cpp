#include "FileReaderAndWriter.hpp"
#include "Batches.hpp"

int main()
{
    FileReaderAndWriter* test = new FileReaderAndWriter();

    Batches* batch[5];
    for(int i=0; i< 5; i++)
    {
        //the middle param is the amount of items per batch: try the values of 20 and 50
        //20 will actually print out fine, but 50 doesn't want to come out right
        batch[i] = new Batches(true, 50, 8);
    }

    for(int i=0; i< 5; i++)
    {
        test->writeFilesSimOne("t1.txt", batch[i], i);
    }
}