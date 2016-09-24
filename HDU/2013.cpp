#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int x = 1;
		for(int i=1; i<n; i++)
		{
			x = (x+1) * 2;	
		}	
		printf("%d\n",x); 
	} 
    return 0;
}
