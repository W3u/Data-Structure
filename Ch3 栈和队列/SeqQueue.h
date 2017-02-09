#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef DataType int;

typedef struct {
    DataType data[MAXSIZE]; //���еĴ洢�ռ�
    int front,rear; //��ͷ��βָ��,Ϊ�����±�
}SeqQueue,* pSeqQueue;

//1.���еĳ�ʼ��
pSeqQueue Init_SeqQueue();

//2.�жӶӿ�
int Empty_SeqQueue(pSeqQueue pQueue);

//3.���(1��ʾ�ɹ���-1��ʾ�������)
int In_SeqQueue(pSeqQueue pQueue,DataType x);

//4.���ӣ�1��ʾ�ɹ���-1��ʾ�ӿգ�
int Out_SeqQueue(pSeqQueue pQueue,DataType *x);

//5.����ͷԪ�أ�1��ʾ�ɹ���-1��ʾ�ӿգ�
int Front_SeqQueue(pSeqQueue pQueue,DataType *x);

//6.���ٶ���
void Destroy_SeqQueue(pSeqQueue *pQueue);


