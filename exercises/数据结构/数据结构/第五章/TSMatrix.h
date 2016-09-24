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
Status CreateSMatrix(TSMatrix &M)
{
   int p,q,e;
   printf("����������С��У�\n");
   scanf("%d%d",M.mu,M.nu);  //�������������
   M.tu=0; 
   printf("������Ԫ��ֵ��\n");
   while(scanf("%d%d%d",p,q,e)==3)
   {
       M.tu++;
       M.data[M.tu].i=p;     M.data[M.tu].j=q;
       M.data[M.tu].e=e;                              
   }
   return OK;
}

//���ϡ�����
Status PrintSMatrix(TSMatrix M)
{
   int p;
   printf("ϡ��������Ԫ�ص��С��С�Ԫ������Ϊ��\n");
   for(p=1;p<M.tu+1;p++)
      printf("%-4d %-4d %-d\n",M.data[p].i,M.data[p].j,M.data[p].e);                     
   return OK;    
} 










