#include <stdio.h>

void exchange(int *a,int*b)     
{
   int t;
   t=*a;  *a=*b;  *b=t;     
}

void chooseSort(int *a, int n)    //Ñ¡ÔñÅÅÐòÉýÐò 
{
   int i, j;
   for(i = n-1; i > 0; i--)
        for(j = 0; j < i; j++)
              if(a[j] > a[j+1])
                  exchange(&a[j], &a[j+1]);
}

int main()
{
   int a[5],i;
   for(i=0;i<5;i++)
      scanf("%d",&a[i]);
   putchar('\n');
   chooseSort(a,5);
   for(i=0;i<5;i++)
      printf("%d ",a[i]);
   system("pause");
   return 0;    
}
