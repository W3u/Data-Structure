//-------------------------------------------------------------
//Problem Descirption:
//设由n个人围坐在一个圆桌周围，现从第s个人开始从1报数，数到m的人出列，
//然后从出列的下一个人重新开始从1报数，数到m的再出列...
//如此反复，直到所有人都出列，求出出列的次序。
//
//算法思路:
//采用顺序表存储结构，将n个人的编号顺序存放在顺序表中，
//从顺序表中的第s个元素开始寻找第s+m-1个元素，找到后输出（在寻找过程中若到表尾，
//则跳到开始位置，通过取模实现），再删除该元素，下一次从该位置重复上述过程。
//-------------------------------------------------------------

#include <stdio.h>
#include "Sequence_List.h"

//约瑟夫问题
void Josephus();

int Josephus_SeqList(pSeqList pL,int s,int m);

int main()
{
    Josephus();
    return 0;
}

//约瑟夫问题
void Josephus()
{
	pSeqList pL = Init_SeqList();
	int i;
	for (i = 1; i<11; i++)
	{
		Insert_SeqList(pL, i, i);
	}
	Print_SeqList(pL);
	Josephus_SeqList(pL, 2, 5);
}

int Josephus_SeqList(pSeqList pL, int s, int m)
{
	if (pL == NULL)
	{
		printf("顺序表不存在\n");
		return -2;
	}
	if (s<1 || s>pL->length)   //s有效范围1至length
	{
		printf("s不在有效范围内\n");
		return -1;
	}
	if (m < 0)
	{
		printf("m无效\n");
		return 0;
	}
	int s1 = s - 1;
	int i;
	while (pL->length != 0)
	{
		s1 = s1 + m - 1;
		//s1 % pL->length的结构值可能为0，0可以是数组下标，但不能是位置值
		//故s1赋值为s-1;
		i = s1 % pL->length;		//取模

		printf("%d ", pL->data[i]);
		Delete_SeqList(pL, i + 1);
	}
	return 1;
}

