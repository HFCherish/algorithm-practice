#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int Feibo(int n)
{
    if(n==1 || n==2)  return 1;
    return Feibo(n-1)+Feibo(n-2);  
}

int main()
{
    int n,*a,*b,i;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    b=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]); 
       b[i]=Feibo(a[i]);
    }
    for(i=0;i<n;i++)
       printf("%d\n",b[i]);    
    system("pause");
    return 0;
}
