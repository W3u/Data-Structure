#include "SeqStack.h"

//1.栈初始化
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

//2.判断栈空
//返回值【1:表示为空；0表示不为空】
int Empty_SeqStack(pSeqStack S)
{
	if (S == NULL)
	{
		printf("顺序栈不存在");
		return -1;
	}
	if (S->top == -1)
		return 1;
	else
		return 0;
}

//3.入栈
int Push_SeqStack(pSeqStack S, DataType x)
{
	if (S == NULL)
	{
		printf("顺序栈不存在");
		return -1;
	}
	if (S->top == MAXSIZE - 1)
	{
		printf("顺序表已满");
		return 0;
	}
	S->top++;
	S->data[S->top] = x;
	return 1;
}

//4.出栈
int Pop_SeqStack(pSeqStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("顺序栈不存在");
		return -1;
	}
	if (S->top == -1)
	{
		printf("顺序表为空");
		return 0;
	}
	*x = S->data[S->top];
	S->top--;
	return 1;
}

//5.取栈顶元素
int GetTop_SeqStack(pSeqStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("顺序栈不存在");
		return -1;
	}
	if (S->top == -1)
	{
		printf("顺序表为空");
		return 0;
	}
	*x = S->data[S->top];
	return 1;
}

//6.销毁栈
void Destroy_SeqStack(pSeqStack* pS)
{
	if (*pS != NULL)
		free(*pS);
	*pS = NULL;
	return;
}

//7.遍历栈
void Print_SeqStack(pSeqStack S)
{
	if (S == NULL)
	{
		printf("顺序栈不存在");
		return;
	}
	if (S->top == -1)
	{
		printf("顺序表为空");
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
