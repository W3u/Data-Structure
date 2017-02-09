//ºı÷Œ

#include <stdio.h>

int Maxinum(int a[],int n);

int main()
{
    int a[8]={3,5,8,7,2,6,62,34};
    int max=Maxinum(a,7);
    printf("%d",max);
}

int Maxinum(int a[],int n)
{
    if(n==0)
        return a[n];
    else
    {
        return Maxinum(a,n-1)>a[n]?Maxinum(a,n-1):a[n];
    }
}
