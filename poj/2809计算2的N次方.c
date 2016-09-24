#include<stdio.h>
#include<stdlib.h>

int main()
{
   long long sum=1ll;
   int n,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
           sum*=2ll;            
   }
   printf("%lld\n",sum);
   system("pause");
   return 0;
}
