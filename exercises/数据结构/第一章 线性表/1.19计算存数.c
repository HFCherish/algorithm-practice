#include <stdio.h>
#define MAXINT 100000
#define ARRSIZE 50

void b(int *a)
{
     a[0] = 2;
     int i;
     for( i=1; i<ARRSIZE; i++)
     {
        a[i] = a[i-1] * (i+1) * 2;        
        if(a[i] > MAXINT)
        {
                a[i] = -1;
                return;
        }
     }
}

int main()
{
   int i, a[ARRSIZE];
   scanf("%d", &i);
   if(i > ARRSIZE) printf("out of the bound!\n");
   else
   {
       b(a); 
       if(a[i-1] == -1) 
       {
                 printf("the number is too big!\n"); 
                 exit(0);
       }
       printf("%d\n",a[i-1]);
   } 
   system("pause");
   return 0;
}
