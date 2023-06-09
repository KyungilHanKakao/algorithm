#include "LinkedList.h"

//  노드 생성
Node *SLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));

    NewNode->Data = NewData;  //  데이터를 저장한다.
    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화 한다.

    return NewNode; //  노드의 주소를 반환한다.
}

/** 노드 소멸
 Simple ansewr:
 you can't check if a pointer has been freed already in C.
 Different behaviors are probably due to different compilers,
 as using a pointer after freeing it is undefined you can get all sorts of behavior
 (including a SEGFAULT and program termination).

If you want to check if you use free property and your program is memory leak free,
then use a tool like Valgrind.
*/
void SLL_DestroyNode(Node *Node)
{
    free(Node);
    Node = NULL;
}

// ! Node** 인것에 주의  노드 추가
void SLL_AppendNode(Node **Head, Node *NewNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        //  테일을 찾아 NewNode를 연결한다.
        Node *Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

//  노드 삽입
void SLL_InsertAfter(Node *Current, Node *NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
    if (Head == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

//  !  노드 제거 - 이해가 어려움
void SLL_RemoveNode(Node **Head, Node *Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node *Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}

//  노드 탐색
Node *SLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

//  노드 수 세기
int SLL_GetNodeCount(Node *Head)
{
    int Count = 0;
    Node *Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

void SLL_InsertBefore(Node **Head, Node *Current, Node *NewHead)
{
    if (*Head==Current)
    {
        NewHead->NextNode = Current;
        *Head=NewHead;
    }
    else
    {
        Node* find = *Head;
        while (find->NextNode!=Current)
        {
            find=find->NextNode;
        }
        if(find->NextNode == Current)
        {
            find->NextNode=NewHead;
            NewHead->NextNode=Current;
        }
        
    }
    
    
    //NewNode->NextNode = Current->NextNode;
    //Current->NextNode = NewNode;
}
void SLL_DestroyAllNodes(Node **List)
{
    Node *Current = *List;
    while(Current !=NULL)
    {
        *List = Current->NextNode;
        SLL_DestroyNode(Current);
        Current = *List;
    }
}
