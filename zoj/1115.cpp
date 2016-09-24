#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int root(char*a)
{
	int sum;
	sum = 0;
	int n = strlen(a);
	for(int i=0; i<n; i++)
		sum += a[i]-'0';	
	if(sum>9)	
	{
		char s[20];
		sprintf(s,"%d",sum);
		return root(s);
	}
	return sum;	
}

int main()
{
		char a[1000];  
		while(scanf("%s",a) && a[0]!='0')
		{ 
			printf("%d\n",root(a)); 
			getchar();
		}
    	return 0;
}
