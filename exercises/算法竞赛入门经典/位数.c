#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    scanf("%d",&n);
    while(n!=0)
    {
        n/=10;     
        count++;  
    } 
    printf("%d\n", count);
    system("pause");
    return 0;
}
