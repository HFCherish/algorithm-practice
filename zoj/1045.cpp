#include <stdio.h>
#include <stdlib.h>

int main()
{
	double c;
	while(scanf("%lf",&c) && c>0.00) 
	{
		double sum = 0.00;
		int	t;
		for(t=2; sum<c; t++)
		{
			sum += 1.0/t;	
		}
		printf("%d card(s)\n",t-2); 
	}
	system("pause"); 
    return 0;
}
