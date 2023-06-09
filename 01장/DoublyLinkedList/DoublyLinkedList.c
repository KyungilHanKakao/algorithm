#include "DoublyLinkedList.h"

Node *DLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node)); // sizeof(Node) //! sizeof(Node*)
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;
    return NewNode;
}

void DLL_DestroyNode(Node *Node)
{
    free(Node);
    Node = NULL;
}

void DLL_AppendNode(Node **Head, Node *NewNode)
{
    Node *Current = *Head;
    while (Current->NextNode != NULL)
    {
        Current = Current->NextNode;
    }

    Current->NextNode = NewNode;
}

void DLL_InsertAfter(Node *Current, Node *NewNode)
{
    if (Current->NextNode == NULL)
    {
        Current->NextNode = NewNode;
        NewNode->PrevNode = Current;
    }
    else
    {
        NewNode->NextNode = Current->NextNode;
        NewNode->PrevNode = Current;

        Current->NextNode = NewNode;
        Current->NextNode->PrevNode = NewNode;
    }
}

void DLL_RemoveNode(Node **Head, Node *Remove)
{
}

Node *DLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;
    while (Current != NULL && (--Location >= 0))
    {
        Current = Current->NextNode;
    }
    return Current;
}

int DLL_GetNodeCount(Node *Head)
{
    return 0;
}
