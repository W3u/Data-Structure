#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int DataType;

typedef struct Sequence{
	DataType data[MaxSize];
	int length;
} SeqList,* pSeqList;

//1.顺序表的初始化
pSeqList Init_SeqList();
//2.求顺序表的长度
int Length_SeqList(pSeqList pL);
//3.顺序表的检索操作：获取第i位置上的值
DataType Location_SeqList_I(pSeqList pL,int i);
//4.顺序表的检索操作：获取关键字为key的位置
int Location_SeqList_Key(pSeqList pL,DataType key);
//5.顺序表的插入运算:i位置插入key元素
int Insert_SeqList(pSeqList pL,int i,DataType key);
//6.顺序表的删除运算：删除位置i的元素
int Delete_SeqList(pSeqList pL,int i);
//7.打印每个元素
void Print_SeqList(pSeqList pL);
//8.拷贝顺序表
pSeqList Copy_SeqList(pSeqList pL);

