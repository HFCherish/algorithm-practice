#include<stdio.h>
#include<malloc.h>

int f(int m,int n)   //m的所有划分中，最大加数不大于n的划分数 
{
     if(m==1 || n==1)  return  1;
     if(m<n)  return  f(m,m);
     if(m==n)  return  f(m,m-1)+1;
     if(m>n)   return  f(m,n-1)+f(m-n,n);   
}

int main()
{
    int t,m,n,i,num;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
       scanf("%d%d",&m,&n);
       if(m==1 || n==1)  num=1;
       else if(m<=n)  num=f(m,m);
            else  if(m>n)  num=f(m,m)-f(m,m-n);
       printf("%d",num);
    } 
    getchar();
    getchar();
    return 0;
}
