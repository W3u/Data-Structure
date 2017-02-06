#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int DataType;

typedef struct sSeqStack{
	DataType data[MAXSIZE];
	int top;		//当前栈顶元素下标，下一个插入下标为top+1
}SeqStack, *pSeqStack;

//1.栈初始化
pSeqStack Init_SeqStack(void);

//2.判断栈空
int Empty_SeqStack(pSeqStack S);

//3.入栈
int Push_SeqStack(pSeqStack S, DataType x);

//4.出栈，并返回出栈元素的值
int Pop_SeqStack(pSeqStack S, DataType* x);

//5.取栈顶元素
int GetTop_SeqStack(pSeqStack S, DataType* x);

//6.销毁栈
void Destroy_SeqStack(pSeqStack* S);

//7.遍历栈
void Print_SeqStack(pSeqStack S);

