#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int m;
		char s[100];
		scanf("%d",&m);
		getchar();
		scanf("%s",s);
		int len = strlen(s);
		printf("%d ",i+1); 
		for(int j=0; j<len; j++)
		{
			if(j != m-1)	putchar(s[j]);	
		}	
		if(i<n-1)	putchar('\n'); 
	} 
	system("pause"); 
    return 0;
}
