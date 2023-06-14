#include "CircularDoublyLinkedList.h"

Node *CDLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NewNode;
    NewNode->NextNode = NewNode;

    return NewNode;
}

void CDLL_DestroyNode(Node *Node)
{
    free(Node);
    Node = NULL;
}

void CDLL_DestroyAllNodes(Node **List)
{
    int count=CDLL_GetNodeCount(*List);
    Node *Current = *List;
    for (size_t i = 0; i < count; i++)
    {
        *List = Current->NextNode;
        CDLL_DestroyNode(Current);
        Current = *List;
    }
}

void CDLL_AppendNode(Node **Head, Node *NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        // Tail과 Head사이에 NewNode
        Node *Tail = (*Head)->PrevNode;

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
        NewNode->NextNode = *Head;

        (*Head)->PrevNode = NewNode;
    }
}

void CDLL_RemoveNode(Node **Head, Node *Remove)
{
    Node *Temp = Remove;
    Temp->PrevNode->NextNode = Remove->NextNode;
    Remove->NextNode->PrevNode = Temp->PrevNode;

    CDLL_DestroyNode(Remove);
}

Node *CDLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;
    // int maxNodeCount = CDLL_GetNodeCount(Head) - 1;

    while (Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }

    return Current;
}

int CDLL_GetNodeCount(Node *Head)
{
    int count = 0;
    Node *Current = Head;
    while (Current != NULL)
    {
        count++;
        Current = Current->NextNode;
        if (Current == Head)
            break;
    }
    return count;
}
