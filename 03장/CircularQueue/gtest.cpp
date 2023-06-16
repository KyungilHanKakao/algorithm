// tests.cpp
#include "CircularQueue.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

TEST(Calculator_Test, CQ_CreateQueue)
{
    CircularQueue *queue;
    CQ_CreateQueue(&queue, 8);

    CQ_DestroyQueue(queue);
}
TEST(Calculator_Test, CQ_DestroyQueue)
{
}
TEST(Calculator_Test, CQ_Enqueue)
{
    int ExpectData[]={0,1,2,3,4,5,6,7};
    CircularQueue *queue;
    CQ_CreateQueue(&queue, 8);

    for (size_t i = 0; i < 10; i++)
    {
        CQ_Enqueue(queue, i);
        std::cout<<CQ_GetSize(queue)<<std::endl;
    }

    for (size_t i = 0; i < 3; i++)
    {
        EXPECT_EQ(CQ_Dequeue(queue),ExpectData[i]);
        std::cout<<CQ_GetSize(queue)<<std::endl;
    }
    for (size_t i = 10; i < 20; i++)
    {
        CQ_Enqueue(queue, i);
        std::cout<<CQ_GetSize(queue)<<std::endl;
    }
    


    CQ_DestroyQueue(queue);
}
TEST(Calculator_Test, CQ_Dequeue)
{

}
TEST(Calculator_Test, CQ_GetSize)
{
}
TEST(Calculator_Test, CQ_IsEmpty)
{
}
TEST(Calculator_Test, CQ_IsFull)
{
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