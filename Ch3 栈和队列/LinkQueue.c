#include "LinkQueue.h"

//1.队列的初始化
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

//2.判队队空
int Empty_LinkQueue(pLinkQueue pQueue)
{
    if(pQueue==NULL)
    {
        printf("链队不存在\n");
        return -1;
    }
    if(pQueue->front==NULL&&pQueue->rear==NULL)
        return 1;
    else
        return 0;
}

//3.入队(1表示成功)
int In_LinkQueue(pLinkQueue pQueue,DataType x)
{
    if(pQueue==NULL)
    {
        printf("链队不存在\n");
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

//4.出队（1表示成功）
int Out_LinkQueue(pLinkQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("链队不存在\n");
        return -2;
    }
    if(Empty_LinkQueue(pQueue)==1)
    {
        printf("链队为空\n");
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

//5.读队头元素（1表示成功）
int Front_LinkQueue(pLinkQueue pQueue,DataType *x)
{
    if(pQueue==NULL)
    {
        printf("链队不存在\n");
        return -2;
    }
    if(Empty_LinkQueue(pQueue)==1)
    {
        printf("链队为空\n");
        return -1;
    }
    pQnode pNode=pQueue->front;
    *x=pNode->data;

    return 1;

}

//6.销毁队列
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
