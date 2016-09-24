#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char a[51];
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",a);
		printf("String #%d\n",i+1); 
		for(int j=0; a[j]; j++)
		{
			char c;
			c = (a[j]+1-'A') % 26 + 'A';
			printf("%c",c);	
		}
		printf("\n\n"); 
	} 
	system("pause"); 
    return 0;
}
