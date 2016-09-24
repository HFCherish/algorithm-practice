#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a;
	while(scanf("%lf",&a) != EOF)
	{
		printf("%.2lf\n",fabs(a));	
	} 
    system("pause");
    return 0;
}
