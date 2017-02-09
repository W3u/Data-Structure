#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
    DataType data;
    struct node* next;
}Qnode,*pQnode;

typedef struct {
    pQnode front,rear;
}LinkQueue,*pLinkQueue;

//1.队列的初始化
pLinkQueue Init_LinkQueue();

//2.判队队空
int Empty_LinkQueue(pLinkQueue pQueue);

//3.入队(1表示成功)
int In_LinkQueue(pLinkQueue pQueue,DataType x);

//4.出队（1表示成功，
int Out_LinkQueue(pLinkQueue pQueue,DataType *x);

//5.读队头元素（1表示成功）
int Front_LinkQueue(pLinkQueue pQueue,DataType *x);

//6.销毁队列
void Destroy_LinkQueue(pLinkQueue *pQueue);
