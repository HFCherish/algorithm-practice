#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double avg( int a,int b )
{
	return ( a+b ) / 2.0;	
}

int main()
{
	int a[6];
	while( scanf("%d",&a[0]) != EOF )
	{
		int i;
		double res;
		for( i=1; i<6; i++ )	scanf("%d",&a[i]);
		if( abs(a[3]-a[2]) <= a[1] )	res = avg( a[2], a[3] );
		else
		{
			int p,q;
			p = abs( a[4]-a[2] );
			q = abs( a[4]-a[3] );
			if( p<=a[1] && q>a[1] )	res = avg( a[4], a[2] );
			else if( p>a[1] && q<=a[1] ) res = avg( a[4], a[3] );
				else if( p<=a[1] && q<=a[1] ) res = ( a[2]>a[3]?a[2]:a[3] ) > a[4]? ( a[2]>a[3]?a[2]:a[3] ):a[4];
					else res = a[5];
		}
		printf("%.1lf\n",res);	
	} 
    return 0;
}
