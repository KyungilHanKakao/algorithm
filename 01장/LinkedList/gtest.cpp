// tests.cpp
#include "LinkedList.h"
#include <gtest/gtest.h>
TEST(SLL_Test, Full_Test)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;
    int Expected_Data1[] = {-2, -1, 0, 1, 2, 3, 4};
    int Expected_Data2[] = {-2, -1, 0, 3000, 1, 2, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data1[i], Current->Data);
    }

    //  리스트의 세번째 노드 뒤에 새 노드 삽입
    // printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data2[i], Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    // printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
}
TEST(SLL_Test, SLL_CreateNode)
{
    int *nullPtr = nullptr;
    Node *validPtr = SLL_CreateNode(5);

    EXPECT_EQ(nullPtr, nullptr);
    EXPECT_NE(typeid(validPtr), typeid(int));
    EXPECT_NE(typeid(validPtr), typeid(Node));
    EXPECT_EQ(typeid(validPtr), typeid(Node *));

    delete nullPtr;
    SLL_DestroyNode(validPtr);
}
TEST(SLL_Test, SLL_DestroyNode)
{
    Node *validPtr = SLL_CreateNode(5);
    EXPECT_EQ(typeid(validPtr), typeid(Node *));

    SLL_DestroyNode(validPtr);    // ! valgrind에서 해제 되는지 확인한다.
    EXPECT_NE(validPtr, nullptr); //! 메모리를 해젷해도 validPtr은 주소를 갖고 있다.
    // EXPECT_EQ(validPtr, nullptr);
}
TEST(SLL_Test, SLL_AppendNode)
{
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    NewNode = SLL_CreateNode(5);
    SLL_AppendNode(&List, NewNode);

    EXPECT_EQ(List, NewNode);

    SLL_DestroyNode(NewNode);
}
TEST(SLL_Test, SLL_InsertAfter)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;
    int Expected_Data[] = {0, 1, 2, 3000, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data[i], Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    // printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
}
TEST(SLL_Test, SLL_InsertNewHead)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;
    int Expected_Data[] = {-1, 0, 1, 2, 3, 4};
    int NonExpected_Data[] = {0, 1, 2, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data[i], Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    // printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
}
TEST(SLL_Test, SLL_RemoveNode)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    // Node *NewNode = NULL;
    int Expected_Data[] = {1, 2, 3, 4};
    int NonExpected_Data[] = {0, 1, 2, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        // NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, SLL_CreateNode(i));
    }

    Current = SLL_GetNodeAt(List, 0);
    SLL_RemoveNode(&List, Current);
    SLL_DestroyNode(Current); // ! 빼먹기 쉽다!!

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data[i], Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    // printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    // SLL_DestroyNode(NewNode);
    // SLL_DestroyNode(Current);
}
TEST(SLL_Test, SLL_DestroyAllNodes)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    // Node *NewNode = NULL;
    int Expected_Data[] = {0, 1, 2, 3, 4};
    int NonExpected_Data[] = {0, 1, 2, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        // NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, SLL_CreateNode(i));
    }

    SLL_DestroyAllNodes(&List);
}
TEST(SLL_Test, SLL_InsertBefore)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;
    int Expected_Data[] = {0, 1, 3000, 2, 3, 4};

    //  노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertBefore(&List, Current, NewNode);

    //  리스트 출력
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        // printf("List[%d] : %d\n", i, Current->Data);
        EXPECT_EQ(Expected_Data[i], Current->Data);
    }

    //  모든 노드를 메모리에서 제거
    // printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_CreateNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_DestroyNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_AppendNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertAfter";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertNewHead";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_RemoveNode";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_GetNodeAt";
    //::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_DestroyAllNodes";
    ::testing::GTEST_FLAG(filter) = "SLL_Test.SLL_InsertBefore";

    //::testing::GTEST_FLAG(filter) = "SLL_Test.*";
    //::testing::GTEST_FLAG(repeat) = 10;
    //::testing::FLAGS_gtest_repeat=10;
    //::testing::FLAGS_gtest_filter == "SLL_Test.*";

    return RUN_ALL_TESTS();
}