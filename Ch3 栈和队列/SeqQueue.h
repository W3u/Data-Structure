#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef DataType int;

typedef struct {
    DataType data[MAXSIZE]; //队列的存储空间
    int front,rear; //队头队尾指针,为数组下标
}SeqQueue,* pSeqQueue;

//1.队列的初始化
pSeqQueue Init_SeqQueue();

//2.判队队空
int Empty_SeqQueue(pSeqQueue pQueue);

//3.入队(1表示成功，-1表示队满溢出)
int In_SeqQueue(pSeqQueue pQueue,DataType x);

//4.出队（1表示成功，-1表示队空）
int Out_SeqQueue(pSeqQueue pQueue,DataType *x);

//5.读队头元素（1表示成功，-1表示队空）
int Front_SeqQueue(pSeqQueue pQueue,DataType *x);

//6.销毁队列
void Destroy_SeqQueue(pSeqQueue *pQueue);


