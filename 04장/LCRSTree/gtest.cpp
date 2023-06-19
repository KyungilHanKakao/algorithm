// tests.cpp
#include "LinkedQueue.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>


TEST(LC_Test, LQ_CreateQueue)
{
    const char* sample[]={"abc","def","ghi","jkl","mno"};
    LinkedQueue* Queue;
    Node* node;

    LQ_CreateQueue(&Queue);
    

    for (size_t i = 0; i < 5; i++)
    {
        node=LQ_CreateNode((char*)sample[i]);
        LQ_Enqueue(Queue,node);
    }
    for (size_t i = 0; i < 5; i++)
    {
        node=LQ_Dequeue(Queue);
        std::cout<<node->Data<<std::endl;
        LQ_DestroyNode(node);
    }
    


    LQ_DestroyQueue(Queue);
}
TEST(LC_Test, LQ_DestroyQueue)
{

}
TEST(LC_Test, LQ_CreateNode)
{
}
TEST(LC_Test, LQ_DestroyNode)
{
}
TEST(LC_Test, LQ_Enqueue)
{

}
TEST(LC_Test, LQ_Dequeue)
{
}
TEST(LC_Test, LQ_IsEmpty)
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