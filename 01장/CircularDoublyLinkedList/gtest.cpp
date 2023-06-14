#include "CircularDoublyLinkedList.h"
#include <gtest/gtest.h>

TEST(CDLL_Test, CDLL_CreateNode)
{
    Node *List = NULL;
    ElementType data = 1;

    List = CDLL_CreateNode(data);
    EXPECT_EQ(List->Data, data);
    CDLL_DestroyNode(List);
}
TEST(CDLL_Test, CDLL_AppendNode)
{
    Node *List = NULL;
    ElementType data = 1;
    ElementType ExpectData[]={0,1,2,3,4};

    for (size_t i = 0; i < 5; i++)
    {
        CDLL_AppendNode(&List,CDLL_CreateNode(i));
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        EXPECT_EQ(CDLL_GetNodeAt(List,i)->Data, ExpectData[i]);
    }


    CDLL_DestroyAllNodes(&List);
}
TEST(CDLL_Test, CDLL_RemoveNode)
{
    Node *List = NULL;
    Node *Remove = NULL;
    ElementType data = 1;
    ElementType ExpectData[]={0,1,3,4};

    for (size_t i = 0; i < 5; i++)
    {
        CDLL_AppendNode(&List,CDLL_CreateNode(i));
    }
    Remove = CDLL_GetNodeAt(List, 2);

    CDLL_RemoveNode(&List,Remove);

    for (size_t i = 0; i < 3; i++)
    {
        EXPECT_EQ(CDLL_GetNodeAt(List,i)->Data, ExpectData[i]);
    }


    CDLL_DestroyAllNodes(&List);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "CDLL_Test.CDLL_CreateNode";
    //::testing::GTEST_FLAG(filter) = "CDLL_Test.CDLL_AppendNode";
    //::testing::GTEST_FLAG(filter) = "DLL_Test.DLL_GetNodeAt";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_DestroyNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_AppendNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertAfter";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertNewHead";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_RemoveNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_GetNodeAt";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_DestroyAllNodes";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertBefore";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.*";
    //::testing::GTEST_FLAG(repeat) = 10;
    //::testing::FLAGS_gtest_repeat=10;
    //::testing::FLAGS_gtest_filter == "SLL_Test.*";

    return RUN_ALL_TESTS();
}
