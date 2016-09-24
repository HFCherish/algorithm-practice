#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[16][3];
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<3; j++)
			scanf("%d",&a[i][j]);	
	} 
	int b[3];
	while(scanf("%d%d%d",&b[0],&b[1],&b[2]) && b[0]!=-1)
	{
		int min;
		min = 0;
		for(int i=1; i<16; i++)
		{
			int t=0; 
			for(int j=0; j<3; j++)
				t += (a[i][j] + a[min][j] - 2*b[j]) * (a[i][j] - a[min][j]); 
			min = t<0?i:min;	
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",b[0],b[1],b[2],a[min][0],a[min][1],a[min][2]); 
	} 
    return 0;
}
