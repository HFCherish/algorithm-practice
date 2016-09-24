#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n,sum,a;
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&n);
		sum = 0;
		for(int j=0; j<n; j++)
		{
			scanf("%d",&a);
			sum += a; 
		}	
		printf("%d\n",sum); 
	} 
    system("pause");
    return 0;
}
