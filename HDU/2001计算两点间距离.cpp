#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double x1,y1,x2,y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2) == 4)
	{
		double a = x1-x2;
		double b = y1-y2;
		printf("%.2lf\n",sqrt(a*a + b*b));
	} 
    system("pause");
    return 0;
}
