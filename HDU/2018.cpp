#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
	if(n<=4)	return n;
	return f(n-3) + f(n-1);	
} 

int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
		printf("%d\n",f(n)); 
    return 0;
}
