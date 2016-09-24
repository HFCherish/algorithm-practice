#include<stdio.h>
#include<stdlib.h>

int main()
{
   int a,b,c,d,sum,count[100],i=0,j;
   while(1)
   {
     scanf("%d%d%d%d",&a,&b,&c,&d);
     if(a==-1)break;
     sum=(5544*a+14421*b+1288*c-d+21252)%21252;   
     if(sum<=0) sum+=21252;
     count[i++]=sum;
   }
   for(j=0;j<i;j++)
     printf("Case %d: the next triple peak occurs in %d days.\n",j+1,count[j]);
   system("pause");
   return;
}
