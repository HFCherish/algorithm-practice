#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,a;
	while(scanf("%d",&n)!=EOF)
	{
		int sum = 1;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a);
			if(a%2)	sum *= a;	
		}
		printf("%d\n",sum); 
	} 
    system("pause");
    return 0;
}
