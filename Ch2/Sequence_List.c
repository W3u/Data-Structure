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


void test();


int main()
{
	test();
	return 0;
}

void test()
{
	pSeqList pL=Init_SeqList();
	printf("pL->length = %d\n",pL->length);
	int i;
	for(i=1;i<11;i++)
	{
		Insert_SeqList(pL,i,i);
	}
	Print_SeqList(pL);
	Delete_SeqList(pL,11);
	Delete_SeqList(pL,9);
	Print_SeqList(pL);

	printf("key=10的元素位置为 %d\n",Location_SeqList_Key(pL,10));
}


//1.顺序表的初始化
pSeqList Init_SeqList()
{
	pSeqList pL=(pSeqList)malloc(sizeof(SeqList));
	if(pL==NULL)
	{
		printf("malloc error\n");
		return NULL;
	}
	pL->length=0;
	return pL;
}

//2.求顺序表的长度
int Length_SeqList(pSeqList pL)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return -1;
	}
	return pL->length;
}

//3.顺序表的检索操作：获取第i位置上的值
//注：data数组中元素值也有可能为-2，-1
DataType Location_SeqList_I(pSeqList pL,int i)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return -2;
	}
	if(i<1||i>pL->length)	//i有效范围在1至length之间
	{
		printf("i值不在有效范围之内");
		return -1;
	}
	return pL->data[i-1];
}

//4.顺序表的检索操作：获取关键字为key的第一个位置
//返回值：-1->线性表不存在
//返回值：0->线性表中没有该值的元素
int Location_SeqList_Key(pSeqList pL,DataType key)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return -1;
	}
	int index=0;
	while(index<pL->length&&pL->data[index]!=key)
	{
		index++;
	}
	if(index>=pL->length)
		return 0;
	return index+1;
}

//5.顺序表的插入运算:i位置插入key元素
int Insert_SeqList(pSeqList pL,int i,DataType key)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return -2;
	}
	if(pL->length>=MaxSize)
	{
		printf("顺序表已满\n");
		return -1;
	}
	if(i<1||i>pL->length+1)	//i有效范围在1至length+1之间
	{
		printf("i值不在有效范围之内\n");
		return 0;
	}
	//1至i-1位置的元素保持不动，将i至length位置的元素后移一个位置
	//腾出位置i插入新值，并将length=length+1
	int j=pL->length-1;
	while(j>=i-1)
	{
		pL->data[j+1]=pL->data[j];
		j--;
	}
	pL->data[i-1]=key;
	pL->length=pL->length+1;
	return 1;
}

//6.顺序表的删除运算：删除位置i的元素
int Delete_SeqList(pSeqList pL,int i)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return -1;
	}
	if(i<1||i>pL->length)	//i有效范围在1至length之间
	{
		printf("i值不在有效范围之内\n");
		return 0;
	}
	//将位置为i+1至length的位置向前移动一个位置
	//将length=length-1
	int j=i;
	while(j<pL->length)
	{
		pL->data[j-1]=pL->data[j];
		j++;
	}
	pL->length--;
	return 1;
}

//7.打印每个元素
void Print_SeqList(pSeqList pL)
{
	if(pL==NULL)
	{
		printf("线性表不存在\n");
		return;
	}
	if(pL->length==0)
	{
		printf("线性表为空\n");
		return;
	}
	int i=0;
	for(;i<pL->length;i++)
	{
		printf("%d ",pL->data[i]);
	}
	printf("\n");
}
