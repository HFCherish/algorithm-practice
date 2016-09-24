#include"Define.h"
#define MAXSIZE 12500
typedef struct
{
   int i,j;  //定义每个非零元素的行列
   int e;          
}Triple;
typedef struct
{
   Triple data[MAXSIZE+1];  //非零元三元表，data[0]未用 
   int mu,nu,tu;  //定义矩阵的行数、列数、元素个数     
}TSMatrix;
  
//创建稀疏矩阵


//输出稀疏矩阵
Status PrintSMatrix(TSMatrix M)
{
   int p;
   printf("稀疏矩阵非零元素的行、列、元素依次为：\n");
   for(p=1;p<M.tu+1;p++)
      printf("%-4d %-4d %-d\n",M.data[M.p].i,M.data[M.p].j,M.data[M.p].e);                     
   return OK;    
} 










