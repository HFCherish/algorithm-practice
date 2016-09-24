#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int n,m;
	while( scanf("%d%d",&n,&m) && n!=0 )
	{
		int a[n+1],b,res = 0;
		memset(a,0,sizeof(a));
		for( int i=0; i<m; i++ )
		{
			scanf("%d",&b);	
			if(	a[b] == 0 )	a[b] = 1;
			else if( a[b]==1 )
			{
				a[b] = -1;
				res++;	
			}
		}
		printf("%d\n",res);
	} 
	return 0;
}
