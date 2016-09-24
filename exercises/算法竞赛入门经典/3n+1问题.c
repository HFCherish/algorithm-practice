#include <stdio.h>

int main()
{
    /*long long int n;
    scanf("%I64d",&n);
    int count = 0;
    while(n > 1)
    {
            if(n%2 == 0) 
            {
                   n/=2;
                   count++;
            }
            else 
            {
                 n = (3*n + 1) / 2; 
                 count += 2;        
            }
    } 
    printf("%d",count); */
    
    int n;
    scanf("%d",&n);
    int count = 0;
    while(n > 1)
    {
            if(n%2 == 0) 
            {
                   n/=2;
                   count++;
            }
            else 
            {
                 n = (n-1)/2*3 + 2; 
                 count += 2;        
            }
    } 
    printf("%d",count);
    
    
   system("pause");
   return 0;
}





