//·ÖÖÎ

#include <stdio.h>

int Maxinum(int a[],int lo,int hi);

int main()
{
    int a[8]={3,5,8,34,2,6,12,34};
    int max=Maxinum(a,0,7);
    printf("%d",max);
}

int Maxinum(int a[],int lo,int hi)
{
    if(lo==hi)
        return a[lo];
    else
    {
        int mid=(lo+hi)/2;
        int leftMax=Maxinum(a,lo,mid);
        int rightMax=Maxinum(a,mid+1,hi);
        return leftMax>rightMax?leftMax:rightMax;
    }
}
