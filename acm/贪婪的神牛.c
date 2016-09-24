#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define ERROR 0

void mmas(int *p,int n,int m);  //�������������е�m�����Ԫ�أ����к��m��Ԫ�ؾ��ڵ�m��λ��

int main()
{
    int N,M,K,*a,*sum;
    int i,j; 
    scanf("%d",&N);   //��n������ 
    if(N>=1 && N<=5)
    {
        sum=(int*)malloc(N*sizeof(int));   
        for(i=0;i<N;i++)
        {
             sum[i]=0;
             scanf("%d%d",&M,&K);    //ץ��mֻ���ӣ������װkֻ���� 
             if(M>=1 && M<=20000 && K>=1 && K<=5)
             { 
                 a=(int*)malloc(M*sizeof(int)); 
                 for(j=0;j<M;j++)
                 {
                     scanf("%d",&a[j]);   //ÿֻ���ӵ����� 
                     if(a[j]<1 || a[j]>1000)exit(ERROR);   //�������ݲ��Ϸ� 
                 }                 
             } 
             else exit(ERROR);  //�������ݲ��Ϸ� 
             mmas(a,M,K);     //�ҳ���kֻ������������ 
             for(j=0;j<K;j++)  sum[i]+=a[j];  //��������ǰk��������ӵý�� 
             free(a);                 
        } 
        for(i=0;i<N;i++)
           printf("%d\n",sum[i]);
        free(sum);
    }             
    else exit(ERROR);       //�������ݲ��Ϸ� 
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
       flag=p[s];  //��һ��Ԫ�������� 
       i=s+1;  j=t;   //
       do
       {
           while(p[i]>flag)i++;   //ɨ��������Ҫ���������� 
           while(p[j]<flag)j--;   //ɨ��������Ҫ���������� 
           if(i<j)
           {
              temp;
              temp=p[i];  p[i]=p[j]; p[j]=temp;       
           }        
       }while(i<j);       //�Ե�ǰ������л��� 
       p[s]=p[j];   p[j]=flag;
       if(j<m-1) s=j+1;  //��m���Ԫ���ں����ӿռ��� 
       else if(j>m-1)  t=j-1;   //��m��Ԫ����ǰ���ӿռ��� 
       else return;   //�ҵ���m��Ԫ�� 
   }while(1);  
}
