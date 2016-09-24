#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	double m;
	while(scanf("%d",&n) != EOF)
	{
		scanf("%lf",&m);
		double sum,max,min;
		sum = max = min = m;
		for(int i=1; i<n; i++)
		{
			scanf("%lf",&m);
			sum += m;
			if(m > max)	max = m;
			else if(m < min) min = m;	
		}	
		sum = sum - (max+min);
		printf("%.2lf\n",sum/(n-2)); 
	} 
    return 0;
}
