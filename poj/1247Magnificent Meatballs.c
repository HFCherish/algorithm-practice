#include <stdio.h>

int main()
{
   int nguests;
   while(scanf("%d",&nguests) && nguests!=0)
   {
       int i,sum=0,a[nguests];
       for(i=0;i<nguests;i++)
       {
          scanf("%d",&a[i]);
          sum+=a[i];                     
       }    
       if(sum%2==0)
       {
           sum/=2;
           int t=0,partion;
           for(partion=0;partion<nguests-1;partion++)
           {
              t+=a[partion];
              if(t>=sum)  break;                                   
           }            
           if(t==sum)  printf("Sam stops at position %d and Ella stops at position %d.\n",
                               partion+1,partion+2);
           else    printf("No equal partitioning.\n");
       }  
       else 
           printf("No equal partitioning.\n");                     
   }    
   system("pause");
   return 0;
}
