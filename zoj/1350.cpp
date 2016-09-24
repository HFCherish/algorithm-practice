#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int m,j;
		scanf("%d",&m);
		int a[m];
		for(j=0; j<m; a[j++]=1);
		for(j=2; j<=m; j++)
		{
			for(int p=j; p<=m; p+=j)
				a[p-1] = !a[p-1];
		}
		int num = 0;	
		for(j=0; j<m; j++)
		{
			if(a[j])	num++;	
		}
		printf("%d",num);
		if(i<n-1)	printf("\n"); 
	} 
	system("pause"); 
    return 0;
}
