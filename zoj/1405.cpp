#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	char a[1000];
	while(scanf("%d",&n) && n!=0)
	{
		getchar();
		int b[100] = {0};
		scanf("%s",a);
		int len = strlen(a);
		int i,go=0;
		for(i=0; i<len; i++)
		{
			char t = a[i];
			if(b[t]==1)
			{
				b[t] = 0;
				n++;	
			}	
			else if(b[t] == 0)
			{
				if(n>0)
				{
					b[t] = 1;
					n--;	
				}
				else 
				{
					go++;
					b[t] = -1;	
				}
			}
		}
		if(go)	printf("%d customer(s) walked away.\n",go);
		else	printf("All customers tanned successfully.\n"); 
	} 
    return 0;
}
