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
    printf("单链表长度= %d\n",Length_LinkedList(pHead));

    Delete_LinkedList(pHead,9);

    Print_LinkedList(pHead);
    Distroy_LinkedList(pHead);
    Print_LinkedList(pHead);
}

//1.创建空单链表
pLinkedList Create_LinkedList()
{
    pLinkedList pHead=(pLinkedList)malloc(sizeof(LNode));   //创建头结点
    if(pHead==NULL)
    {
        printf("malloc error\n");
        return NULL;
    }
    pHead->next=NULL;
    return pHead;   //返回头指针
}

//2.销毁单链表
void Distroy_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("单链表不存在\n");
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
    //头结点空间不释放
    pHead->next=NULL;
}

//3.求单链表表长
int Length_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("单链表不存在\n");
        return -1;
    }
    if(pHead->next==NULL)
    {
        printf("单链表为空\n");
        return 0;
    }
    int count=0;
    pLinkedList pNode=pHead->next;  //pNode为第一个数据结点
    while(pNode)
    {
        pNode=pNode->next;
        count++;
    }
    return count;
}

//4.查找操作：返回序号为i的数据结点的地址
pLinkedList Locate_LinkedList_Pos(pLinkedList pHead,int i)
{
    if(pHead==NULL)
    {
        printf("单链表不存在\n");
        return NULL;
    }
    if(i<0)
    {
        printf("i位置无效\n");
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
    return NULL;    //i超出单链表长度
}

//5.查找操作：查找值为key的结点，返回结点地址
pLinkedList Locate_LinkedList_Vaule(pLinkedList pHead,DataType key)
{
    if(pHead==NULL)
    {
        printf("单链表不存在\n");
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

//6. 插入操作:在第i个位置前插入一个值为x的新节点，
int Insert_LinkedList(pLinkedList pHead,int i,DataType key)
{
    pLinkedList pNode=Locate_LinkedList_Pos(pHead,i-1); //查找第i-1个数据结点
    if(pNode==NULL)
    {
        printf("单链表为空或位置i无效\n");
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

//7.删除操作：删除第i个结点
int Delete_LinkedList(pLinkedList pHead,int i)
{
    pLinkedList pNode=Locate_LinkedList_Pos(pHead,i-1); //查找第i-1个数据结点
    //第i个数据元素可能不存在（前面只判断了第i-1个数据元素是否存在）
    if(pNode==NULL||pNode->next==NULL)
    {
        printf("位置i无效\n");
        return -1;
    }
    pLinkedList pDelNode=pNode->next;
    pNode->next=pDelNode->next;
    free(pDelNode);
    return 1;
}

//8.遍历单链表
void Print_LinkedList(pLinkedList pHead)
{
    if(pHead==NULL)
    {
        printf("单链表不存在\n");
        return;
    }
    if(pHead->next==NULL)
    {
        printf("单链表为空\n");
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



