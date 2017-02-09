#include <stdio.h>

void Swap(int a[],int i,int j);

void Perm(int list[],int k,int m);

int main()
{
    int a[]={1,2,4};
    Perm(a,0,2);
    int i;
    scanf("%d",&i);
}

void Swap(int a[],int i,int j)
{
    int x;
    x=a[i];
    a[i]=a[j];
    a[j]=x;
}

void Perm(int list[],int k,int m)
{
    int i;
    if(k==m)
    {
        for(i=0;i<=m;i++)
            printf("%d",list[i]);
        printf("\n");
    }
    else
    {
        for(i=k;i<=m;i++)
        {
            Swap(list,k,i);
            Perm(list,k+1,m);
            Swap(list,k,i);
        }
    }
}

