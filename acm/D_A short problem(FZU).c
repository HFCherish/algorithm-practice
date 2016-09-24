#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define NEG_INFINITY -10000000000ll


int main()
{
   int ncases,i,m,n;
   scanf("%d",&ncases);
   for(i=0;i<ncases;i++)
   {
       scanf("%d%d",&m,&n);
       int a[m];
       int j;
       for(j=0;j<m;j++)
           scanf("%d",&a[j]);    
       int p,q;
       long long max=NEG_INFINITY;  
       for(p=0;p<=m-n;p++)
       {           
           int sum=0;
           for(q=p;q<p+n;q++)  sum+=a[q];
           max=(sum>max)?sum:max;  
           for(q=p+n;q<m;q++)
           {
               sum+=a[q];
               if(a[q]>0)   
                  if(sum>max)  max=sum;                                   
           }                       
       }   
       printf("%lld\n",max);                  
   } 
   //system("pause");
   return 0;
}
