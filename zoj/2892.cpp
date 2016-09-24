#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while( scanf("%d",&n) && n!=0 )
	{
		int a[n];
		int j;
		for( j=0; j<n; j++ )
		{
			scanf("%d",&a[j]);	
		}	
		for( j=1; j<=n; j*=2 )
		{
			int t1,t2;
			t2 = a[0];
			for( int p=0; p<j; p++ )
			{
				t1 = (a[p]+a[p+j])/2;
				a[p] = t2;
				t2 = a[p]-t1;
				a[p+1] = t1;
			}	
		}
		for( j=0; j<n; j++ )
		{
			if( j<n-1 )
				printf("%d ",a[j]);
			else printf("%d\n",a[j]);	
		}
	}
    return 0;
}
