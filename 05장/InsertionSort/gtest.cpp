// tests.cpp
#include "InsertionSort.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

TEST(ET_Test, ET_CreateNode)
{

    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int ExpectData[] ={1,2,3,4,5,6};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    InsertionSort(DataSet, Length);

    for (i = 0; i < Length; i++)
    {
        EXPECT_EQ(ExpectData[i] , DataSet[i]);
        
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_CreateNode";
    //::testing::GTEST_FLAG(repeat) = 10;
    //::testing::FLAGS_gtest_repeat=10;
    //::testing::FLAGS_gtest_filter == "SLL_Test.*";

    return RUN_ALL_TESTS();
}