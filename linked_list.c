#include <stdio.h>
#include <stdlib.h>

typedef int dataType;	//元素类型

typedef struct sNode{
	dataType data;	//存放数据信息 
	struct sNode* next;	//存放后继元素的地址 
} LinkList,*pLinkList;

//1.链表的初始化
pLinkList Create_LinkList(void);
//2.链表的长度
int Length_LinkList(pLinkList pHead);
//3.按序号查找 
pLinkList Location_LinkList_Pos(pLinkList pHead,int i);
//4.按值查找 
pLinkList Location_LinkList_Value(pLinkList pHead,dataType key);
//4.插入元素(将x插入链表第i个位置上，返回【1:成功；0:插入位置不合法；-1:溢出；-2:链表不存在】)
int Insert_LinkList(pLinkList pHead,int i,dataType key);
//5.删除元素(删除第i个位置上的元素，返回【1:成功；0:删除位置不合法；-1:链表不存在】)
int Delete_LinkList(pLinkList pHead,int i);
//6.遍历链表
void Print_LinkList(pLinkList pHead);
//7.销毁链表
void Destroy_LinkList(pLinkList* pHead); 

int main()
{
	
	return 0;		
} 

//创建头结点H，将H->next=NULL 
pLinkList Create_LinkList(void)
{
	pLinkList pHead=(pLinkList)malloc(sizeof(LinkList));
	if(pHead!=NULL)
	{
		pHead->data=0;
		pHead->next=NULL;
	}
	else
		printf("> malloc error\n");

	return pHead;
}

int Length_LinkList(pLinkList pHead)
{
	int count=-1;	//链表有头结点，需要减1； 
	pLinkList pNode=pHead;
	while(pNode!=NULL)
	{
		pNode=pNode->next;
		count++;
	}
	return count;
}
 
//按序号查找
//从单链表的第1个元素结点起，判断当前结点是否是第i个，若是，则返回该结点的指针，
//否则继续下一个结点查找，直到表结束为止。
//若没有第i个结点则返回空，如果i==0返回头指针。 
pLinkList Location_LinkList_Pos(pLinkList pHead,int i)
{
	int count=0;
	pLinkList pNode=pHead;
	while(pNode!=NULL)
	{
		if(count==i)
			return pNode;
		pNode=pNode->next;
		count++;
	}
	return NULL;
}

//按值查找 
//成功返回值key对应的结点的指针；失败返回NULL 
pLinkList Location_LinkList_Value(pLinkList pHead,dataType key)
{
	//头结点为辅助节点，其数据域中保存其他信息。
	//pNode为链表的数据结点。 
	pLinkList pNode=pHead->next;
	while(pNode!=NULL)
	{
		if(pNode->data==key)
		{
			return pNode;
		}
		else
		{
			pNode=pNode->next;
		}
	} 
	return NULL;
} 

//newNode->next=pre->next
//pre->next=newNode； 
int Insert_LinkList(pLinkList pHead,int i,dataType key)
{
	pLinkList preNode= Location_LinkList_Pos(pHead,i-1);
	if(preNode==NULL)
	{
		printf("i有误");
		return -2; 
	}
	pLinkList newNode=(pLinkList)malloc(sizeof(LinkList));
	if(newNode==NULL)
	{
		printf("malloc allow");
		return -1;
	}
	newNode->data=key;
	newNode->next=preNode->next;
	preNode->next=newNode;
	return 1;
}

//删除运算是指删除单链表的第i个结点，即将第i-1个元素结点的指针域指向第i+1个元素结点。 
int Delete_LinkList(pLinkList pHead,int i)
{
	pLinkList preNode= Location_LinkList_Pos(pHead,i-1);
	if(preNode==NULL||preNode->next==NULL)
	{
		printf("i有误");
		return -1; 	
	}
	pLinkList delNode= preNode->next;
	preNode->next=delNode->next;
	free(delNode);
	return 1;
}

//单链表使用完后，由于其结点均为动态分配的内存空间，所以必须要销毁，
//以释放空间，否则会造成空间的浪费。
//销毁单链表，入口参数：单链表头指针的地址 
void Destroy_LinkList(pLinkList* pHead)
{
	pLinkList p,q;
	p=*pHead;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*pHead=NULL;
}