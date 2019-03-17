#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _node{
    int c;
    int e;
    struct _node* next;
}Node, *PNode;

void attach(int c, int e, PNode* rear)
{
    PNode pNode = (PNode)malloc(sizeof(Node));
    pNode->c = c;
    pNode->e = e;
    pNode->next = NULL;

    (*rear)->next = pNode;
    *rear = pNode;
}

PNode createNode()
{
    int num, c, e;
    PNode rear = (PNode)malloc(sizeof(Node));
    rear->next = NULL;
    PNode p = rear;
    scanf("%d", &num);

    while(num--)
    {
        scanf("%d %d", &c, &e);
        attach(c, e, &rear);
    }

    PNode t = p;
    p = p->next;
    free(t);

    return p;
}

PNode add(PNode L1, PNode L2)
{
    PNode p = (PNode)malloc(sizeof(Node));
    p->next = NULL;
    PNode rear = p;
    PNode t1 = L1;
    PNode t2 = L2;

    int sum;

    while(t1 && t2)
    {
        if(t1->e == t2->e)
        {
            sum = t1->c + t2->c;
            if(sum) attach(sum, t1->e, &rear);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->e > t2->e)
        {
            attach(t1->c, t1->e, &rear);
            t1 = t1->next;
        }
        else
        {
            attach(t2->c, t2->e, &rear);
            t2 = t2->next;
        }
    }
    while(t1)
    {
        attach(t1->c, t1->e, &rear);
        t1 = t1->next;
    }
    while(t2)
    {
        attach(t2->c, t2->e, &rear);
        t2 = t2->next;
    }

    PNode t = p;
    p = p->next;
    free(t);

    return p;
}

PNode mul(PNode L1, PNode L2)
{
    PNode p = (PNode)malloc(sizeof(Node));
    p->next = NULL;
    PNode rear = p;

    int c, e;

    PNode t1 = L1;
    PNode t2 = L2;
    while(t2)
    {
        attach(t1->c*t2->c, t1->e+t2->e, &rear);
        t2 = t2->next;
    }
    t1= t1->next;
    while(t1)
    {
        t2 = L2; rear= p;
        while(t2)
        {
            e = t1->e + t2->e;
            c = t1->c * t2->c;
            while(rear->next && rear->next->e > e)
                rear = rear->next;
            if(rear->next && rear->next->e == e)
            {
                if(rear->next->c + c)
                    rear->next->c += c;
                else
                {
                    PNode t = rear->next;
                    rear->next = t->next;
                    free(t);
                }
            }
            else
            {
                PNode node = (PNode)malloc(sizeof(Node));
                node->c = c;
                node->e = e;
                node->next = rear->next;
                rear->next = node;
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    t2 = p; p = p->next; free(t2);
    return p;
}

void printList(PNode list)
{
    int flag = 0;

    while(list)
    {
        if(!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", list->c, list->e);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    PNode pAdd, pMul, p1, p2;
    p1 = createNode();
    p2 = createNode();
    pAdd = add(p1, p2);
    pMul = mul(p1, p2);
    printList(pAdd);
    printList(pMul);
    return 0;
}
