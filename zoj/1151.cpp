#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int n,m;
	scanf("%d",&n); 
	char s[100];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&m); 
		getchar();
		for(int j=0; j<m; j++)
		{
			gets(s);
			int t,m,len;
			len = strlen(s);
			for(int p=0; p<len; p++)
			{
				m = p;
				for(; isalpha(s[p]) && p<len; p++);	
				for(t=p-1; t>=m; t--)	printf("%c",s[t]);
				if(p<len)	putchar(' ');
			}
			putchar('\n');
		}
		if(i<n-1)	putchar('\n');	
	} 
	system("pause"); 
    return 0;
}
