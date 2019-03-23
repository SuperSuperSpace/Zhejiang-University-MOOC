#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct {
    ElementType* data;
    int front, rear;
    int max;
}QNode, *Queue;

Queue createQ(int max)
{
    Queue q = (Queue)malloc(sizeof(QNode));
    q->data = (ElementType*)malloc(sizeof(ElementType) * max);
    q->max = max;
    q->front = q->rear = 0;
    return q;
}

void addQ(Queue q, ElementType data)
{
    if((q->rear + 1) % q->max == q->front)
    {
        printf("The queue is full\n");
        exit(-1);
    }

    q->rear = (q->rear + 1) % q->max;
    q->data[q->rear] = data;
}

ElementType deleteQ(Queue q)
{
    if(q->rear == q->front)
    {
        printf("The queue is empty\n");
        exit(-1);
    }

    q->front = (q->front + 1) % q->max;
    return q->data[q->front];
}

int main()
{
    Queue q = createQ(4);
    addQ(q, 1);
    addQ(q, 2);
    addQ(q, 3);
    printf("%d\n", deleteQ(q));
    printf("%d\n", deleteQ(q));
    printf("%d\n", deleteQ(q));
    printf("%d\n", deleteQ(q));
    return 0;
}
