#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n%2==0 || n==1)
			printf("2^? mod %d = 1\n",n);
		else
		{
			int i,t=1;
			for(i=1; ;i++)
			{
				t *= 2;
				t %= n;
				if(t == 1)
				{
					printf("2^%d mod %d = 1\n",i,n);
					break;	
				}	
			}	
		}	
	} 
    return 0;
}
