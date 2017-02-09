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

//1.���еĳ�ʼ��
pLinkQueue Init_LinkQueue();

//2.�жӶӿ�
int Empty_LinkQueue(pLinkQueue pQueue);

//3.���(1��ʾ�ɹ�)
int In_LinkQueue(pLinkQueue pQueue,DataType x);

//4.���ӣ�1��ʾ�ɹ���
int Out_LinkQueue(pLinkQueue pQueue,DataType *x);

//5.����ͷԪ�أ�1��ʾ�ɹ���
int Front_LinkQueue(pLinkQueue pQueue,DataType *x);

//6.���ٶ���
void Destroy_LinkQueue(pLinkQueue *pQueue);
