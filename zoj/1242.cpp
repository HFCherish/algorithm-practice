#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int w,d,t=0;
	while( scanf("%d%d",&w,&d) && w!=0 )
	{
		t++;
		double x,y;
		int res;
		x = 810.0/((double)d/w);
		y = log(x) / log(2) * 5730;
		res = (int)y;
		if( res<10000 )
			res = (res+50) /100 * 100;
		else res = (res+500) /1000 * 1000;
		printf("Sample #%d\n",t);
		printf("The approximate age is %d years.\n\n",res);	
	}	
}
