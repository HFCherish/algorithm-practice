#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	while( scanf("%d",&n) != EOF )
	{
		long long int a[n];
		int i,j;
		for( i=0; i<n; i++ )
			scanf( "%lld",&a[i] );	
		scanf("%d",&m);
		long long int b[m],res;
		for( i=0; i<m; i++ )
			scanf( "%lld",&b[i] );
		int k = ( m+n+1 ) / 2;
		for( i=0,j=0; i<n && j<m; )
		{
			if( a[i]<b[j] )
			{
				k--;
				if( k == 0 )
				{
					res = a[i];	
					break;
				}	
				i++;
			}	
			else if( a[i]>b[j] )
				{
					k--;
					if( k == 0 )
					{
						res = b[j];	
						break;
					}	
					j++;	
				}
				else if( a[i]==b[j] )
				{
					k -= 2;
					if( k==0 || k==-1)
					{
						res = a[i];	
						break;
					}	
					j++;
					i++;	
				}
		}
		if( i<n && k>0 )	res = a[i+k-1];
		if( j<m && k>0 ) 	res = b[j+k-1];
		printf("%lld\n",res); 
	} 
    return 0;
}
