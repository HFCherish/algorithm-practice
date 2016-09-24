#include<stdio.h>
#include<string.h>

int main()
{
   int m,nmonkeys;
   while(scanf("%d%d",&nmonkeys,&m) && nmonkeys!=0)
   {
       int a[nmonkeys],count1=0,i=0,count2=0;
       memset(a,0,sizeof(a));
       while(count2<nmonkeys-1)
       {
             if(a[i]==0)
             {
                 count1++;
                 if(count1==m)
                 {
                     count1 = 0;
                     a[i] =1; 
                     count2++;           
                 }   
                        
             }   
             i=(i+1)%nmonkeys;                   
       } 
       for(i=0;i<nmonkeys;i++)
           if(a[i]==0)   printf("%d\n",i+1);                           
   } 
   system("pause");
   return 0;
}
