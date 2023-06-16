#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, int Capacity)
{
    (*Queue) = (CircularQueue *)malloc(sizeof(CircularQueue));

    (*Queue)->Nodes = (Node *)malloc(sizeof(Node) * Capacity + 1);

    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
    (*Queue)->Capacity = Capacity;
}

void CQ_DestroyQueue(CircularQueue *Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

void CQ_Enqueue(CircularQueue *Queue, ElementType Data)
{
    int position = Queue->Rear;
    if (CQ_IsFull(Queue) != TRUE)
    {
        if (Queue->Rear == Queue->Capacity)
        {

            Queue->Rear = 0;
        }
        else
        {
            Queue->Rear++;
        }
        Queue->Nodes[position].Data = Data;
    }
    else
    {
    }
}

ElementType CQ_Dequeue(CircularQueue *Queue)
{
    int position = Queue->Front;
    if (Queue->Front == Queue->Capacity)
    {
        Queue->Front = 0;
    }
    else
    {
        Queue->Front++;
    }
    return Queue->Nodes[position].Data;
}

int CQ_GetSize(CircularQueue *Queue)
{
    if ((Queue->Rear - Queue->Front) > 0)
    {
        return Queue->Rear - Queue->Front;
    }
    else
    {
        return Queue->Capacity - Queue->Front + Queue->Rear + 1;
    }
}

int CQ_IsEmpty(CircularQueue *Queue)
{
    if ((Queue->Rear - Queue->Front) == 0)
        return TRUE;
    else
        return FALSE;
}

int CQ_IsFull(CircularQueue *Queue)
{
    if ((Queue->Rear - Queue->Front) == Queue->Capacity)
    {
        return TRUE;
    }
    else
    {
        if ((Queue->Rear + 1) == (Queue->Front))
        {
            return TRUE;
        }
        else
            return FALSE;
    }
}
