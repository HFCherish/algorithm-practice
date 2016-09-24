#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define ERROR 0

void mmas(int *p,int n,int m);  //查找无序数组中第m个最大元素，运行后第m大元素就在第m个位置

int main()
{
    int N,M,K,*a,*sum;
    int i,j; 
    scanf("%d",&N);   //有n组数据 
    if(N>=1 && N<=5)
    {
        sum=(int*)malloc(N*sizeof(int));   
        for(i=0;i<N;i++)
        {
             sum[i]=0;
             scanf("%d%d",&M,&K);    //抓到m只兔子，最多能装k只兔子 
             if(M>=1 && M<=20000 && K>=1 && K<=5)
             { 
                 a=(int*)malloc(M*sizeof(int)); 
                 for(j=0;j<M;j++)
                 {
                     scanf("%d",&a[j]);   //每只兔子的重量 
                     if(a[j]<1 || a[j]>1000)exit(ERROR);   //输入数据不合法 
                 }                 
             } 
             else exit(ERROR);  //输入数据不合法 
             mmas(a,M,K);     //找出第k只重量最大的兔子 
             for(j=0;j<K;j++)  sum[i]+=a[j];  //将数组中前k个数据相加得结果 
             free(a);                 
        } 
        for(i=0;i<N;i++)
           printf("%d\n",sum[i]);
        free(sum);
    }             
    else exit(ERROR);       //输入数据不合法 
    system("pause");
    return 0;     
} 

void mmas(int *p,int n,int m)
{
    int s,t,flag,i,j,temp;
    s=0;    t=n-1;
    do
    {
        if(t<=s+1)
        {
           if(t=s+1 && p[t]>p[s])
           {
               temp;
               temp=p[s];  p[s]=p[t]; p[t]=temp;         
           }    
           return;              
       } 
       flag=p[s];  //第一个元素做岗哨 
       i=s+1;  j=t;   //
       do
       {
           while(p[i]>flag)i++;   //扫描搜索需要交换的数据 
           while(p[j]<flag)j--;   //扫描搜索需要交换的数据 
           if(i<j)
           {
              temp;
              temp=p[i];  p[i]=p[j]; p[j]=temp;       
           }        
       }while(i<j);       //对当前区间进行划分 
       p[s]=p[j];   p[j]=flag;
       if(j<m-1) s=j+1;  //第m大的元素在后面子空间内 
       else if(j>m-1)  t=j-1;   //第m大元素在前面子空间内 
       else return;   //找到第m大元素 
   }while(1);  
}
