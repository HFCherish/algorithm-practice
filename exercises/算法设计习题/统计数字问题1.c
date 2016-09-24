#include<stdio.h>
#include<math.h>

int count[10]={0};

void Count(int n)
{
    while(n)
    {
       count[n%10]++;
       n/=10;        
    }    
}

int main()
{
   long long int n;
   int i;
   scanf("%lld",&n);  
   for(i=1;i<=n;i++)
      Count(i);
   for(i=0;i<10;i++)
      printf("%d\n",count[i]);
   system("pause");    
} 
