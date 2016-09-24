#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n;
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&n);
		double sum = 0.00;
		int t = -1;
		for(int j=1; j<=n; j++)
		{
			t = -t;
			sum += (double)t/j;	
		}
		printf("%.2lf\n",sum);	
	} 
	system("pause"); 
    return 0;
}
