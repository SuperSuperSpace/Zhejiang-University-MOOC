#include "list.h"

void listRead(PNode* head)
{
    *head = (PNode)malloc(sizeof(Node));
    (*head)->next = NULL;
    PNode tail = *head;
    int num;
    int data;

    scanf("%d", &num);
    while(num--)
    {
        scanf("%d", &data);
        PNode node = (PNode)malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

}

void listPrint(PNode list)
{
    if(list->next == NULL)
        printf("NULL");
    while(list->next)
    {
        printf("%d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}

PNode listMerge(PNode L1, PNode L2)
{
    PNode mList = (PNode)malloc(sizeof(Node));
    mList->next = NULL;
    PNode mTail = mList;

    PNode tL1 = L1->next;
    PNode tL2 = L2->next;
    while(tL1 && tL2)
    {
        if(tL1->data < tL2->data)
        {
            mTail->next = tL1;
            mTail = tL1;
            tL1 = tL1->next;
        }
        else
        {
            mTail->next = tL2;
            mTail = tL2;
            tL2 = tL2->next;
        }
    }

    while(tL1)
    {
        mTail->next = tL1;
        mTail = tL1;
        tL1 = tL1->next;
    }

    while(tL2)
    {
        mTail->next = tL2;
        mTail = tL2;
        tL2 = tL2->next;
    }

    L1->next = NULL;
    L2->next = NULL;

    return mList;
}
