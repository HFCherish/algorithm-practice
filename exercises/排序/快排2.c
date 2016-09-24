#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int*a,int*b)    //交换 
{
   int t;
   t=*a;  *a = *b;  *b = t;     
}

int Randomized_Partition(int *a,int p,int r)  // 随机化获得数组划分 
{
    srand((unsigned)time(NULL));
    int t=rand()%(r-p+1)+p;  //printf("%d\n",t); //获得随机数   
    if(r!=t)  Swap(&a[r],&a[t]);
    int x=a[r];
    int i=p-1,j;
    for(j=p; j<r; j++)
    {
       if(a[j]<=x)
             Swap(&a[++i],&a[j]);                                   
    }
    if(i+1<r)  Swap(&a[r],&a[i+1]);   printf("  %d  %d\n",a[i+1],i+1); 
    return i+1;         
}

void QuickSort(int *a,int p,int r)
{
     if(p>=r)  return;
     int t=Randomized_Partition(a,p,r);
     QuickSort(a,p,t-1); 
     QuickSort(a,t+1,r);   
}

int main()
{
   int a[5];
   int i;
   for(i=0;i<5;i++)  scanf("%d",&a[i]);
   QuickSort(a,0,4);
   for(i=0;i<5;i++)  printf("%d ",a[i]);
   system("pause");
   return;    
} 
