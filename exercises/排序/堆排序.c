#include<stdio.h>

int HeapSize;   //堆的大小 

void Swap(int *a,int *b)  // 交换两个整数 
{
   int t;
   t=*a;  *a=*b;   *b=t;     
}

int Parent(int i)   // 求i的父节点 
{
    return i/2;    
} 

int Left(int i)   // 求i的左孩子 
{
    if(i==0)  return 1;
    return 2*i;    
}

int Right(int i)   // 求i的右孩子 
{
    if(i==0)   return 2;
    return 2*i+1;    
}

void Max_HeapIfy(int *a,int i)  // 调节以i为根的子树成为最大堆 
{
    int l,r,max;
    l=Left(i);  r=Right(i);
    if(l<HeapSize && a[l]>=a[i])
         max=l;
    else  max=i;
    if(r<HeapSize && a[r]>=a[max])
       max=r;
    if(max!=i)
    {
          Swap(&a[max],&a[i]);
          Max_HeapIfy(a,max);        
    }    
}

void Build_Max_Heap(int *a,int n)  // 建立大顶堆 
{
     HeapSize=n;
     int i;
     for(i=n/2-1; i>=0; i--)
         Max_HeapIfy(a,i);            
} 

void HeapSort(int *a,int n)  // 堆排序 
{
   Build_Max_Heap(a,n);
   int i;
   for(i=n-1;i>0;i--)
   {
      Swap(&a[i],&a[0]);
      HeapSize--;
      Max_HeapIfy(a,0);                
   }     
}

int main()
{
   int a[5];
   int i;
   for(i=0;i<5;i++)  scanf("%d",&a[i]);
   HeapSort(a,5);
   for(i=0;i<5;i++)  printf("%d ",a[i]);
   system("pause");
   return;    
} 
