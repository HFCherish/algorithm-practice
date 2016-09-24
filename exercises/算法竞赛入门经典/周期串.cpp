#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    char a[100];
    gets(a);
    int t = 1;
    int len = strlen(a);
    for(int i=1; i<=len; i++)
    {
         if(len%i == 0)
         {
               for(int j=i; j<len; j++)
               {
                     if(a[j] != a[j%i])  
                     {
                         t = 0;
                         break;        
                     }
               }   
         } 
         if(t)  printf("%d\n",i);            
    }
    system("pause");
    return 0;
}
