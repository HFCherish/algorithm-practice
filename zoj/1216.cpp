#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a; 
	printf("# Cards  Overhang\n");
	while(scanf("%d",&a) != EOF)
	{
		double res = 0.0;
		for(int p=1; p<=a; p++)
		{
			res += 1.0/(2*p);	
		}
		printf("%5d%10.3f\n",a,res); 
	} 
    return 0;
}
