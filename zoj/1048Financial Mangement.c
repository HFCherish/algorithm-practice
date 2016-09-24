#include<stdio.h>

int main()
{
    double a[12],ave=0.0;
    int i;
    for(i=0;i<12;i++)
    {
       scanf("%lf",&a[i]);
       ave+=a[i];                 
    }
    printf("$%.2lf\n",ave/12); 
    getchar();
    getchar();
    return 0;
}
