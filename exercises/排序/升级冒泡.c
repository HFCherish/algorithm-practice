#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
   //*a ^= *b ^= *a ^= *b;	сп╢М 
	int t;
	t=*a; *a=*b; *b=t;     
}

void Procedure_BubbleSort(int*a,int n)
{
     int i,j,LastExchangeIndex;
     i=n;
     while(i>0)
     {
        LastExchangeIndex=0;
        for(j=1;j<i;j++)
        {
            if(a[j]<a[j-1])
            {
                swap(&a[j],&a[j-1]);
                LastExchangeIndex=j;               
            }                
        }          
        i=LastExchangeIndex;
     }     
} 

int main()
{
   int a[5];
   int i;
   for(i=0;i<5;i++)  scanf("%d",&a[i]);
   Procedure_BubbleSort(a,5);
   for(i=0;i<5;i++)  printf("%d ",a[i]);
   system("pause");
   return;    
} 

