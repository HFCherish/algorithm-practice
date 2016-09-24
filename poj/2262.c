#include<stdio.h>
#include<math.h>

int PrimeNum(int x)  //判断整数x是否为素数，0表示非素数，1表素数 
{
   if(x==1)  return 0;
   if(x==2)  return 1;
   int i;
   if(x%2==0)  return 0;
   for(i=3;i<=sqrt((double)x);i+=2)
      if(x%i==0)  return 0;
   return 1;
   return 0;    
} 

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int j;
        for(j=3;j<=n/2;j+=2)
          if(PrimeNum(j)==1 && PrimeNum(n-j)==1)
          {
              printf("%d = %d + %d\n",n,j,n-j);
              break;                       
          }
        if(j>n/2)  printf("Goldbach's conjecture is wrong.\n");         
    } 
    return 0;
}
