#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int b[1001],flag;
	char a[1001];
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
	{
		memset(b,0,1000*sizeof(int));
		flag = 0;
		int j;
		scanf("%s",a);
		int len = strlen(a); 
		for(j=0; j<len; j++)
		{
			if(a[j]!=a[flag])	flag = j;
			b[flag]++;
		}	
		for(j=0; j<=flag; j++)
		{
			if(b[j])	printf("%d%c",b[j],a[j]);	
		}
		if(i<n-1)	printf("\n"); 
	} 
    return 0;
}
