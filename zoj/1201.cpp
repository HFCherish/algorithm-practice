#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int n;
	char c;
	while( scanf("%d",&n) && n!=0 )
	{
		getchar();
		scanf( "%c",&c );
		int a[n],i,b[n];
		memset(b,0,n*sizeof(int));
		for( i=0; i<n; i++ )
			scanf( "%d",&a[i] );
		
		int j;	
		if( c=='P' )
		{
			for( i=1; i<=n; i++ )
			{
				for( j=0; j<n; j++ )
				{
					if( a[j]>i )	b[i-1]++;
					if( a[j]==i ) break;	
				}	
			}	
		} 	
		else if( c=='I' )
		{
			b[0] = n;
			for( i=1; i<n; i++ )
			{
				int t=a[n-1-i];
				if( b[t]!=0 )
				{
					for( j=i; j>t; j-- )
						b[j] = b[j-1];	
				}	
				b[t] = n-i;
			}	
		}
		for( i=0; i<n-1; i++ )
			printf( "%d ",b[i] ); 
		printf( "%d\n",b[i] );
	}    
}
