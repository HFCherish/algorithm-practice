#include"Define.h"
#define MAXSIZE 12500
typedef struct
{
   int i,j;  //����ÿ������Ԫ�ص�����
   int e;          
}Triple;
typedef struct
{
   Triple data[MAXSIZE+1];  //����Ԫ��Ԫ��data[0]δ�� 
   int mu,nu,tu;  //��������������������Ԫ�ظ���     
}TSMatrix;
  
//����ϡ�����


//���ϡ�����
Status PrintSMatrix(TSMatrix M)
{
   int p;
   printf("ϡ��������Ԫ�ص��С��С�Ԫ������Ϊ��\n");
   for(p=1;p<M.tu+1;p++)
      printf("%-4d %-4d %-d\n",M.data[M.p].i,M.data[M.p].j,M.data[M.p].e);                     
   return OK;    
} 










