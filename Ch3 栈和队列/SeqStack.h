#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int DataType;

typedef struct sSeqStack{
	DataType data[MAXSIZE];
	int top;		//��ǰջ��Ԫ���±꣬��һ�������±�Ϊtop+1
}SeqStack, *pSeqStack;

//1.ջ��ʼ��
pSeqStack Init_SeqStack(void);

//2.�ж�ջ��
int Empty_SeqStack(pSeqStack S);

//3.��ջ
int Push_SeqStack(pSeqStack S, DataType x);

//4.��ջ�������س�ջԪ�ص�ֵ
int Pop_SeqStack(pSeqStack S, DataType* x);

//5.ȡջ��Ԫ��
int GetTop_SeqStack(pSeqStack S, DataType* x);

//6.����ջ
void Destroy_SeqStack(pSeqStack* S);

//7.����ջ
void Print_SeqStack(pSeqStack S);

