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
    Batches* batch = new Batches(false, 20, 8);
    //test->writeFilesSimOne(2, batch, "t1.txt" );
}

TEST_CASE("SimOne Class")
{
    SimOne* simOne = new SimOne();
    simOne->simulationProceed("t1.txt"); 
    
}

TEST_CASE("SimTwo Class")
{

}