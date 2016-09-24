#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k;
	while( scanf("%d%d",&n,&k) != EOF )
	{
		int m,in=0;
		double price,rate;
		rate = 1 + (double)k/100;
		price = 200/rate; 
		for( m=1; m<=20; m++ )
		{
			in += n;
			price *= rate;
			if( in>=price )
			{
				printf("%d\n",m);
				break;	
			}			
		}	
		if( m>20 )
			printf("Impossible\n");
	} 
    return 0;
}
