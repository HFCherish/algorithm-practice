#include<stdio.h>
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


int main()
{
    int x;
    while(scanf("%d",&x))
      printf("%d\n",PrimeNum(x));
    system("pause");
    return 0;    
} 
