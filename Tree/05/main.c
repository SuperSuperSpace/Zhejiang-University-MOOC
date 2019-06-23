#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

typedef int ElementType;

typedef struct _sNode {
    struct _sNode* next;
    ElementType data;
}SNode, *Stack;

typedef struct _arrTreeEle {
    ElementType pre[MAXLEN];
    ElementType in[MAXLEN];
    ElementType post[MAXLEN];
}aTE, *pATE;

Stack createStack();
void pushStack(Stack s, ElementType ele);
ElementType popStack(Stack s);
int isEmptyStack(Stack s);

Stack creatStack()
{
    Stack s = (Stack)malloc(sizeof(SNode));
    s->next = NULL;
    s->data = 0;
    return s;
}

void pushStack(Stack s, ElementType ele)
{
    Stack stTmp = (Stack)malloc(sizeof(SNode));
    stTmp->data = ele;
    stTmp->next = s->next;
    s->next = stTmp;
}

ElementType popStack(Stack s)
{
    if(s->next == NULL)
    {
        printf("the stack empty\n");
        exit(-1);
    }
    Stack stTmp = s->next;
    s->next = stTmp->next;
    ElementType ele = stTmp->data;
    free(stTmp);
    return ele;
}

int isEmptyStack(Stack s)
{
    return (s->next == NULL);
}

void solve(int preL, int inL, int postL, int n, pATE pA)
{
    if(n == 0)
        return ;
    if(n == 1)
    {
        pA->post[postL] = pA->pre[preL];
        return ;
    }

    int i, L, R;

    ElementType root = pA->pre[preL];
    pA->post[postL+n-1] = root;
    for(i = 0; i < n; i++)
    {
        if(pA->in[inL+i] == root) break;
    }
    L = i;
    R = n - L - 1;
    solve(preL+1, inL, postL, L, pA);
    solve(preL+L+1, inL+L+1, postL+L, R, pA);
}

void readTree()
{
    int n, i, data, count = 0;
    int pro = 0, mid = 0;
    char str[10];

    Stack s = creatStack();
    pATE arrT = (pATE)malloc(sizeof(aTE));

    scanf("%d\n", &n);

    if(n)
    {
        /*用栈得到先序和中序的数组*/
        while(!isEmptyStack(s) || count < n)
        {
            scanf("%s", str);
            if(strcmp("Push", str) == 0)
            {
                scanf("%d", &data);
                pushStack(s, data);
                arrT->pre[pro++] = data;
                count++;
            }
            else if(strcmp("Pop", str) == 0)
            {
                arrT->in[mid++] = popStack(s);
            }
        }

        /*当栈为空才可执行，否则格式有误*/
        if(isEmptyStack(s))
        {
            solve(0, 0, 0, n, arrT);
            for(i = 0; i < n; i++)
            {
                printf("%d ", arrT->post[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    readTree();
    return 0;
}
