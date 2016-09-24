#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while( scanf("%d",&n) && n )
	{
		int a[n],sum,sam,flag=0;
		sum = sam = 0;
		int i;
		for( i=0; i<n; i++ )
		{
			scanf("%d",&a[i]);
			sum += a[i];	
		}	
		if( sum%2==0 )
		{
			int tp = sum/2;
			for( i=0; i<n; i++ )
			{
				sam += a[i];
				if( sam>=tp )	break;	
			}
			if( sam==tp )	flag = 1;
		}
		if( flag )
			printf("Sam stops at position %d and Ella stops at position %d.\n",i+1,i+2);
		else	printf("No equal partitioning.\n");
	}
    return 0;
}
