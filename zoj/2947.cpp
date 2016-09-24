#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	for( int i=0; i<t; i++ )
	{
		int n,m,res = 1;
		char a[15],b[10];
		scanf("%d",&n);
		int j;
		for( j=0; j<n; j++ )
		{
			getchar();
			scanf("%s",a);	
			b[j] = a[0];
		}	
		scanf("%d",&m);
		if( n!=m ) res = 0;
		for( j=0; j<m; j++ )
		{
			getchar();
			scanf("%s",a);
			if( res )
			{
				if( a[0]!=b[j] )	res = 0;	
			}	
		}
		if( res )	printf("SAME");
		else	printf("DIFFERENT");
		if( i<t-1 )	printf("\n");
	}
    return 0;
}
