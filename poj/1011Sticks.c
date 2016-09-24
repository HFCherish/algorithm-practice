#include <stdio.h>

int main()
{
    int nparts;
    while(scanf("%d",&nparts) && nparts!=0)
    {
       int sum=0,max=0,length;
       int i;
       for(i=0;i<nparts;i++)
       {
          scanf("%d",&length);
          sum+=length;
          max=(max>length)?max:length;                     
       }                          
       for(i=max; i<=sum; i++)
           if(sum%i==0)
           {
              printf("%d\n",i);
              break;            
           }
    }    
    system("pause");
    return 0;
}
