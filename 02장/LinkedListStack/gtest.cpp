// tests.cpp
#include "LinkedListStack.h"
#include <gtest/gtest.h>

TEST(LLS_Test, LLS_CreateStack)
{
    
}
TEST(LLS_Test, LLS_DestroyStack)
{
    
}
TEST(LLS_Test, LLS_CreateNode)
{

}
TEST(LLS_Test, LLS_DestroyNode)
{
    
}
TEST(LLS_Test, LLS_Push)
{    
}
TEST(LLS_Test, LLS_Pop)
{
    int i= 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;

    LLS_CreateStack(&Stack);
    
    Node* pushed = LLS_CreateNode("abc");

    int a= 0;

    LLS_Push( Stack, pushed );
    LLS_Push( Stack, LLS_CreateNode("def") );
    LLS_Push( Stack, LLS_CreateNode("efg") );
    LLS_Push( Stack, LLS_CreateNode("hij") );

    //Popped = LLS_Pop( Stack );
    //LLS_DestroyNode(Popped);
    //LLS_DestroyStack(Stack);
    
}
TEST(LLS_Test, LLS_Top)
{

}
TEST(LLS_Test, LLS_GetSize)
{
    
}
TEST(LLS_Test, LLS_IsEmpty)
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