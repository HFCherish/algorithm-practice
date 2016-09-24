#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		if(x>y)	x ^= y ^= x ^= y;
		int even = 0;
		int odd = 0;
		int i=x+1,j=x+1;
		if(x%2 == 0)	i = x;
		else 	j = x;
		for(; i<=y; i+=2)	even += i*i;
		for(; j<=y; j+=2)	odd += j*j*j;
		printf("%d %d\n",even,odd);	
	} 
    system("pause");
    return 0;
}
