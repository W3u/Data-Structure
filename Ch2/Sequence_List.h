#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int DataType;

typedef struct Sequence{
	DataType data[MaxSize];
	int length;
} SeqList,* pSeqList;

pSeqList Init_SeqList();
int Length_SeqList(pSeqList pL);
DataType Location_SeqList_I(pSeqList pL,int i);
int Location_SeqList_Key(pSeqList pL,DataType key);
int Insert_SeqList(pSeqList pL,int i,DataType key);
int Delete_SeqList(pSeqList pL,int i);
void Print_SeqList(pSeqList pL);
pSeqList Copy_SeqList(pSeqList pL);

