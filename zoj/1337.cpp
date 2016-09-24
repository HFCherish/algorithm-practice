#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GCD( int a, int b )
{
	if( a<b )	a^=b^=a^=b;
	while( b )
	{
		int t = a%b;
		a = b;
		b = t;	
	}
	return a;	
}

int main()
{
	int n;
	while( scanf("%d",&n) && n!=0 )
	{
		int a[n],b[n],i,j,k,num;	
		i = j = 0;
		for( k=0; k<n; k++ )
		{
			scanf("%d",&num);
			if( num%2 )	a[i++] = num;	//a´æÆæÊý
			else b[j++] = num; //b´æÅ¼Êý
		}
		int pair = 0;
		if( i )
		{
			for( int p=0; p<i; p++ )
			{
				for( int q=0; q<j; q++ )
				{
					int gcd;
					gcd = GCD(a[p],b[q]);
					if( gcd == 1 )	pair++;
				}
			}
			for( int p=0; p<i-1; p++ )
			{
				for( int q=p+1; q<i; q++)
				{
					int gcd;
					gcd = GCD(a[p],a[q]);
					if( gcd == 1 ) pair++;	
				}	
			}
		}
		if( pair )	
		{
			int all = n*(n-1)/2;
			double ratio = (double)pair/all;
			printf("%.6lf\n",sqrt(6/ratio));
		}	
		else	printf("No estimate for this data set.\n"); 
	} 
    return 0;
}
