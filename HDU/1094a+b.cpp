#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,a,sum;
	while(scanf("%d",&n) != EOF)
	{
		sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a);
			sum += a;	
		}
		printf("%d\n",sum); 
	} 
    //system("pause");
    return 0;
}
