#include "LinkStack.h"

//1.栈初始化
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

//2.判断栈空
int Empty_LinkStack(pLinkStack S)
{
	if (S == NULL)
	{
		printf("链栈不存在");
		return -1;
	}
	if (S->top == NULL)
		return 1;
	else
		return 0;
}

//3.入栈
int Push_LinkStack(pLinkStack S, DataType x)
{
	if (S == NULL)
	{
		printf("链栈不存在");
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

//4.出栈，并返回出栈元素的值
int Pop_LinkStack(pLinkStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("链栈不存在");
		return -2;
	}
	if (S->top == NULL)
	{
		printf("链栈为空");
		return -1;
	}
	pStackNode pDel = S->top;
	S->top = S->top->next;
	*x = pDel->data;
	free(pDel);
	return 1;
}

//5.取栈顶元素
int GetTop_LinkStack(pLinkStack S, DataType* x)
{
	if (S == NULL)
	{
		printf("链栈不存在");
		return -2;
	}
	if (S->top == NULL)
	{
		printf("链栈为空");
		return -1;
	}
	*x = S->top->data;
	return 1;
}

//6.销毁栈
void Destroy_LinkStack(pLinkStack* pS)
{
	pLinkStack s = *pS;
	if (s == NULL)
	{
		printf("链栈不存在");
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

//7.遍历栈
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
