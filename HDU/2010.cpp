#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		int flag = 0;
		for(int i=m; i<=n; i++)
		{
			int a,b,c;
			a = i%10;
			b = i/10%10;
			c = i/100;
			int sum = a*a*a + b*b*b + c*c*c;
			if(sum == i)
			{
				if(flag == 0)
				{
					printf("%d",i);	
					flag = 1;
				}
				else	printf(" %d",i); 
			}
		}
		if(flag == 0)	printf("no"); 
		printf("\n");
	} 
    system("pause");
    return 0;
}
