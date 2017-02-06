/*
栈的链式实现
*/

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;


typedef struct Node{
	DataType data;
	struct Node* next;
}StackNode, *pStackNode;

typedef struct {
	pStackNode top;
} LinkStack, *pLinkStack;

//1.栈初始化
pLinkStack Init_LinkStack(void);

//2.判断栈空
int Empty_LinkStack(pLinkStack S);

//3.入栈
int Push_LinkStack(pLinkStack S, DataType x);

//4.出栈，并返回出栈元素的值
int Pop_LinkStack(pLinkStack S, DataType* x);

//5.取栈顶元素
int GetTop_LinkStack(pLinkStack S, DataType* x);

//6.销毁栈
void Destroy_LinkStack(pLinkStack* S);

//7.遍历栈
void Print_LinkStack(pLinkStack S);
