#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue **Queue)
{
    (*Queue) = (LinkedQueue *)(malloc(sizeof(LinkedQueue)));

    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
    ;
}

void LQ_DestroyQueue(LinkedQueue *Queue)
{
    free(Queue);
}

Node *LQ_CreateNode(const char *Data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->Data = (char *)malloc(sizeof(Data));
    node->Data = (char*)Data;
    node->NextNode = NULL;

    return node;
}

void LQ_DestroyNode(Node *_Node)
{
    //free(_Node->Data);
    free(_Node);
}

void LQ_Enqueue(LinkedQueue *Queue, Node *NewNode)
{
    if (Queue->Front == NULL)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }

    Queue->Count++;
}

Node *LQ_Dequeue(LinkedQueue *Queue)
{
    Node *node = Queue->Front;
    Queue->Count--;
    Queue->Front = Queue->Front->NextNode;
    return node;
}
