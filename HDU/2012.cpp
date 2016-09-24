#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
	if(n==0 || n==1)	return 0;
	if(n == 2)	return 1;
	if(n%2 == 0)	return 0;
	for(int i=3; i<=n/2; i+=2)
	{
		if(n%i == 0)	return 0;	
	}	
	return 1;
}

int f(int n)
{
	return n*n + n + 41;	
}

int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF	&& !(x==0 && y==0))
	{
		if(x>y)	x^=y^=x^=y;
		int flag = 1;
		for(int i=x; i<=y; i++)
		{
			int n = f(i);
			if(!isPrime(n))	
			{
				flag = 0;
				break;
			}
		}	
		if(flag)	printf("OK\n");
		else	printf("Sorry\n"); 
	} 
    return 0;
}
