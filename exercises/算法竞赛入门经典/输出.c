#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <memory.h>

int main()
{
   printf("%.17f",1/3.0); 
   long long int b=11111111111111111ll;
       printf("\nb = %I64d\n",b); 
   long long int c;
   scanf("%I64d",&c);
   printf("c=%I64d\n",c); 
   printf("\n%d      %d %ld  %ld  %I64d  %I64d",INT_MIN,INT_MAX,LONG_MIN,LONG_MAX,LONG_LONG_MIN,LONG_LONG_MAX); 
   
   /*int b;
   scanf("%d",&b);
   int m = (b%10)*100 + (b/10%10)*10 + (b/100); 
   printf("\n%03d",m); */
   putchar('\n');
   
   
   printf("%s\n","\\%"); 
   
   int a[18];
   int i,j;
   memset(a,0,sizeof(a));
   for(i=0; i<9; i++)
   {
            for(j=0; j<9; j++)
            {
                     a[i+j] += 1;         
            }         
   }
   for(i=0; i<=16; i++)
   {
            a[i+1] += a[i]/10;
            a[i] %= 10;         
   }
   for(i=0; i<17; i++)  printf("%d",a[i]);
   if(a[17] != 0) printf("%d",a[17]); 
   
   
   system("pause");
   return 0;
}
