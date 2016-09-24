#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++)
	{
		int n,j;
		scanf("%d",&n);
		int c[n+1];
		for(j=n; j>=0; j--)
			scanf("%d",&c[j]);
		if(n == 0)	printf("0\n"); 
		else
		{
			for(j=n; j>1; j--)
			{
				int m;
				m = j * c[j];
				printf("%d ",m); 
			}	
			printf("%d\n",c[j]) ;
		}
	} 
	system("pause"); 
    return 0;
}
