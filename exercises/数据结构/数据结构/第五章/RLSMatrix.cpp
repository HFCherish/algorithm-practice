#include"Define.h"
#define MAXSIZE 12500
#define MAXRC 12500
typedef struct
{
   int i,j;  //定义每个非零元素的行列
   int e;          
}Triple;
typedef struct
{
   Triple data[MAXSIZE+1];  //非零元三元表，data[0]未用 
   int rpos[MAXRC+1];   //每行第一个非零元的位置表 
   int mu,nu,tu;  //定义矩阵的行数、列数、元素个数     
}RLSMatrix;
  
//创建稀疏矩阵
Status CreateSMatrix(RLSMatrix &M)
{
   int t,p,q,e;
   int num[M.mu+1];
   for(t=0;t<=M.mu;t++)  num[t]=0;
   printf("请输入矩阵行、列：\n");
   scanf("%d%d",M.mu,M.nu);  //输入矩阵行列数
   M.tu=0; 
   printf("请输入元素值：\n");
   while(scanf("%d%d%d",p,q,e)==3)
   {
       M.tu++;
       M.data[M.tu].i=p;     M.data[M.tu].j=q;
       M.data[M.tu].e=e;
       num[p]++;                              
   }
   M.rpos[1]=1;
   for(t=2; t<=M.mu; t++)
       M.rpos[t]=M.rpos[t-1]+num[t-1];
   return OK;
}

//输出稀疏矩阵
Status PrinRLSMatrix(RLSMatrix M)
{
   int p;
   printf("稀疏矩阵非零元素的行、列、元素依次为：\n");
   for(p=1;p<M.tu+1;p++)
      printf("%-4d %-4d %-d\n",M.data[p].i,M.data[p].j,M.data[p].e);                     
   return OK;    
} 










