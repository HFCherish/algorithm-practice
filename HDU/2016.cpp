#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		int a[n];
		int min = 0;
		int i;
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<a[min])	min = i;				
		}	
		if(min != 0)
		{
			a[min] ^= a[0] ^= a[min] ^= a[0];	
		}
		for(i=0; i<n-1; i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
    return 0;
}
