#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
   int t, n;
   scanf("%d",&t);
   int i;
   for(i=0; i<t; i++)
   {
            scanf("%d",&n);
            int a[n],j,b[2*n],c[n];
            for(j=0; j<n; j++)
                     scanf("%d",&a[j]);
            memset(b, 0, sizeof(b));  
            memset(c, 0, sizeof(c));
            for(j=0; j<n; j++)
            {
                     int k = a[j]+j;
                     b[k] = 1;
                     int m;
                     for(m=k; m>=0; m--)
                     {
                              if(b[m]==1) c[j]++;
                              else if(b[m] == 0)
                                   {
                                           b[m] = -1;
                                           break;
                                   }
                     }
            }
            for(j=0; j<n-1; j++)
                     printf("%d ",c[j]);
            printf("%d\n",c[j]);          
   } 
   system("pause");                  
   return 0;
}
