#include"RLSMatrix.h"

Status AddSMatrix(RLSMatrix A,RLSMatrix B,RLSMatrix &C)
{
     if(A.mu!=B.mu || A.nu!=B.nu) return ERROR;
     C.mu=A.mu;  C.nu=A.nu; C.tu=0;  
     if(A.tu || B.tu)
     {
        int ctemp[A.mu+1];
        int arow,ccol,col,t,tpa,tpb;
        for(arow=1; arow<=A.mu; arow++)
        {
             for(t=0;t<A.mu+1;t++)  ctemp[t]=0;
             C.rpos[arow]=C.tu+1;
             if(arow<A.mu)  {tpa=A.rpos[arow+1];   tpb=B.rpos[arow+1];} 
             else  {tpa=A.tu+1; tpb=B.tu+1;} //tpa,tpb为每行A,B最后一个非零元的下一个位置 
             for(col=A.rpos[arow]; col<tpa; col++)
             {
                ccol=A.data[col].j;  ctemp[ccol]+=A.data[col].e;                      
             }
             for(col=B.rpos[arow]; col<tpb; col++)
             {
                ccol=B.data[col].j;  ctemp[ccol]+=B.data[col].e;                      
             }
             for(ccol=1; ccol<=C.nu; ccol++)
               if(ctemp[ccol])
               {
                   C.tu++;
                   C.data[C.tu].i=arow;
                   C.data[C.tu].j=ccol;
                   C.data[C.tu].e=ctemp[ccol];            
               }
        }            
        return OK;
     }
}
