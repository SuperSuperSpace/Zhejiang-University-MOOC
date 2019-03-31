#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXNODE 10

typedef struct BinTreeNode{
    int Element;
    struct BinTreeNode* Left;
    struct BinTreeNode* Right;
}BinTree;

typedef struct _NodeInf{
    int LeftIndex;
    int RightIndex;
}NodeInf;

int findTreeHead(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
            return i;
    }
    return -1;
}

int builtTreeNodeInf(NodeInf nodeinf[])
{
    int n, i;
    char cl, cr;
    int flagArr[MAXNODE];
    memset(flagArr, 0, sizeof(flagArr));

    scanf("%d\n", &n);
    if(n > MAXNODE)
        return -1;

    for(i = 0; i < n; i++)
    {
        scanf("%c %c\n", &cl, &cr);
        if(cl !='-')
        {
            nodeinf[i].LeftIndex = cl - '0';
            flagArr[cl-'0'] = 1;
        }
        else
            nodeinf[i].LeftIndex = -1;

        if(cr !='-')
        {
            nodeinf[i].RightIndex = cr - '0';
            flagArr[cr-'0'] = 1;
        }
        else
            nodeinf[i].RightIndex = -1;
    }
    int root = findTreeHead(flagArr, n);
    return root;
}

void createTreeAndPriLeaves(int root, NodeInf nodeinf[])
{
    int head = 0;
    int tail = 0;
    BinTree* queue[MAXNODE];
    BinTree* temp;
    BinTree* binTree = (BinTree*)malloc(sizeof(BinTree));
    binTree->Element = root;

    queue[tail++] = binTree;

    while(head < tail)
    {
        if(nodeinf[queue[head]->Element].LeftIndex != -1)
        {
            temp = (BinTree*)malloc(sizeof(BinTree));
            temp->Element = nodeinf[queue[head]->Element].LeftIndex;
            queue[head]->Left = temp;
            queue[tail++] = temp;
        }
        else
            queue[head]->Left = NULL;
        if(nodeinf[queue[head]->Element].RightIndex != -1)
        {
            temp = (BinTree*)malloc(sizeof(BinTree));
            temp->Element = nodeinf[queue[head]->Element].RightIndex;
            queue[head]->Right = temp;
            queue[tail++] = temp;

        }
        else
            queue[head]->Right = NULL;

        if(queue[head]->Left == NULL && queue[head]->Right == NULL)
        {
            int ele = queue[head]->Element;
            printf("%d ", ele);
        }

        head++;
    }
    putchar('\n');
}

int main()
{
    NodeInf Tree[MAXNODE];
    int root = builtTreeNodeInf(Tree);
    printf("%d\n", root);
    createTreeAndPriLeaves(root, Tree);
    return 0;
}
