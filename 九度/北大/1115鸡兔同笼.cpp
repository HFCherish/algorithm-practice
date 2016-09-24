#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,a;
	scanf("%d",&n); 
	for( int i=0; i<n; i++ )
	{
		int min,max;
		min = max = 0;
		scanf("%d",&a);
		if( a%2 == 0 )
		{
			max = a/2;
			if( a%4 )	min = (a-2)/4+1;
			else	min = a/4;	
		}	
		printf("%d %d",min,max);
		if( i<n-1 )	printf("\n");
	} 
    return 0;
}
