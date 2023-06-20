// tests.cpp
#include "QuickSort.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

TEST(QS_Test, QS_QuickSort)
{

    int DataSet[] = {5,6, 4, 2, 3, 1};
    int ExpectDataSet[] = {1, 2, 3, 4, 5, 6};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length - 1);

    for (i = 0; i < Length; i++)
    {
        EXPECT_EQ(DataSet[i],ExpectDataSet[i]);
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