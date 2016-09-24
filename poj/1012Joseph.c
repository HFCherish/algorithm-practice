#include <stdio.h>
#include <string.h>

int main()
{
    int k,m;
    a:
    while(scanf("%d",&k) && k!=0)
    {
        int m,a[k];        
        for(m=k;;m++)
        {
            memset(a,1,sizeof(a));
            int j,count=0,i=0;
            for(j=0;j<2*k;j++)
            {
                if(a[j])
                {
                    i++;
                    if(i%m==0)
                    {
                       count++;
                       if(j<k && count<k)
                           break;       
                       else 
                          if(count==k)
                          {
                             printf("%d\n",m+1);
                             goto a;            
                          }
                       a[j]=0;          
                    }        
                }                  
            }             
        }                             
    } 
    system("pause");
    return 0;   
}
