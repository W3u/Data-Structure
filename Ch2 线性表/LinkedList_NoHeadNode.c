/*
不带头结点的单链表实现
*/
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct sNode{
	DataType data;
	struct sNode* next;
}LNode, *pLinkedList;

//1.创建空单链表
pLinkedList Create_LinkedList_NoHeader();

//2.销毁单链表
void Distroy_LinkedList_NoHeader(pLinkedList* ppHead);

//3.求单链表表长
int Length_LinkedList_NoHeader(pLinkedList pHead);

//4.查找操作：返回位置为i的地址
pLinkedList Locate_LinkedList_NoHeader_Pos(pLinkedList pHead, int i);

//5.查找操作：查找值为key的结点，返回结点地址
pLinkedList Locate_LinkedList_NoHeader_Vaule(pLinkedList pHead, DataType key);

//6. 插入操作:在第i个位置前插入一个值为x的新节点，
int Insert_LinkedList_NoHeader(pLinkedList* ppHead, int i, DataType key);

//7.删除操作：删除第i个结点
int Delete_LinkedList_NoHeader(pLinkedList pHead, int i);

//8.遍历单链表
void Print_LinkedList_NoHeader(pLinkedList pHead);

void LinkedList_NoHeader_Test();

int main()
{
	LinkedList_NoHeader_Test();

	int a;
	scanf_s("%d", &a);
	return 0;
}

void LinkedList_NoHeader_Test()
{
	pLinkedList pHead = Create_LinkedList_NoHeader();
	int i = 1;
	for (; i < 11; i++)
	{
		Insert_LinkedList_NoHeader(&pHead, i, i);
	}
	Print_LinkedList_NoHeader(pHead);
	printf("单链表长度= %d\n", Length_LinkedList_NoHeader(pHead));

	Delete_LinkedList_NoHeader(pHead, 9);

	Print_LinkedList_NoHeader(pHead);
	Distroy_LinkedList_NoHeader(&pHead);
	Print_LinkedList_NoHeader(pHead);
}

//1.创建空单链表
pLinkedList Create_LinkedList_NoHeader()
{
	pLinkedList pHead = NULL;
	return pHead;	//返回头指针
}

//2.销毁单链表
void Distroy_LinkedList_NoHeader(pLinkedList* ppHead)
{
	pLinkedList pNode = *ppHead;

	pLinkedList pTemp;
	while (pNode != NULL)
	{
		pTemp = pNode->next;
		free(pNode);
		pNode = pTemp;
	}
	//头指针赋值为NULL
	*ppHead = NULL;
}

//3.求单链表表长
int Length_LinkedList_NoHeader(pLinkedList pHead)
{
	if (pHead == NULL)
	{
		printf("单链表不存在\n");
		return -1;
	}

	int count = 0;
	pLinkedList pNode = pHead;  //pNode为第一个数据结点的指针
	while (pNode != NULL)
	{
		pNode = pNode->next;
		count++;
	}
	return count;
}

//4.查找操作：返回序号为i的数据结点的地址
pLinkedList Locate_LinkedList_NoHeader_Pos(pLinkedList pHead, int i)
{
	if (pHead == NULL)
	{
		printf("单链表不存在\n");
		return NULL;
	}
	if (i < 1)
	{
		printf("i位置无效\n");
		return NULL;
	}
	int j = 1;
	pLinkedList pNode = pHead;
	while (pNode)
	{
		if (j == i)
		{
			return pNode;
		}
		pNode = pNode->next;
		j++;
	}
	return NULL;    //i超出单链表长度
}

//5.查找操作：查找值为key的结点，返回结点地址
pLinkedList Locate_LinkedList_NoHeader_Vaule(pLinkedList pHead, DataType key)
{
	if (pHead == NULL)
	{
		printf("单链表不存在\n");
		return NULL;
	}
	pLinkedList pNode = pHead;//pNode为第一个数据结点的指针

	while (pNode != NULL)
	{
		if (pNode->data == key)
		{
			return pNode;
		}
		pNode = pNode->next;
	}
	return NULL;
}

//6. 插入操作:在第i个位置前插入一个值为x的新结点，
int Insert_LinkedList_NoHeader(pLinkedList* ppHead, int i, DataType key)
{
	pLinkedList pNode;
	pLinkedList pNew;
	if (i == 1)
	{
		pNew = (pLinkedList)malloc(sizeof(LNode));
		if (pNew == NULL)
		{
			printf("malloc error\n");
			return 0;
		}
		pNew->data = key;
		if (*ppHead == NULL)//单链表为空时
			pNew->next = NULL;
		else
			pNew->next = (*ppHead)->next;
		*ppHead = pNew;//在第1个位置前插入，需改维护变头指针变量的值
	}
	else
	{
		pNode = Locate_LinkedList_NoHeader_Pos(*ppHead, i - 1); //查找第i-1个数据结点
		if (pNode == NULL)
		{
			printf("单链表为空或位置i无效\n");
			return -1;
		}
		pNew = (pLinkedList)malloc(sizeof(LNode));
		if (pNew == NULL)
		{
			printf("malloc error\n");
			return 0;
		}
		pNew->data = key;
		pNew->next = pNode->next;
		pNode->next = pNew;
	}
	return 1;
}

//7.删除操作：删除第i个结点
int Delete_LinkedList_NoHeader(pLinkedList pHead, int i)
{
	pLinkedList pNode;
	pLinkedList pDelNode;
	if (i == 1)
	{
		//删除第1个位置元素时，需改维护变头指针变量的值
		pDelNode = pHead;
		pHead = pHead->next;
		free(pDelNode);
	}
	else
	{
		pNode = Locate_LinkedList_NoHeader_Pos(pHead, i - 1); //查找第i-1个数据结点
		//第i个数据元素可能不存在（前面只判断了第i-1个数据元素是否存在）
		if (pNode == NULL || pNode->next == NULL)
		{
			printf("位置i无效\n");
			return -1;
		}
		pLinkedList pDelNode = pNode->next;
		pNode->next = pDelNode->next;
		free(pDelNode);
	}
	return 1;
}

//8.遍历单链表
void Print_LinkedList_NoHeader(pLinkedList pHead)
{
	if (pHead == NULL)
	{
		printf("单链表不存在\n");
		return;
	}
	pLinkedList pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d ", pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
}




