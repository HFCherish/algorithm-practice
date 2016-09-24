#include<stdio.h>
int main()
{
   int p[5];
   int a=0,b=4,i,t,key,count=0,NumOfOut=0;
   for(i=0;i<5;i++)
     scanf("%d",&p[i]);
   scanf("key=%d",&key); 
   do
   {
         t=(a+b)/2;
         if(key==p[t])
         {
           printf("p[%d]=%d\n",t,key);
           break;             
         }
         else
           if(key>p[t])
             a=t;
           else  b=t;
           
   }
   while(a<b);
   if(a>=b)printf("There is no suitable number for %d\n",key);
   getchar();
   getchar();
   return 0;
}
