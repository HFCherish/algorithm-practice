#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) && !(n==0 && m==0))
	{
		int a,flag=0;
		for(int i=0; i<n-1; i++)
		{
			scanf("%d",&a);
			if(a>=m && flag==0)	
			{
				printf("%d ",m);
				flag = 1;
			}
			printf("%d ",a);
		}
		scanf("%d",&a);
		if(!flag)
		{
			if(a>=m)	printf("%d %d\n",m,a);
			else	printf("%d %d\n",a,m);	
		}
		else	printf("%d\n",a);
	} 
    return 0;
}
