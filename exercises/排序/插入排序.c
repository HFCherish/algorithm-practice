#include<stdio.h>


void insertionSort(int a[],int n) //²åÈëÉıĞò 
{
     int i,j;
     for(i=1;i<n;i++)
     {
         int t=a[i];
         for(j=i-1;a[j]>t && j>=0;j--)  a[j+1]=a[j];
         a[j+1]=t;
     }   
}




int main()
{
   int a[5],i;
   for(i=0;i<5;i++)
      scanf("%d",&a[i]);
   putchar('\n');
   insertionSort(a,5);
   for(i=0;i<5;i++)
      printf("%d ",a[i]);
   system("pause");
   return 0;    
}
