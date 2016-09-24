#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,u,d;
	while(scanf("%d%d%d",&n,&u,&d) && n!=0)
	{
		int a,b,c;
		a = u-d;
		b = n-u;
		c = b/a;
		if(b == a*c)	c = c*2+1;
		else	c = c*2+3;
		printf("%d\n",c);	
	} 
    return 0;
}
