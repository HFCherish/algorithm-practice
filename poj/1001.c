#include<stdio.h>
int main()
{
   int i,m,n,j;
   __int64 num[100],t;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
      for(i=0;i<100;i++)
         num[i]=0;  
      num[1]=1;  num[0]=1;
      for(i=1;i<=m;i++)
      {
         for(t=0,j=1;j<num[0];j++)
         {
            num[j]*=n;
            num[j]+=t;
            t=num[j]/1000000000;
            num[j]%=1000000000;               
         }                 
         if(t!=0)
         {
            num[j]=t;
            num[0]++;        
         }
      }                  
      for(i=num[0];i>0;i--)
      {
        i==num[0]?printf("%I64d",num[i]):printf("%09I64d",num[i]);                     
      } 
      putchar('\n');                   
   }    
   return 0;
} 
