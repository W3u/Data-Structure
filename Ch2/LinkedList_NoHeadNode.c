/*
����ͷ���ĵ�����ʵ��
*/
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct sNode{
	DataType data;
	struct sNode* next;
}LNode, *pLinkedList;

//1.�����յ�����
pLinkedList Create_LinkedList_NoHeader();

//2.���ٵ�����
void Distroy_LinkedList_NoHeader(pLinkedList* ppHead);

//3.�������
int Length_LinkedList_NoHeader(pLinkedList pHead);

//4.���Ҳ���������λ��Ϊi�ĵ�ַ
pLinkedList Locate_LinkedList_NoHeader_Pos(pLinkedList pHead, int i);

//5.���Ҳ���������ֵΪkey�Ľ�㣬���ؽ���ַ
pLinkedList Locate_LinkedList_NoHeader_Vaule(pLinkedList pHead, DataType key);

//6. �������:�ڵ�i��λ��ǰ����һ��ֵΪx���½ڵ㣬
int Insert_LinkedList_NoHeader(pLinkedList* ppHead, int i, DataType key);

//7.ɾ��������ɾ����i�����
int Delete_LinkedList_NoHeader(pLinkedList pHead, int i);

//8.����������
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
	printf("��������= %d\n", Length_LinkedList_NoHeader(pHead));

	Delete_LinkedList_NoHeader(pHead, 9);

	Print_LinkedList_NoHeader(pHead);
	Distroy_LinkedList_NoHeader(&pHead);
	Print_LinkedList_NoHeader(pHead);
}

//1.�����յ�����
pLinkedList Create_LinkedList_NoHeader()
{
	pLinkedList pHead = NULL;
	return pHead;	//����ͷָ��
}

//2.���ٵ�����
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
	//ͷָ�븳ֵΪNULL
	*ppHead = NULL;
}

//3.�������
int Length_LinkedList_NoHeader(pLinkedList pHead)
{
	if (pHead == NULL)
	{
		printf("����������\n");
		return -1;
	}

	int count = 0;
	pLinkedList pNode = pHead;  //pNodeΪ��һ�����ݽ���ָ��
	while (pNode != NULL)
	{
		pNode = pNode->next;
		count++;
	}
	return count;
}

//4.���Ҳ������������Ϊi�����ݽ��ĵ�ַ
pLinkedList Locate_LinkedList_NoHeader_Pos(pLinkedList pHead, int i)
{
	if (pHead == NULL)
	{
		printf("����������\n");
		return NULL;
	}
	if (i < 1)
	{
		printf("iλ����Ч\n");
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
	return NULL;    //i������������
}

//5.���Ҳ���������ֵΪkey�Ľ�㣬���ؽ���ַ
pLinkedList Locate_LinkedList_NoHeader_Vaule(pLinkedList pHead, DataType key)
{
	if (pHead == NULL)
	{
		printf("����������\n");
		return NULL;
	}
	pLinkedList pNode = pHead;//pNodeΪ��һ�����ݽ���ָ��

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

//6. �������:�ڵ�i��λ��ǰ����һ��ֵΪx���½�㣬
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
		if (*ppHead == NULL)//������Ϊ��ʱ
			pNew->next = NULL;
		else
			pNew->next = (*ppHead)->next;
		*ppHead = pNew;//�ڵ�1��λ��ǰ���룬���ά����ͷָ�������ֵ
	}
	else
	{
		pNode = Locate_LinkedList_NoHeader_Pos(*ppHead, i - 1); //���ҵ�i-1�����ݽ��
		if (pNode == NULL)
		{
			printf("������Ϊ�ջ�λ��i��Ч\n");
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

//7.ɾ��������ɾ����i�����
int Delete_LinkedList_NoHeader(pLinkedList pHead, int i)
{
	pLinkedList pNode;
	pLinkedList pDelNode;
	if (i == 1)
	{
		//ɾ����1��λ��Ԫ��ʱ�����ά����ͷָ�������ֵ
		pDelNode = pHead;
		pHead = pHead->next;
		free(pDelNode);
	}
	else
	{
		pNode = Locate_LinkedList_NoHeader_Pos(pHead, i - 1); //���ҵ�i-1�����ݽ��
		//��i������Ԫ�ؿ��ܲ����ڣ�ǰ��ֻ�ж��˵�i-1������Ԫ���Ƿ���ڣ�
		if (pNode == NULL || pNode->next == NULL)
		{
			printf("λ��i��Ч\n");
			return -1;
		}
		pLinkedList pDelNode = pNode->next;
		pNode->next = pDelNode->next;
		free(pDelNode);
	}
	return 1;
}

//8.����������
void Print_LinkedList_NoHeader(pLinkedList pHead)
{
	if (pHead == NULL)
	{
		printf("����������\n");
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




