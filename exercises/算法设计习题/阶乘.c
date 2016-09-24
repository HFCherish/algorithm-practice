#include <stdio.h>

int main()
{   
    int i,j;    
    for(j=1; j<=100; j++)
    {
             long long int res=1ll;
             for(i=1; i<=j; i++)
                      res = res*i;
             printf("%d!=%I64d      ",j,res);
     }
    system("pause");
    return 0; 
}
