#include <stdio.h>
#include <stdlib.h>

typedef struct _AVLTree {
    int height;
    int data;
    struct _AVLTree* LTree;
    struct _AVLTree* RTree;
}AVLNode, *AVLTree;

AVLTree SingleRotateWithLeft(AVLTree T);
AVLTree SingleRotateWithRight(AVLTree T);
AVLTree DoubleRotateWithLeft(AVLTree T);
AVLTree DoubleRotateWithRight(AVLTree T);

int max(int a, int b)
{
    return (a > b ? a : b);
}

int height(AVLTree T)
{
    if(T == NULL)
        return -1;
    return T->height;
}

AVLTree insert(AVLTree T, int v)
{
    if(T == NULL)
    {
        T = (AVLTree)malloc(sizeof(AVLNode));
        if(T == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        T->data = v;
        T->height = 0;
        T->LTree = T->RTree = NULL;
    }
    else if(v < T->data)
    {
        T->LTree = insert(T->LTree, v);
        if((height(T->LTree) - height(T->RTree)) == 2)
        {
            if(v < T->LTree->data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(v > T->data)
    {
        T->RTree = insert(T->RTree, v);
        if((height(T->RTree) - height(T->LTree)) == 2)
        {
            if(v > T->RTree->data)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }

    T->height = max(height(T->LTree), height(T->RTree)) + 1;

    return T;
}

AVLTree SingleRotateWithLeft(AVLTree T)
{
    AVLTree pNode = T->LTree;
    T->LTree = pNode->RTree;
    pNode->RTree = T;

    T->height = max(height(T->LTree), height(T->RTree)) + 1;
    pNode->height = max(height(pNode->LTree), height(pNode->RTree)) + 1;

    return pNode;
}

AVLTree SingleRotateWithRight(AVLTree T)
{
    AVLTree pNode = T->RTree;
    T->RTree = pNode->LTree;
    pNode->LTree = T;

    T->height = max(height(T->LTree), height(T->RTree)) + 1;
    pNode->height = max(height(pNode->LTree), height(pNode->RTree)) + 1;

    return pNode;
}

AVLTree DoubleRotateWithLeft(AVLTree T)
{
    T->LTree = SingleRotateWithRight(T->LTree);
    return SingleRotateWithLeft(T);
}

AVLTree DoubleRotateWithRight(AVLTree T)
{
    T->RTree = SingleRotateWithLeft(T->RTree);
    return SingleRotateWithRight(T);
}

int main()
{
    AVLTree T = NULL;
    int n, v;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &v);
        T = insert(T, v);
    }
    if(T)
        printf("ROOT:%d\n", T->data);
    return 0;
}
