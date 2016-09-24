#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n!=-1)
	{
		int s,t[n+1],sum;
		t[0] = sum = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&s,&t[i]);
			sum += s*(t[i]-t[i-1]);
		}
		printf("%d miles\n",sum); 
	} 
    return 0;
}
