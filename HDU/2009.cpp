#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		double sum = 0.00;
		double x = (double)n;
		for(int i=0; i<m; i++)
		{
			sum += x;
			x = sqrt(x);
		}
		printf("%.2lf\n",sum);	
	} 
    system("pause");
    return 0;
}
