#include<stdio.h>
#include<stdlib.h> 
#define INFINITY 1000000 

void merge(int a[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    int b[n1+1],c[n2+1];
    int i;
    for(i=0;i<n1;i++)   b[i]=a[p+i];
    for(i=0;i<n2;i++)   c[i]=a[q+i+1];
    b[n1]=c[n2]=INFINITY; 
    int m=0,n=0;
    for(i=p;i<=r;i++)
    {
       if(b[m]<c[n])  { a[i]=b[m];   m++;}
       else {a[i]=c[n];  n++;}
    }     
}

void mergeSort(int a[],int m,int n)
{
   if(m>=n)  return; 
   int i;
   i=(m+n)/2;
   mergeSort(a,m,i);
   mergeSort(a,i+1,n);
   merge(a,m,i,n);
}



int main()
{
   int a[5];
   int i;
   for(i=0;i<5;i++)  scanf("%d",&a[i]);
   mergeSort(a,0,4);
   for(i=0;i<5;i++)  printf("%d ",a[i]);
   system("pause");
   return;    
}
