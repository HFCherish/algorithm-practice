#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		int a[4] = {0};
		int i,p,q;
		for( i=0; i<n/2; i++ )
		{
			scanf("%d%d",&p,&q);
			if( p+q == 0 )	a[0]++;
			else if( p+q == 2 )	a[3]++;
			else if( p==0 && q==1 )	a[1]++;
			else a[2]++;	
		}
		int res = 0;	
		int small = a[1]<a[2]?1:2;
		if( n%2 )
		{
			scanf("%d",&p);
			if( p )		a[2]++;
			else	a[1]++;	
			small = a[1]<a[2]?1:2;
			if( small == p+1 )	res--;
		}	
		res += a[0] + a[3] + 2*a[small];
		printf("%d\n",res);
	}
    return 0;
}
