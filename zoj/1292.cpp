#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int b[10050];
int main()
{
	int n;
	scanf("%d",&n);
	char a[150];
	for(int i=0; i<n; i++)
	{
		memset(b,0,10050*sizeof(int));
		int t,j;
		t = j = 0;
		while(scanf("%s",a) && !(a[0]=='0' && a[1]=='\0'))
		{
			int i;
			t = strlen(a);
			for(i=t-1,j=0; i>=0; i--,j++)
			{
				b[j] += a[i]-'0';
			}
		}
		for(t=0; t<j; t++)
		{
			b[t+1] += b[t] / 10;
			b[t] = b[t] % 10;	
		}
		for(; b[t]>9; t++)
		{
			b[t+1] += b[t] / 10;
			b[t] = b[t] % 10;	
		}
		if(b[t] == 0)	t--;
		for(; t>=0; t--)
			printf("%d",b[t]);
		printf("\n");	
		if(i < n-1)	printf("\n"); 
	} 
	system("pause"); 
    return 0;
}
