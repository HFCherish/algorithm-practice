#include<stdio.h>
#include<stdlib.h>

int BinarySerch(int *a,int m,int n,int k)
{
   /* if(m>n)  return -1;
    int t=(m+n)/2;
    if(a[t]==k)  return t;
    if(a[t]>k)  BinarySerch(a,m,t-1,k);
    BinarySerch(a,t+1,n,k);  */   
    int low=0,high=n-1;
    while(low<=high)
    {
       int t=(low+high)/2;
       if(a[t]==k)  return t;
       if(a[t]<k)   low=t+1;
       else  high=t-1;             
    }
    return -1;
} 

int main()
{
    int a[5],k;
    int i;
    for(i=0;i<5;i++)
        scanf("%d",&a[i]); 
    scanf("%d",&k);  
    i=BinarySerch(a,5,k);  
    if(i<0)  printf("Cannot find %d in array a\n",k);
    else printf("a[%d]=%d\n",i,k); 
    system("pause"); 
    return 0;
}
