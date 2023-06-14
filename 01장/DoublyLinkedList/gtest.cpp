#include "DoublyLinkedList.h"
#include <gtest/gtest.h>

TEST(DLL_Test, DLL_CreateNode)
{
    Node *List = NULL;
    ElementType data = 1;

    List = DLL_CreateNode(data);
    EXPECT_EQ(List->Data, data);

    DLL_DestroyNode(List);
}
TEST(DLL_Test, DLL_AppendNode)
{
    Node *List = NULL;
    Node *NewNode = NULL;
    ElementType Expected_Data[] = {1, 2};

    List = DLL_CreateNode(1);
    NewNode = DLL_CreateNode(2);

    DLL_AppendNode(&List, NewNode);
    for (size_t i = 0; i < 2; i++)
    {
        EXPECT_EQ(DLL_GetNodeAt(List, i)->Data, Expected_Data[i]);
    }

    DLL_DestroyAllNodes(&List);
}

TEST(DLL_Test, DLL_InsertAfter)
{
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;
    ElementType data = 1;
    ElementType Expected_Data[] = {0, 1, 2, 3000, 3, 4};

    //  노드 5개 추가
    for (int i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    for (size_t i = 0; i < 6; i++)
    {
        EXPECT_EQ(DLL_GetNodeAt(List, i)->Data, Expected_Data[i]);
    }

    DLL_DestroyAllNodes(&List);

}

TEST(DLL_Test, DLL_RemoveNode)
{
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Remove = NULL;
    ElementType data = 1;
    ElementType Expected_Data[] = {0, 1,  3, 4};
    ElementType Error_Data[] = {1, 2,  4, 5};

    //  노드 5개 추가
    for (int i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Remove = DLL_GetNodeAt(List, 2);
    
    DLL_RemoveNode(&List, Remove);

    for (size_t i = 0; i < 4; i++)
    {
        EXPECT_EQ(DLL_GetNodeAt(List, i)->Data, Expected_Data[i]);
        EXPECT_NE(DLL_GetNodeAt(List, i)->Data, Error_Data[i]);
        if (i<3)
        {
            EXPECT_EQ(DLL_GetNodeAt(List, i)->Data, DLL_GetNodeAt(List, i+1)->PrevNode->Data);
        }
        
        
    }

    DLL_DestroyAllNodes(&List);

}
/*
TEST(DLL_Test, DLL_GetNodeAt)
{
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;
    ElementType data = 1;
    ElementType Expected_Data[] = {0, 1, 2, 3, 4};

    Current = DLL_GetNodeAt(List, 2);

    //! that statement cannot catch a segmentation fault.
    // Segmentation faults are a system level thing and can cause undefined behavior.
    // Exceptions are a lot easier to handle. I am still looking for ways to address this,
    // but having separate executables is the way for now.
    // By default, Googletest does catch *exceptions* thrown by a test and continue with the next test


    //  노드 5개 추가
    for (int i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);
}
TEST(DLL_Test, Full_Test)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    //  리스트 출력
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    //  리스트의 세번째 칸 뒤에 노드 삽입
    printf("\nInserting 3000 After [2]...\n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    //  리스트 출력
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    printf("\nDestroying List...\n");

    Count = DLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }
}
*/
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "DLL_Test.Full_Test";
    //::testing::GTEST_FLAG(filter) = "DLL_Test.DLL_CreateNode";
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
