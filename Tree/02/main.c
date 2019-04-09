#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    struct TreeNode* Left;
    struct TreeNode* Right;
    int v;
    int flag;
}TNode, *Tree;

Tree NewNode(int v);
Tree MakeTree(int N);
Tree Insert(Tree T, int v);
int Judge(Tree T, int N);
void ResetTree(Tree T);
void freeTree(Tree T);
int check(Tree T, int v);

Tree NewNode(int v)
{
    Tree T = (Tree)malloc(sizeof(TNode));
    T->flag = 0;
    T->Left = T->Right = NULL;
    T->v = v;

    return T;
}

Tree Insert(Tree T, int v)
{
    if(!T)
        T = NewNode(v);
    else
    {
        if(v > T->v)
            T->Right = Insert(T->Right, v);
        else
            T->Left = Insert(T->Left, v);
    }
    return T;
}

Tree MakeTree(int N)
{
    int i, v;
    Tree T;
    scanf("%d", &v);
    T = NewNode(v);
    for(i = 1; i < N; i++)
    {
        scanf("%d", &v);
        T = Insert(T, v);
    }

    return T;
}

int Judge(Tree T, int N)
{
    int flag = 0;
    int i, v;

    scanf("%d", &v);
    if(v != T->v) flag = 1;
    else T->flag = 1;
    for(i = 1; i < N; i++)
    {
        scanf("%d", &v);
        if((!flag) && (!check(T, v)))
            flag = 1;

    }
    if(flag)
        return 0;
    else
        return 1;
}

int check(Tree T, int v)
{
    if(T->flag)
    {
        if(v < T->v)
            return check(T->Left, v);
        else if(v > T->v)
            return check(T->Right, v);
        else
            return 0;
    }
    else
    {
        if(T->v == v)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

void ResetTree(Tree T)
{
    if(T->Left)
        ResetTree(T->Left);
    if(T->Right)
        ResetTree(T->Right);
    T->flag = 0;
}

void freeTree(Tree T)
{
    if(T->Left)
        freeTree(T->Left);
    if(T->Right)
        freeTree(T->Right);
    free(T);
}

int main()
{
    int N, L, i;
    Tree T;

    scanf("%d", &N);
    while(N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for(i = 0; i < L; i++)
        {
            if(Judge(T, N))
                printf("Yes\n");
            else
                printf("No\n");
            ResetTree(T);
        }
        freeTree(T);
        scanf("%d", &N);
    }

    return 0;
}
