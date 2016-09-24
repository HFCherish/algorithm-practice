#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int squ(int n)
{
	return n*n;	
}

int main()
{
	int	a[3],t=0;
	while(scanf("%d%d%d",&a[0],&a[1],&a[2]) && a[0]!=0)
	{
		t++;
		int i,m;
		for(i=0; i<3; i++)
		{
			if(a[i] == -1)
			{
				m = i;
				break;
			}
		} 
		printf("Triangle #%d\n",t); 
		if(m==2)	printf("c = %.3lf\n\n",sqrt(squ(a[0])+squ(a[1])));  
		else
		{
			int p = squ(a[2])-squ(a[!m]);
			if(p<0)	printf("Impossible.\n\n");
			else  printf("%c = %.3lf\n\n",m+'a',sqrt(p));	
		}
	} 
    return 0;
}
