// tests.cpp
#include "ExpressionTree.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

TEST(ET_Test, ET_CreateNode)
{
}
TEST(ET_Test, ET_DestroyNode)
{
}
TEST(ET_Test, ET_PreorderPrintTree)
{
}
TEST(ET_Test, ET_InorderPrintTree)
{
    ETNode *node;
    //char *postExp = "12+34-*";
    char postExp[] = "12+34-*";

    ET_BuildExpressionTree(postExp, &node);
    ET_PostorderPrintTree(node);
}
TEST(ET_Test, ET_PostorderPrintTree)
{
}
TEST(ET_Test, ET_BuildExpressionTree)
{
}
TEST(ET_Test, ET_Evaluate)
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