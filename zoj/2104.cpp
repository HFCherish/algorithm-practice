#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		char a[n][20];
		int b[n],max=0;
		memset(b,0,n*sizeof(int)); 
		int i,j;
		for(i=0; i<n; i++)
		{
			getchar();
			scanf("%s",a[i]);
			for(j=0; j<=i; j++)
			{
				if(strcmp(a[i],a[j]) == 0)
				{
					b[j]++;
					max = b[j]>b[max]?j:max;
					break;	
				}	
			}
		}
		printf("%s\n",a[max]);	
	} 
    return 0;
}
