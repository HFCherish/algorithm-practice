#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int n;
	while(scanf("%ud",&n) && n!=0)
	{
		int res = 0;
		for(; n>1; res++,n=(n+1)/2);
		printf("%d\n",res);	
	} 
    return 0;
}
