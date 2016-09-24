#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,t=0;
	while(scanf("%d",&n) && n!=0)
	{
		t++;
		int a[n];
		int i,sum=0;
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int avg = sum/n;
		sum = 0;
		for(i=0; i<n; i++)
		{
			if(a[i]>avg)	sum += a[i] - avg;	
		}	
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,sum); 
	} 
    return 0;
}
