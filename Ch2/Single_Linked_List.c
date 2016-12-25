#include "Single_Linked_List.h"

void LinkedList_Test();

int main()
{
    LinkedList_Test();
    return 0;
}

void LinkedList_Test()
{
    pLinkedList pHead=Create_LinkedList();
    int i=1;
    for(;i<11;i++)
    {
        Insert_LinkedList(pHead,i,i);
    }
    Print_LinkedList(pHead);
    printf("��������= %d\n",Length_LinkedList(pHead));

    Delete_LinkedList(pHead,9);

    Print_LinkedList(pHead);
    Distroy_LinkedList(pHead);
    Print_LinkedList(pHead);
}

//1.�����յ�����
pLinkedList Create_LinkedList()
{
    pLinkedList pHead=(pLinkedList)malloc(sizeof(LNode));   //����ͷ���
    if(pHead==NULL)
    {
        printf("malloc error\n");
        return NULL;
    }
    pHead->next=NULL;
    return pHead;   //����ͷָ��
}

//2.���ٵ�����
void Distroy_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("����������\n");
        return;
    }
    pLinkedList pNode=pHead;
    pLinkedList pTemp;
    while(pNode!=NULL)
    {
        pTemp=pNode->next;
        free(pNode);
        pNode=pTemp;
    }
    //ͷ���ռ䲻�ͷ�
    pHead->next=NULL;
}

//3.�������
int Length_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("����������\n");
        return -1;
    }
    if(pHead->next==NULL)
    {
        printf("������Ϊ��\n");
        return 0;
    }
    int count=0;
    pLinkedList pNode=pHead->next;  //pNodeΪ��һ�����ݽ��
    while(pNode)
    {
        pNode=pNode->next;
        count++;
    }
    return count;
}

//4.���Ҳ������������Ϊi�����ݽ��ĵ�ַ
pLinkedList Locate_LinkedList_Pos(pLinkedList pHead,int i)
{
    if(pHead==NULL)
    {
        printf("����������\n");
        return NULL;
    }
    if(i<0)
    {
        printf("iλ����Ч\n");
        return NULL;
    }
    int j=0;
    pLinkedList pNode=pHead;
    while(pNode)
    {
        if(j==i)
        {
            return pNode;
        }
        pNode=pNode->next;
        j++;
    }
    return NULL;    //i������������
}

//5.���Ҳ���������ֵΪkey�Ľ�㣬���ؽ���ַ
pLinkedList Locate_LinkedList_Vaule(pLinkedList pHead,DataType key)
{
    if(pHead==NULL)
    {
        printf("����������\n");
        return NULL;
    }
    pLinkedList pNode=pHead->next;

    while(pNode!=NULL)
    {
        if(pNode->data==key)
        {
            return pNode;
        }
        pNode=pNode->next;
    }
    return NULL;
}

//6. �������:�ڵ�i��λ��ǰ����һ��ֵΪx���½ڵ㣬
int Insert_LinkedList(pLinkedList pHead,int i,DataType key)
{
    pLinkedList pNode=Locate_LinkedList_Pos(pHead,i-1); //���ҵ�i-1�����ݽ��
    if(pNode==NULL)
    {
        printf("������Ϊ�ջ�λ��i��Ч\n");
        return -1;
    }
    pLinkedList pNew=(pLinkedList)malloc(sizeof(LNode));
    if(pNew==NULL)
    {
        printf("malloc error\n");
        return 0;
    }
    pNew->data=key;
    pNew->next=pNode->next;
    pNode->next=pNew;
    return 1;
}

//7.ɾ��������ɾ����i�����
int Delete_LinkedList(pLinkedList pHead,int i)
{
    pLinkedList pNode=Locate_LinkedList_Pos(pHead,i-1); //���ҵ�i-1�����ݽ��
    //��i������Ԫ�ؿ��ܲ����ڣ�ǰ��ֻ�ж��˵�i-1������Ԫ���Ƿ���ڣ�
    if(pNode==NULL||pNode->next==NULL)
    {
        printf("λ��i��Ч\n");
        return -1;
    }
    pLinkedList pDelNode=pNode->next;
    pNode->next=pDelNode->next;
    free(pDelNode);
    return 1;
}

//8.����������
void Print_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("����������\n");
        return;
    }
    if(pHead->next==NULL)
    {
        printf("������Ϊ��\n");
        return;
    }
    pLinkedList pNode=pHead->next;
    while(pNode!=NULL)
    {
        printf("%d ",pNode->data);
        pNode=pNode->next;
    }
    printf("\n");
}



