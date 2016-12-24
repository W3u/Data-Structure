#include <stdio.h>
#include "Sequence_List.h"

//交集
pSeqList Intersection(pSeqList pa,pSeqList pb);
//并集
pSeqList Union(pSeqList pa,pSeqList pb);

void test();

int main()
{
    test();
	return 0;
}

void test()
{
	pSeqList pL1 = Init_SeqList();
	pSeqList pL2 = Init_SeqList();

	int i;
	for (i = 1; i<11; i++)
	{
		Insert_SeqList(pL1, i, i);
		Insert_SeqList(pL2, i, 2*i);
	}

	Intersection(pL1, pL2);

	Union(pL1, pL2);
}


//交集
pSeqList Intersection(pSeqList pa,pSeqList pb)
{
    //如果A中的元素在B中不存在，则删除该元素
    if(pa==NULL||pb==NULL)
    {
        printf("顺序表必须存在\n");
        return NULL;
    }
    pSeqList pc=Copy_SeqList(pa);
    int i=0;
    for(;i<pc->length;i++)
    {
        if(Location_SeqList_Key(pb,pc->data[i])<1)  //小于1表示不存在
        {
            Delete_SeqList(pc,i+1);
        }
    }

    printf("A：");
    Print_SeqList(pa);
    printf("B：");
    Print_SeqList(pb);
    printf("C：");
    Print_SeqList(pc);

    return pc;
}
//并集
pSeqList Union(pSeqList pa,pSeqList pb)
{
    if(pa==NULL||pb==NULL)
    {
        printf("顺序表必须存在\n");
        return NULL;
    }
    //如果B中的元素在A中不存在，则添加该元素
    pSeqList pc=Copy_SeqList(pa);
    int i=0;
    for(;i<pb->length;i++)
    {
        if (Location_SeqList_Key(pc, pb->data[i]) < 1) //小于1表示不存在
        {
            Insert_SeqList(pc,pc->length+1,pb->data[i]);    //插入到length+1的位置
        }
    }

    printf("A：");
    Print_SeqList(pa);
    printf("B：");
    Print_SeqList(pb);
    printf("C：");
    Print_SeqList(pc);

    return pc;
}

