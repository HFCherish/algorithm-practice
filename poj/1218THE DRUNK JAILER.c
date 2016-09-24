#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ncases,i,ncells;
    scanf("%d",&ncases);
    for(i=0;i<ncases;i++)
    {
        scanf("%d",&ncells);
        int a[ncells];
        memset(a,0,sizeof(a));  //预设，0表示未锁，1表示锁了 
        int j;
        for(j=1;j<ncells;j++)
        {
            int k;
            for(k=j; k<ncells; k+=j+1)
                a[k]^=1;                                 
        }  
        int count = 0; 
        for(j=0;j<ncells;j++)
            if(a[j]==0)  count ++;
        printf("%d\n",count);                 
    }    
    system("pause");
    return 0; 
}
