/*
ջ����ʽʵ��
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

//1.ջ��ʼ��
pLinkStack Init_LinkStack(void);

//2.�ж�ջ��
int Empty_LinkStack(pLinkStack S);

//3.��ջ
int Push_LinkStack(pLinkStack S, DataType x);

//4.��ջ�������س�ջԪ�ص�ֵ
int Pop_LinkStack(pLinkStack S, DataType* x);

//5.ȡջ��Ԫ��
int GetTop_LinkStack(pLinkStack S, DataType* x);

//6.����ջ
void Destroy_LinkStack(pLinkStack* S);

//7.����ջ
void Print_LinkStack(pLinkStack S);
