#include <stdio.h>
#include <stdlib.h>


#if 0    /*数组方式实现栈*/

typedef int ElementType;
typedef struct {
    ElementType* data;
    int max;
    int top;
}Node, *Stack;

Stack createStack(int max)
{
    Stack s = (Stack)malloc(sizeof(Node));
    s->data = (ElementType*)malloc(sizeof(ElementType) * max);
    s->top = -1;
    s->max = max;
    return s;
}

int isFull(Stack s)
{
    return(s->top == s->max - 1);
}

int isEmpty(Stack s)
{
    return(s->top == -1);
}

void push(Stack s, ElementType data)
{
    if(isFull(s))
    {
        printf("The stack is full\n");
        exit(-1);
    }
    s->data[++(s->top)] = data;
}

ElementType pop(Stack s)
{
    if(isEmpty(s))
    {
        printf("The stack is empty\n");
        exit(-1);
    }
    return s->data[(s->top)--];
}
#endif  /*数组方式实现栈*/

#if 1 /*链表方式实现栈*/

typedef int ElementType;
typedef struct node{
    ElementType data;
    struct node* next;
}Node, *Stack;

Stack createStack()
{
    Stack s = (Stack)malloc(sizeof(Node));
    s->next = NULL;
    return s;
}

int isEmpty(Stack s)
{
    return (s->next == NULL);
}

void push(Stack s, ElementType data)
{
    Stack node = (Stack)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;

    /*头插法*/
    node->next = s->next;
    s->next = node;
}

ElementType pop(Stack s)
{
    int data;
    if(isEmpty(s))
    {
        printf("The stack is empty\n");
        exit(-1);
    }

    Stack tmp = s->next;
    data = tmp->data;
    s->next = tmp->next;
    free(tmp);

    return data;
}

#endif /*链表方式实现栈*/

int main()
{
    Stack s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    return 0;
}
