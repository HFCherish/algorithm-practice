#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Count(int n,int i)
{     
   int sum=0;
   if(n/10==0 && i==0)  return 0;
   if(n%10>=i)  sum+=1; 
   n/=10;
   int count=1;
    while(n!=0)
    {
       int c;
       c=n%10;
       sum+=c*Count((int)pow(10,count++)-1,i);
       if(c>=i)  sum+=1;
       n/=10;
    } 
    if(i==0)  sum-=1;
    return sum;
}

int main()
{
    int m,n;
    while(scanf("%d",&n)==1)
    {
       int i;
       for(i=0;i<10;i++)         
          printf("%d\n",Count(n,i));                              
    }     
    system("pause");
}
