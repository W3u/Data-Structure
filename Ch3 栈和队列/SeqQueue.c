#include "SeqQueue.h"

//1.队列的初始化
pSeqQueue Init_SeqQueue()
{
    pSeqQueue pQueue=(pSeqQueue)malloc(sizeof(SeqQueue));
    if(pQueue==NULL)
    {
        printf("malloc error\n");
    }
    else
    {
        pQueue->front=0;
        pQueue->rear=0;
    }
    return pQueue;
}

//2.判队队空
int Empty_SeqQueue(pSeqQueue pQueue)
{
    int result;
    if(pQueue==NULL)
    {
        printf("顺序队列不存在\n");
        result=-1;
    }
    if(pQueue->rear==pQueue->front)
        result=1;
    else
        result=0;
}

//3.入队(1表示成功，-1表示队满溢出)
int In_SeqQueue(pSeqQueue pQueue,DataType x)
{
    if(pQueue==NULL)
    {
        printf("顺序队列不存在\n");
        return -2;
    }
    if((pQueue->rear+1)%MAXSIZE==pQueue->front)
    {
        printf("顺序队列已满\n");
        return -1;
    }
    //rear位置移动一位
    pQueue->rear=(pQueue->rear+1)%MAXSIZE;
    pQueue->data[pQueue->rear]=x;

    return 1;
}

//4.出队（1表示成功，-1表示队空）
int Out_SeqQueue(pSeqQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("顺序队列不存在\n");
        return -2;
    }
    if(Empty_SeqQueue(pQueue)==1)
    {
        printf("顺序队列为空\n");
        return -1;
    }
    pQueue->front=(pQueue+1)%MAXSIZE;
    *x=pQueue->data[pQueue->front];
    return 1;
}

//5.读队头元素（1表示成功，-1表示队空）
int Front_SeqQueue(pSeqQueue pQueue,DataType *x)
{
        if(pQueue==NULL)
    {
        printf("顺序队列不存在\n");
        return -2;
    }
    if(Empty_SeqQueue(pQueue)==1)
    {
        printf("顺序队列为空\n");
        return -1;
    }
    int front=(pQueue+1)%MAXSIZE;
    *x=pQueue->data[front];
    return 1;
}

//6.销毁队列
void Destroy_SeqQueue(pSeqQueue *pQueue)
{
    if(*pQueue!=NULL)
        free(*pQueue);
    *pQueue=NULL;
}
