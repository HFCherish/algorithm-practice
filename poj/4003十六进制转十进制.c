#include<stdio.h>
#include<stdlib.h>

int main()
{
   int t,i;
   scanf("%d",&t); 
   for(i=0;i<t;i++)
   {
      unsigned int a;
      scanf("%x",&a);
      printf("%u\n",a);                
   }
   system("pause");
   return 0;
}
