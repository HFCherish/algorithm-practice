#include"Define.h"
#define MAXSIZE 12500
#define MAXRC 12500
typedef struct
{
   int i,j;  //����ÿ������Ԫ�ص�����
   int e;          
}Triple;
typedef struct
{
   Triple data[MAXSIZE+1];  //����Ԫ��Ԫ��data[0]δ�� 
   int rpos[MAXRC+1];   //ÿ�е�һ������Ԫ��λ�ñ� 
   int mu,nu,tu;  //��������������������Ԫ�ظ���     
}RLSMatrix;
  
//����ϡ�����
Status CreateSMatrix(RLSMatrix &M)
{
   int t,p,q,e;
   int num[M.mu+1];
   for(t=0;t<=M.mu;t++)  num[t]=0;
   printf("����������С��У�\n");
   scanf("%d%d",M.mu,M.nu);  //�������������
   M.tu=0; 
   printf("������Ԫ��ֵ��\n");
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

//���ϡ�����
Status PrinRLSMatrix(RLSMatrix M)
{
   int p;
   printf("ϡ��������Ԫ�ص��С��С�Ԫ������Ϊ��\n");
   for(p=1;p<M.tu+1;p++)
      printf("%-4d %-4d %-d\n",M.data[p].i,M.data[p].j,M.data[p].e);                     
   return OK;    
} 










