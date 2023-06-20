#include "ExpressionTree.h"

ETNode *ET_CreateNode(ElementType NewData)
{
    ETNode *node = (ETNode *)malloc(sizeof(ETNode));

    node->Left = NULL;
    node->Right = NULL;
    node->Data = NewData;

    return node;
}

void ET_DestroyNode(ETNode *Node)
{
    free(Node);
}

void ET_DestroyTree(ETNode *Root)
{
    if (Root == NULL)
    {
        return;
    }

    ET_DestroyTree(Root->Left);
    ET_DestroyTree(Root->Right);

    ET_DestroyNode(Root);
}

void ET_PostorderPrintTree(ETNode *Node)
{
    ETNode *node = Node;
    if (Node == NULL)
    {
        return;
    }

    ET_PostorderPrintTree(Node->Left);

    ET_PostorderPrintTree(Node->Right);

    printf("%c", Node->Data);
}

void ET_BuildExpressionTree(char *PostfixExpression, ETNode **Node)
{
    int len = strlen(PostfixExpression);
    char token = PostfixExpression[len - 1];
    PostfixExpression[len - 1] = '\0';

    switch (token)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        (*Node) = ET_CreateNode(token);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
        break;

    default:
        (*Node) = ET_CreateNode(token);
        break;
    }
}
