#include<stdio.h>
#include<memory.h>
#include<string.h>

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
       int m=2,p,a[n];       
       for(;;m++)
       {
          /*p=n;
          int sum=0;
          while(p>1)
          {
              sum+=p;     
              if(n<m)
                p=p-(p+m-1)/m;
              else  p=p-p/m;
              if(sum%m==0)  break;        
          }          
          if(p==1)
          {
             printf("%d\n",m);
             break;        
          }*/
          int k = 1,count = 0;
          memset(a,0,sizeof(a));
          while(k!=2)
          {
              a[k-1] = 1;
              count++;
              k = (k+m) % n; 
              if(k == 0)   k = n;             
              while(a[k-1])  
              {
                  k = (k+m+1) % n;  
                  if(k == 0)   k = n;  
              }     
          }
          if(count == n-1)  
          {
                   printf("%d\n",m);
                   break;
          } 
       }                     
    } 
    system("pause"); 
    return 0;
}
