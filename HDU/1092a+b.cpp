#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,sum,a;
	while(scanf("%d",&n) && n!=0)
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
