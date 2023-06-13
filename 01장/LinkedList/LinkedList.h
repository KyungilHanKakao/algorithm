#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode *NextNode;
} Node;

// 함수 원형 선언
Node *SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node *Node);

void SLL_AppendNode(Node **Head, Node *NewNode);
Node *SLL_GetNodeAt(Node *Head, int Location);
void SLL_DestroyAllNodes(Node **List);
int SLL_GetNodeCount(Node *Head);
void SLL_InsertAfter(Node *Head, int location, Node *NewNode);
void SLL_InsertBefore(Node **Head, int location, Node *NewHead);
void  SLL_InsertNewHead(Node** Head, Node* NewHead);

void  SLL_RemoveNode(Node** Head, Node* Remove);





#endif
