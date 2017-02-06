#include "SeqStack.h"

//1.ջ��ʼ��
pSeqStack Init_SeqStack()
{
	pSeqStack s = (pSeqStack)malloc(sizeof(SeqStack));
	if (s == NULL)
	{
		printf("malloc error");
		return NULL;
	}
	s->top = -1;
	return s;
}

//2.�ж�ջ��
//����ֵ��1:��ʾΪ�գ�0��ʾ��Ϊ�ա�
int Empty_SeqStack(pSeqStack S)
{
	if (S == NULL)
	{
		printf("˳��ջ������");
		return -1;
	}
	if (S->top == -1)
		return 1;
	else
		return 0;
}

//3.��ջ
int Push_SeqStack(pSeqStack S, DataType x)
{
	if (S == NULL)
	{
		printf("˳��ջ������");
		return -1;
	}
	if (S->top == MAXSIZE - 1)
	{
		printf("˳�������");
		return 0;
	}
	S->top++;
	S->data[S->top] = x;
	return 1;
}

//4.��ջ
int Pop_SeqStack(pSeqStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("˳��ջ������");
		return -1;
	}
	if (S->top == -1)
	{
		printf("˳���Ϊ��");
		return 0;
	}
	*x = S->data[S->top];
	S->top--;
	return 1;
}

//5.ȡջ��Ԫ��
int GetTop_SeqStack(pSeqStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("˳��ջ������");
		return -1;
	}
	if (S->top == -1)
	{
		printf("˳���Ϊ��");
		return 0;
	}
	*x = S->data[S->top];
	return 1;
}

//6.����ջ
void Destroy_SeqStack(pSeqStack* pS)
{
	if (*pS != NULL)
		free(*pS);
	*pS = NULL;
	return;
}

//7.����ջ
void Print_SeqStack(pSeqStack S)
{
	if (S == NULL)
	{
		printf("˳��ջ������");
		return;
	}
	if (S->top == -1)
	{
		printf("˳���Ϊ��");
		return;
	}
	int i = S->top;
	while (i >=0)
	{
		printf("%d ", S->data[i]);
		i--;
	}
	printf("\n");
}
