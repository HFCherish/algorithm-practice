#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)	printf("NO BRAINS");
		else 	printf("MMM BRAINS");
		if(i<n-1)	printf("\n");	
	} 
    return 0;
}
