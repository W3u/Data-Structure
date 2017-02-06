/*
已知一顺序表 A， 其元素值非递减有序排列， 编写一个函数删除顺序表中多余的值相同
的元素。
*/
#include <stdio.h>

int DeleteElement(int a[],int len);

int main()
{
    int a[7]={1,2,3,4,5,6,7};
    int len=7;
    int num=DeleteElement(a,7);
    int i=0;
    for(;i<num;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}

int DeleteElement(int a[],int len)
{
    int i,j;
    i=j=0;
    while(j<len)
    {
        if(a[i]==a[j])
        {
            j++;
        }
        else
        {
            a[++i]=a[j++];
        }
    }
    return i+1;
}
