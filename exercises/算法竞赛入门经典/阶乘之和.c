#include <stdio.h>
#include <time.h>

int main()
{
   const int MOD = 1000000;
   int n;
   scanf("%d",&n); 
   int s=0, factorial=1;
   int i;
   
   if(n>25) n = 25;
   for(i=1; i<=n; i++)
   {
            factorial = factorial * i %1000000;
            s = (s + factorial) % 1000000;         
   }
   printf("%d\n",s); 
   
   /*int j;
   for(i=1; i<=n; i++)
   {
            factorial = 1;
            for(j=1; j<=i; j++)
                factorial = factorial*j%1000000;
            s = (s + factorial) % 1000000;
   }
   printf("%d\n",s);
   printf("Time used = %.2lf\n",(double)clock() / CLOCKS_PER_SEC);*/ 
   system("pause");
   return 0;
}
