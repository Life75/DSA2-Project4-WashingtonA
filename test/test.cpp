#define CATCH_CONFIG_MAIN

#include <sstream>
#include <cstdlib>
#include "catch/catch.hpp"
#include <queue>

#include "../Batches.hpp"
#include "../FileReaderAndWriter.hpp"
#include "../SimOne.hpp"

TEST_CASE("Batches Class")
{
    Batches Batch(true, 100, 7);
    std::queue<bool> test;
    test = Batch.getBatch();
    while(!test.empty())
    {
        REQUIRE(test.front());
        test.pop();
    } 

    Batches BadBatch(false, 100, 7);
    test = BadBatch.getBatch();
    while(!test.empty())
    {
        //std::cout << test.front() << std::endl;
        test.pop();
    }


}

TEST_CASE("FileReaderAndWriter Class")
{
    FileReaderAndWriter* test = new FileReaderAndWriter();
    std::queue<int> specs;
    std::queue<Batches*> holder;
    specs = test->readFilesSimOne("t1.txt");
    REQUIRE(100 == specs.front());
    specs.pop();

    REQUIRE(2000 == specs.front());
    specs.pop();

    REQUIRE(24 == specs.front());
    specs.pop();

    REQUIRE(7 == specs.front());
    specs.pop();

    REQUIRE(30 == specs.front());
    specs.pop();
/*
    Batches* batch[100];
    for(int i=0; i< 100; i++)
    {
        batch[i] = new Batches(true, 50, 8);
        holder.push(batch[i]);
    }

    for(int i=0; i<100;i++)
    {
      test->writeFilesSimOne("t1.txt", batch[i], i );
    }
  */  
}

TEST_CASE("SimOne Class")
{
    SimOne* simOne = new SimOne();
    simOne->Output();
}

TEST_CASE("SimTwo Class")
{

}