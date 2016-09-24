#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
   *a^=*b^=*a^=*b;     
}

int main()
{
   int n,m;
   int i,j,k;
   scanf("%d%d",&n,&m);
   getchar();
   int count[m],p=0;  //记录各个字符串的无序性 
   for(i=0;i<m;i++)
      count[i]=0;           //无序性置零 
   char DNA[m][n+1];
   for(i=0;i<m;i++)
   {
         gets(DNA[p]);  
         for(j=0;j<n-1;j++)
         {
             for(k=j+1;k<n;k++)
             {
                   if(DNA[p][k]<DNA[p][j])  count[p]++;            
             }         
         }    
         p++;              
   } 
   int LastExchangeIndex,q[m];
   for(k=0;k<m;k++)   q[k]=k;
   i=m;
   while(i>0)
   {
       LastExchangeIndex=0;
       for(j=1;j<i;j++)
       {
           if(count[j]<count[j-1])
           {
                swap(&count[j],&count[j-1]);
                LastExchangeIndex=j;
                swap(&q[j],&q[j-1]);                     
           }                
       }  
       i=LastExchangeIndex;        
   }
   for(i=0;i<m;i++)
      puts(DNA[q[i]]);                
   system("pause");
   return 0;
}
