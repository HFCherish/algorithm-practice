#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		char s[10];
		int m;
		getchar();
		scanf("%s",s);
		scanf("%d",&m);
		int a[m];
		scanf("%d",&a[0]);
		int res = a[0];
		for(int j=1; j<m; j++)
		{
			scanf("%d",&a[j]);
			if(s[0] == 'F')
				res = res>a[j]?a[j]:res;
			else
				res = res<a[j]?a[j]:res;	
		}	
		printf("%d",res);
		if(i<n-1)	putchar('\n'); 
	} 
	system("pause"); 
    return 0;
}
