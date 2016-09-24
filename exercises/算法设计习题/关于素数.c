#include<stdio.h>
#include<math.h>
#include<malloc.h>
#define M 1000

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



int FindPrimeNum(int n,int *a)  //找n以内的素数个数 
{
    int j=1; 
    if(n==1)  a=NULL;    
    else
    {
       a[0]=2;
       int i;
       for(i=3;i<=n;i+=2)
          if(PrimeNum(i)==1) 
             a[j++]=i;  
    }
    return  j;
} 


int main()
{
   int a[200],i,j;
   i=FindPrimeNum(12,a);
   for(j=0;j<i;j++)  printf("%d  ",a[j]); 
   printf("\n%d",i); 
   getchar();   
   return 0; 
}
