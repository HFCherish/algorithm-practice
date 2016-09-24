#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double m,n;
	scanf("%lf",&m);
	while( scanf("%lf",&n) && !(fabs(n-999)<10e-6) )
	{
		printf("%.2lf\n",n-m);
		m = n;	
	}	
	printf("End of Output\n");
    return 0;
}
