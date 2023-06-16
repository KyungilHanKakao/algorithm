#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack **Stack)
{
    // 스택을 자유 저장소에 생성
    (*Stack) = (LinkedListStack *)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

Node *LLS_CreateNode(const char *Data)
{
    Node *NewNode =(Node*)malloc(sizeof(Node));  //
    NewNode->Data =  (char*)malloc(sizeof(Data+1));
    NewNode->NextNode = NULL;
    return NewNode;
}

void LLS_Push(LinkedListStack *Stack, Node *NewNode)
{
    if (Stack->List == NULL)
    {
        Stack->List = NewNode;
    }
    else
    {
        // 스택의 Top에 신규 노드를 연결
        Stack->Top->NextNode = NewNode;
    }

    // 스택의 Top 필드에 새 노드의 주소를 등록
    Stack->Top = NewNode;
}

