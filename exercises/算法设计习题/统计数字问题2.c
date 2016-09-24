#include<stdio.h>
#include<math.h>

int Count(int n,int i)
{
   int sum=0,count=0,m=n;
   if(i==0) 
   { 
     while(m>0)
     {
         m/=10;
         sum+=m*(int)pow(10,count++);          
     }
     return sum;
   }
   while(m>0)
   {
      int t=(int)pow(10,count++);
      sum+=(m/10)*t;
      if(m%10>i)  sum+=t;
      else if(m%10==i)  sum+=n%t+1;
      m/=10;         
   }    
   return sum;
} 

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
       int i;  
       for(i=0;i<10;i++)         
          printf("%d\n",Count(n,i));                              
    }     
    system("pause");
}
