#include "SeqQueue.h"

//1.���еĳ�ʼ��
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

//2.�жӶӿ�
int Empty_SeqQueue(pSeqQueue pQueue)
{
    int result;
    if(pQueue==NULL)
    {
        printf("˳����в�����\n");
        result=-1;
    }
    if(pQueue->rear==pQueue->front)
        result=1;
    else
        result=0;
}

//3.���(1��ʾ�ɹ���-1��ʾ�������)
int In_SeqQueue(pSeqQueue pQueue,DataType x)
{
    if(pQueue==NULL)
    {
        printf("˳����в�����\n");
        return -2;
    }
    if((pQueue->rear+1)%MAXSIZE==pQueue->front)
    {
        printf("˳���������\n");
        return -1;
    }
    //rearλ���ƶ�һλ
    pQueue->rear=(pQueue->rear+1)%MAXSIZE;
    pQueue->data[pQueue->rear]=x;

    return 1;
}

//4.���ӣ�1��ʾ�ɹ���-1��ʾ�ӿգ�
int Out_SeqQueue(pSeqQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("˳����в�����\n");
        return -2;
    }
    if(Empty_SeqQueue(pQueue)==1)
    {
        printf("˳�����Ϊ��\n");
        return -1;
    }
    pQueue->front=(pQueue+1)%MAXSIZE;
    *x=pQueue->data[pQueue->front];
    return 1;
}

//5.����ͷԪ�أ�1��ʾ�ɹ���-1��ʾ�ӿգ�
int Front_SeqQueue(pSeqQueue pQueue,DataType *x)
{
        if(pQueue==NULL)
    {
        printf("˳����в�����\n");
        return -2;
    }
    if(Empty_SeqQueue(pQueue)==1)
    {
        printf("˳�����Ϊ��\n");
        return -1;
    }
    int front=(pQueue+1)%MAXSIZE;
    *x=pQueue->data[front];
    return 1;
}

//6.���ٶ���
void Destroy_SeqQueue(pSeqQueue *pQueue)
{
    if(*pQueue!=NULL)
        free(*pQueue);
    *pQueue=NULL;
}
