#include "LinkQueue.h"

//1.���еĳ�ʼ��
pLinkQueue Init_LinkQueue()
{
    pLinkQueue pQueue=(pLinkQueue)malloc(sizeof(LinkQueue));
    if(pQueue==NULL)
    {
        printf("malloc error\n");
    }
    else
    {
        pQueue->front=NULL;
        pQueue->rear=NULL;
    }
    return pQueue;
}

//2.�жӶӿ�
int Empty_LinkQueue(pLinkQueue pQueue)
{
    if(pQueue==NULL)
    {
        printf("���Ӳ�����\n");
        return -1;
    }
    if(pQueue->front==NULL&&pQueue->rear==NULL)
        return 1;
    else
        return 0;
}

//3.���(1��ʾ�ɹ�)
int In_LinkQueue(pLinkQueue pQueue,DataType x)
{
    if(pQueue==NULL)
    {
        printf("���Ӳ�����\n");
        return -2;
    }
    pQnode pNode=(pQnode)malloc(sizeof(Qnode));
    if(pNode==NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    pNode->data=x;
    pNode->next=NULL;
    if(Empty_LinkQueue(pQueue)==1)
    {
        pQueue->rear=pQueue->front=pNode;
    }
    else
    {
        pQueue->rear->next=pNode;
        pQueue->rear=pNode;
    }

    return 1;
}

//4.���ӣ�1��ʾ�ɹ���
int Out_LinkQueue(pLinkQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("���Ӳ�����\n");
        return -2;
    }
    if(Empty_LinkQueue(pQueue)==1)
    {
        printf("����Ϊ��\n");
        return -1;
    }
    pQnode pNode=pQueue->front;
    *x=pNode->data;
    pQueue->front=pNode->next;
    free(pQnode);

    if(pQueue->front==NULL)
        pQueue->rear=NULL;
    return 1;
}

//5.����ͷԪ�أ�1��ʾ�ɹ���
int Front_LinkQueue(pLinkQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("���Ӳ�����\n");
        return -2;
    }
    if(Empty_LinkQueue(pQueue)==1)
    {
        printf("����Ϊ��\n");
        return -1;
    }
    pQnode pNode=pQueue->front;
    *x=pNode->data;

    return 1;

}

//6.���ٶ���
void Destroy_LinkQueue(pLinkQueue *pQueue)
{
    pQnode pNode;
    if(*pQueue!=NULL)
    {
        while(pQueue->front)
        {
            pNode=pQueue->front;
            pQueue->front=pQueue->front->next;
            free(pNode);
        }
        free(*pQueue);
    }
    *pQueue=NULL;
}
