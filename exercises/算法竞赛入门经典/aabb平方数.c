#include <stdio.h>
#include <math.h>

int main()
{
    int i,j;
    for(i=1; i<10; i++) 
    {
             for(j=0; j<10; j++)
             {
                      int a = i*1100 + j*11;
                      double m = sqrt(a);
                      if(floor(m+0.5) == m)
                             printf("%d",a); 
             }       
    }
   system("pause");
   return 0;
}

/*int main()
{
    int i;
    for(i=32;;i++)
    {
             int m = i*i;
             printf("%d  ",m); 
             if(m<1000) continue;
             if(m>9999) break;
             int h = m/100, l = m%100;
             if(h/10 == h%10 && l/10 == l%10)
                     printf("%d\n",m);         
    }   
    system("pause");
    return 0; 
}

int main()
{
   int i,j;
   for(i=1; i<=9; i++)
    {
            for(j=0; j<=9; j++)
            {
                     int n = i*1100 + j*11;
                     int m = floor(sqrt(n) + 0.5);
                     if(m*m == n)
                            printf("%d ",n);         
            }        
    }
    printf("\b\n"); 
   system("pause");
   return 0;
}*/
