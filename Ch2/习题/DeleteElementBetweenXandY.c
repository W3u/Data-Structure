/*
��дһ����������һ������˳���A��ɾ��ֵ��x ~ y��x<=y��֮�������Ԫ�أ�
Ҫ���Խϸߵ�Ч����ʵ�֡�
*/
#include <stdio.h>

int DeleteElementBetweenXandY(int a[],int len,int x,int y);

int main()
{
    int a[7]={9,7,2,4,10,6,13};
    int len=7;
    int x=1;int y=7;
    int j=DeleteElementBetweenXandY(a,len,x,y);
    int i=0;
    for(;i<j;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

}

int DeleteElementBetweenXandY(int a[],int len,int x,int y)
{
    int i;
    int count=0;
    for(i=0;i<len;i++)
    {
        if(a[i]>x&&a[i]<y)
        {
            count++;
        }
        else
        {
            a[i-count]=a[i];
        }
    }
    return len-count;
}
