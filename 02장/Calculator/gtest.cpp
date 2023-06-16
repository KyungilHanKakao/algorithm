// tests.cpp
#include "LinkedListStack.h"
#include "Calculator.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>


TEST(Calculator_Test, IsNumber)
{
}
TEST(Calculator_Test, GetNextToken)
{
}
TEST(Calculator_Test, IsPrior)
{
}
TEST(Calculator_Test, GetPostfix)
{
}
TEST(Calculator_Test, FullTest)
{


    char InfixExpression[100];
    char PostfixExpression[100];

    double Result = 0.0;

    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    printf("Enter Infix Expression: ");
    scanf("%s", InfixExpression);

    GetPostfix(InfixExpression, PostfixExpression);

    printf("Infix:%s\nPostfix:%s\n", InfixExpression, PostfixExpression);

    Result = Calculate(PostfixExpression);

    printf("Calculation Result : %f\n", Result);
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