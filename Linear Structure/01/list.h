#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node{
    ElementType data;
    struct _Node* next;
}Node, *PNode;

void listRead(PNode* head); //创建链表，并读入数据
void listPrint(PNode list); //遍历链表并输出
void attach(int c, int e, PNode* rear); //新增一个节点，尾插
PNode listMerge(PNode L1, PNode L2);    //合并两个链表,原有的两个链表


#endif /*_LIST_H_
