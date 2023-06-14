#include "DoublyLinkedList.h"

Node *DLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

void DLL_DestroyNode(Node *Node)
{
    free(Node);
    Node = NULL;
}

void DLL_DestroyAllNodes(Node **List)
{
    Node *Current = *List;
    while (Current != NULL)
    {
        *List = Current->NextNode;
        DLL_DestroyNode(Current);
        Current = *List;
    }
}

void DLL_AppendNode(Node **Head, Node *NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node *Current = *Head;
        while (Current->NextNode != NULL)
        {
            Current = Current->NextNode;
        }
        NewNode->PrevNode = Current;
        Current->NextNode = NewNode;
    }
}

void DLL_InsertAfter(Node *Current, Node *NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode; //
    Current->NextNode = NewNode;
}

void DLL_RemoveNode(Node **Head, Node *Remove)
{
    Node* Temp = Remove;
    Temp->PrevNode->NextNode=Remove->NextNode;
    Remove->NextNode->PrevNode=Temp->PrevNode;
    DLL_DestroyNode(Remove);
}

Node *DLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;
    int maxNodeCount = DLL_GetNodeCount(Head) - 1;
    if (maxNodeCount < Location)
    {
        Location = maxNodeCount;
    }

    while (Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }

    return Current;
}

int DLL_GetNodeCount(Node *Head)
{
    int count = 0;
    Node *Current = Head;
    while (Current != NULL)
    {
        count++;
        Current = Current->NextNode;
    }
    return count;
}
