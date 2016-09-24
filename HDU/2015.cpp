#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		int i,avg,p;
		i = n/m;
		p = 2;
		if(n == m*i)	i--;
		for(int j=0; j<i; j++)
		{
			int q = (m-1)*2 + p;
			avg = (p+q)/2;
			p = q+2;
			printf("%d ",avg);			 	
		}
		avg = (p+n*2) / 2;
		printf("%d\n",avg);	
	}
    return 0;
}
