#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int n,m;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		int i,a[n],b[n],c[n];
		memset(b,0,sizeof(b));
		for( i=0; i<n; i++ )	
			scanf("%d",&a[i]);	
		for( i=0; i<n-1; i++ )
		{
			if( b[i]==0 )
			{
				int j,k=0;
				for( j=i+1; j<n; j++ )
				{
					if( a[i] == a[j] )
					{
						b[i]++;
						c[k++] = j;
					}	
				}
				for( j=0; j<k; j++ )	
						b[c[j]] = b[i];
			}
			if( b[i] )
				printf("%d\n",b[i]);
			else	printf("BeiJu\n");
		}
		if( b[i] )
			printf("%d\n",b[i]);
		else	printf("BeiJu\n");
	}
    return 0;
}
