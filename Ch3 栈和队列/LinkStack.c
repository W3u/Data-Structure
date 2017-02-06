#include "LinkStack.h"

//1.ջ��ʼ��
pLinkStack Init_LinkStack(void)
{
	pLinkStack s = (pLinkStack)malloc(sizeof(LinkStack));
	if (s == NULL)
	{
		printf("malloc error");
		return NULL;
	}
	s->top = NULL;
	return s;
}

//2.�ж�ջ��
int Empty_LinkStack(pLinkStack S)
{
	if (S == NULL)
	{
		printf("��ջ������");
		return -1;
	}
	if (S->top == NULL)
		return 1;
	else
		return 0;
}

//3.��ջ
int Push_LinkStack(pLinkStack S, DataType x)
{
	if (S == NULL)
	{
		printf("��ջ������");
		return -2;
	}
	pStackNode pNew = (pStackNode)malloc(sizeof(StackNode));
	if (pNew == NULL)
	{
		printf("malloc error");
		return -1;
	}
	pNew->data = x;
	pNew->next = S->top;
	S->top = pNew;
	return 1;
}

//4.��ջ�������س�ջԪ�ص�ֵ
int Pop_LinkStack(pLinkStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("��ջ������");
		return -2;
	}
	if (S->top == NULL)
	{
		printf("��ջΪ��");
		return -1;
	}
	pStackNode pDel = S->top;
	S->top = S->top->next;
	*x = pDel->data;
	free(pDel);
	return 1;
}

//5.ȡջ��Ԫ��
int GetTop_LinkStack(pLinkStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("��ջ������");
		return -2;
	}
	if (S->top == NULL)
	{
		printf("��ջΪ��");
		return -1;
	}
	*x = S->top->data;
	return 1;
}

//6.����ջ
void Destroy_LinkStack(pLinkStack* pS)
{
	pLinkStack s = *pS;
	if (s == NULL)
	{
		printf("��ջ������");
		return -1;
	}

	pStackNode pDel = s->top;
	pStackNode pTemp;
	while (pDel != NULL)
	{
		pTemp = pDel;
		free(pDel);
		pDel = pTemp->next;
	}
	free(s->top);
	*pS = NULL;
	return;
}

//7.����ջ
void Print_LinkStack(pLinkStack S)
{
	pStackNode pNode = S->top;
	while (pNode != NULL)
	{
		printf("%d ", pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
	return;
}
