#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    double sum = 0.0;
    int i;
    for(i=1; i<=n; i++)
             sum += 1.0/i;
    printf("%.3lf\n",sum); 
    
    system("pause");
    return 0;
}
