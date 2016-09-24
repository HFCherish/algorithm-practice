#include<stdio.h>
#include<stdlib.h> 
#define RANGE 10000 

void countingSort(int a[],int n)
{
     int b[RANGE],c[n];
     int i;
     for(i=0;i<RANGE;i++)
        b[i]=0;
     for(i=0;i<n;i++)
        b[a[i]]++;
     for(i=1;i<RANGE;i++)
        b[i]+=b[i-1];
     for(i=0;i<n;i++)
     {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
     }
     for(i=0;i<n;i++)
        a[i]=c[i];          
}



int main()
{
   int a[5];
   int i;
   for(i=0;i<5;i++)  scanf("%d",&a[i]);
   countingSort(a,5);
   for(i=0;i<5;i++)  printf("%d ",a[i]);
   system("pause");
   return;    
} 
