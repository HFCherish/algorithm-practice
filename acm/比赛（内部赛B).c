#include<stdio.h>
#include<stdlib.h>

int main()
{
   int n,m,t;
   while(scanf("%d%d%d",&n,&m,&t)==3)
   {
      int i,a[n][n];
      for(i=0;i<n;i++)  scanf("%d",&a[m-1][i]);
      for(i=0;i<n;i++)
      {
         int count=0,p=m-1,q=i;
         for(;count<n;count++)
         {
              int p1=p,q1=q;
              if(p==n-1 && q==n-1)    p1=q1=0;
              else 
                 if(p==n-1)  
                 {
                     p1=0;  q1++;       
                 }
                 else
                    if(q==n-1)  
                    {
                        q1=0;   p1++;      
                    }
                    else  
                    {
                        p1++;  q1++;      
                    }  
              a[p1][q1]=a[p][q]; 
              p=p1;   
              q=q1;                  
         }               
      }    
      for(i=0;i<n;i++)
          printf("%d ",a[i][t-1]);                              
   } 
   system("pause");
   return 0;
}
