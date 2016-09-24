#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159 

int main()
{
	char start[15],end[5];
	int x,y,z;
	while( scanf("%s",start) && start[0]!='E' )
	{
		scanf("%d%d%d",&x,&y,&z);
		scanf("%s",end);
		if( z>180 )	z = 360-z;
		double need;
		need = (2*PI*x*(z/360.0)) / 5.0 * 2;
		if( need > y )
			printf("NO %d\n",y*5);
		else
			printf("YES %d\n",(int)(y-need));	
	}
    return 0;
}
