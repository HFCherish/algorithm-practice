#include <stdio.h>
#include <stdlib.h>

int main()
{
	int d,a;
	scanf("%d",&d);
	for( int i=0; i<d; i++ )
	{
		scanf("%d",&a);	
		int flag = 1;
		for( int j=0; a; j++ )
		{
			if( a%2 )	
			{
				if( flag )	{ printf("%d",j);	flag = 0; }
				else 	printf(" %d",j);	
			}
			a /= 2;
		}
		if( i<d-1 )	printf("\n"); 
	}
    return 0;
}
