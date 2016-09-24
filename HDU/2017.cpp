#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++)
	{
		int num = 0;
		char c;
		while(scanf("%c",&c) && c!='\n')	//ÓÐÎÊÌâ£¡£¡£¡ 
		{
			if(isdigit(c))	num++;	
		}
		printf("%d\n",num);
	}
	//system("pause");
    return 0;
}
