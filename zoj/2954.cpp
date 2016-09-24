#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int cases;
	scanf("%d",&cases);
	for( int i=0; i<cases; i++ )
	{
		int n,m,res=0;
		scanf("%d%d",&n,&m);
		int a[4][n+1],j,from,to,flag = 0;
		memset(a,0,sizeof(a)); 
		for( j=1; j<n+1; j++ )	a[1][j] = j;
		a[1][0] = n;
		for( j=0; j<m; j++ )
		{
			scanf("%d%d",&from,&to);
			if( flag ==0 )
			{
				int p,q;
				p = a[from][0];
				q = a[to][0];
				if( a[from][p] < a[to][q] )
				{
					res = -(j+1);
					flag = 1;
					continue;
				}
				else
				{
					a[to][q+1] = a[from][p];
					a[from][0]--;
					a[to][0]++;
					if( to==3 && a[to][0]==n )
					{
						res = j+1;
						flag = 1;
						continue;
					}
				}
			}
		}
		printf("%d\n",res);
	}  
	return 0;
}




















