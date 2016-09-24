#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c,d,e,f;
    int npackets,nleft;
    int Three_Packets[4]={0,5,3,1};
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)==6 && !(a==0 && b==0 && c==0 && d==0 && e==0 && f==0))
    {
        
        npackets=d+e+f+(c+3)/4;
        nleft=c%4;
        int two_board=5*d+Three_Packets[nleft];
        int one_board=0;
        if(b>two_board)      
          npackets+=(b-two_board+8)/9;
        one_board=36*npackets-36*f-25*e-16*d-9*c-4*b;
        if(a>one_board)
          npackets+=(a-one_board+35)/36;
        printf("%d\n",npackets);                                                 
    }
    
    system("pause");
    return 0;
}
