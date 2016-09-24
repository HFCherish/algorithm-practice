#include<stdio.h>
#include<stdlib.h>

int main()
{
   int cases,n,m,k,i;
   scanf("%d",&cases);
   for(i=0;i<cases;i++)
   {
      scanf("%d%d%d",&n,&m,&k);
      printf("Case : %d\n",i+1);
      int q;
      if(m-k-k>1)  printf("NO\n");
      else  printf("YES\n");                   
   }
   //system("pause");
   return 0;
}
