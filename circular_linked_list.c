#include <stdio.h>
#include <stdlib.h>

typedef int elemType;	//元素类型

typedef struct sNode{
	elemType data;	//存放数据信息 
	struct sNode* next;	//存放后继元素的地址 
} LNode,*pLinkList;

//1.链表的初始化
pLinkList Create_LinkList(void);
//2.链表的长度
int Length_LinkList(pLinkList pHead);
//3.按序号查找 
pLinkList Location_LinkList_Pos(pLinkList pHead,int i);
//4.按值查找 
pLinkList Location_LinkList_Value(pLinkList pHead,elemType key);
//4.插入元素(将x插入链表第i个位置上，返回【1:成功；0:插入位置不合法；-1:溢出；-2:链表不存在】)
int Insert_LinkList(pLinkList pHead,int i,elemType key);
//5.删除元素(删除第i个位置上的元素，返回【1:成功；0:删除位置不合法；-1:链表不存在】)
int Delete_LinkList(pLinkList pHead,int i);
//6.遍历链表
void Print_LinkList(pLinkList pHead);
//7.销毁链表
void Destroy_LinkList(pLinkList* pHead); 
//8.合并两个循环单链表（pTail*为尾结点）
pLinkList Combine_LinkList(pLinkList pTailA,pLinkList pTailB);


int main()
{
	pLinkList pHead = Create_LinkList();
	pLinkList pHead2 = Create_LinkList();

	int i;
	for(i=1;i<10;i++)
	{
		Insert_LinkList(pHead,i,i+100);
		Insert_LinkList(pHead2,i,i+200);
	}

	Print_LinkList(pHead);
	Print_LinkList(pHead2);
	
	//Combine_LinkList()
	
	return 0;
}

//创建空单链表：创建一个带头结点的空表
pLinkList Create_LinkList(void)
{
	pLinkList pHead=(pLinkList)malloc(sizeof(LNode));
	if(pHead==NULL)
	{
		printf("malloc error\n");
		return NULL;
	}
	pHead->next=pHead;
	return pHead;
}

//2.链表的长度
int Length_LinkList(pLinkList pHead)
{
	if(pHead==NULL)
	{
		printf("链表不存在\n");
		return -1;
	}
	if(pHead->next==pHead)
	{
		printf("链表为空\n");
		return 0;
	}
	pLinkList pNode=pHead->next;
	int count=0;
	while(pNode!=pHead)
	{
		count++;
		pNode=pNode->next;
	}
	printf("Length=%d\n",count);
	return count;
}

//3.按序号查找 
//i不存在活着链表不存在，则返回NULL;
//i==0返回头指针，否则返回第i个结点的指针。
pLinkList Location_LinkList_Pos(pLinkList pHead,int i)
{
	if(pHead==NULL)
	{
		printf("链表不存在");
		return NULL;
	}
	if(pHead->next==pHead)
	{
		return pHead;
	}
	int count=1;
	pLinkList pNode=pHead->next;
	while(pNode!=pHead)
	{
		if(count==i)
			return pNode;
		pNode=pNode->next;
		count++;
	}
	return NULL;
}

//4.插入元素(将x插入链表第i个位置上，返回【1:成功；-2:链表不存在】)
//如果插入位置为链表末尾，则需要调整尾结点的指针域
int Insert_LinkList(pLinkList pHead,int i,elemType key)
{
	pLinkList preNode = Location_LinkList_Pos(pHead,i-1);
	if(preNode==NULL)
	{
		printf("i位置不合法\n");
		return -1;
	}
	
	pLinkList newNode=(pLinkList)malloc(sizeof(LNode));
	if(newNode==NULL)
	{
		printf("malloc error");
		return 0;
	}
	newNode->data=key;
	newNode->next=preNode->next;
	preNode->next=newNode;
	return 1;
}


void Print_LinkList(pLinkList pHead)
{
	if(pHead==NULL)
	{
		printf("单链表不存在");
		return;
	}
	if(pHead->next==pHead)
	{
		printf("单链表为空");
		return;
	}
	pLinkList pNode=pHead->next;
	while(pNode!=pHead)
	{
		printf("%d ",pNode->data);
		pNode=pNode->next;
	}
	printf("\n");
}

//8.合并两个循环单链表（pTail*为尾结点）
pLinkList Combine_LinkList(pLinkList pTailA,pLinkList pTailB)
{
	pLinkList p=pTailA->next;
	pTailA->next=pTailB->next->next;
	free(pTailA->next);
	pTailB->next=p;
	return pTailA;
}
