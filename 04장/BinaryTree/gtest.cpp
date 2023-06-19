// tests.cpp
#include "BinaryTree.h""
#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>


TEST(SBT_Test, SBT_CreateNode)
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
TEST(SBT_Test, SBT_DestroyNode)
{

}
TEST(SBT_Test, SBT_DestroyTree)
{
}
TEST(SBT_Test, SBT_PreorderPrintTree)
{
}
TEST(SBT_Test, SBT_InorderPrintTree)
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