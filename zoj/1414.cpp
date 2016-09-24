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
		if(a<b)	printf("No Number");
		else
		{ 
			int p,q;
			p = a%2;
			q = b%2;
			if(p==0 && q==0)	printf("%d",a+b);
			else if(p!=0 && q!=0)	printf("%d",a+b-1);
				else	printf("No Number");
		}
		if(i<n-1)	printf("\n"); 		
	} 
    return 0;
}
