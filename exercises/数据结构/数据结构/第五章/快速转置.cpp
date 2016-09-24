#include"TSMatrix.h"

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
{
     int num[M.nu+1],cpot[M.mu+1];
     int col,row,t,p;
     T.mu=M.nu;  T.nu=M.mu;   T.tu=M.tu;
     if(T.tu)
     {
         for(col=0; col<=M.nu; col++)  num[col]=0;
         for(t=1; t<=M.tu; t++)  num[M.data[t].j]++;
         cpot[1]=1;
         for(row=2; row<M.mu; M++)  cpot[row]=cpot[row-1]+num[row-1];
         for(t=1; t<M.tu; t++)
         {
             p=cpot[M.data[t].j];  cpot[M.data[t].j]++;
             T.data[p].i=M.data[t].j;
             T.data[p].j=M.data[t].i;
             T.data[p].e=M.data[t].e;       
         }
     }
     return OK;
}
