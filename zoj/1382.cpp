#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int d;
	scanf("%d",&d);
	for(int i=0; i<d; i++)
	{
		int n;
		scanf("%d",&n);
		int o,p,m;
		if(n%2)
			printf("%d 0",n);
		else
		{
			for(o=1; ;o+=2)
			{
				for(p=0; ;p++)
				{
					m = o * (int)pow(2,p);
					if(m >= n)	break;
				}
				if(m == n)	break;
			}
			if(m == n)	printf("%d %d",o,p); 
		}	
		if(i<d-1)	printf("\n"); 
	} 
    return 0;
}
