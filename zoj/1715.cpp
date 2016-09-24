#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,q;
	while( scanf("%d%d",&n,&q) && n!=0 )
	{
		int i,num,a[101]={0},res=0;
		num = n;
		for( i=0; i<n; i++ )
		{
			int m;
			scanf("%d",&m);
			if( m>0 )
			{
				int p,b;
				for( p=0; p<m; p++ )
				{
					scanf("%d",&b);
					if( num>=q )
						a[b]++;
				}
			}
			else	num--;
		}
		if( num>=q )
		{
			for( i=0; i<=100; i++ )
			{
				if( a[i]>a[res] )
					res = i;	
			}	
			if( a[res]<q )	res = 0;
		}
		printf("%d\n",res);	
	} 
    return 0;
}
