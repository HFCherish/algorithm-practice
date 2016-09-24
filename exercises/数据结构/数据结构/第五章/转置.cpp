#include"TSMatrix.h"
Status TransposeMatrix(TSMatrix M,TSMatrix &T)
{
    T.mu=M.nu;  T.nu=M.mu; T.tu=M.tu;
    int p,q;
    if(T.tu)
    {
        int t=1;
        for(q=1;q<=M.nu;q++)
            for(p=1;p<=M.mu;p++)
               if(M.data[p].j==q)
               {
                  T.data[t].j=M.data[p].i;
                  T.data[t].i=M.data[p].j;
                  T.data[t].e=M.data[p].e;
                  t++;
               }                   
    }       
    return OK;
} 
