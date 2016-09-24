#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 

int PrimeNum(int x)  //判断整数x是否为素数 
{
   if(x==1)  return 0;
   if(x==2)  return 1;
   if(x%2==0)  return 0;
   int i;
   for(i=3;i<=sqrt(x);i+=2)
      if(x%i==0)  break;
   if(i<=sqrt(x))  return 0;  //非素数 
   else  return 1;     //素数 
} 



void FindPrimeNum(int m,int n,int &j,int *a)  //找(m,n)以内的素数个数 
{
    a=NULL;
    int i;
    if(m>n) return;
    if(m<=2 && n>=2)  a[j++]=2;
    for(i=3 ;i<=n; i+=2)
          if(PrimeNum(i)==1) 
             a[j++]=i;      
} 
 
int a[200];

int main()
{
   int N,i,x,num,tmax=1,t=0;
   memset(a,0,sizeof(a));
   scanf("%d",&N);
   for(i=0;i<N;i++)
   {
       scanf("%d",&x);
       FindPrimeNum(tmax,x,t,a); 
       if(tmax<x) tmax=x;
       else
        if(
       int j=t;
       FindPrimeNum(x+1,x+a[num-1],t,a);
       if(a[j])  
       {
                 printf("%d\n",a[j]);
                 tmax=a[t-1];
       } 
       else  printf("%d\n",a[num-1]);       
   } 
   system("pause");
   return 0;
}
