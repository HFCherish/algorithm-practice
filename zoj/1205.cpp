#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char a[150],b[150];
	while(scanf("%s%s",a,b) != EOF)
	{
		int c[150] = {0};
		int len1,len2;
		len1 = strlen(a);
		len2 = strlen(b);
		int i,j,t=0;
		for(i=len1-1,j=len2-1; i>=0 && j>=0; i--,j--,t++)
		{
			if(isalpha(a[i]))	c[t] += a[i]-'a'+10;
			else	c[t] += a[i]-'0';
			if(isalpha(b[j]))	c[t] += b[j]-'a'+10;
			else 	c[t] += b[j]-'0';
			if(c[t]>19)
			{
				c[t+1] += c[t]/20;
				c[t] %=20;	
			}
		}
		if(i>=0)
		{
			for(; i>=0; i--,t++)
			{
				if(isalpha(a[i]))	c[t] += a[i]-'a'+10;
				else	c[t] += a[i]-'0';
				if(c[t]>19)
				{
					c[t+1] += c[t]/20;
					c[t] %=20;	
				}	
			}	
		}
		else if(j>=0)
		{
			for(; j>=0; j--,t++)
			{
				if(isalpha(b[j]))	c[t] += b[j]-'a'+10;
				else	c[t] += b[j]-'0';
				if(c[t]>19)
				{
					c[t+1] += c[t]/20;
					c[t] %=20;	
				}	
			}	
		}	
		if(c[t]==0)	t--;
		else 
		{
			while(c[t]>19)
			{
				c[t+1] += c[t]/20;
				c[t] %=20;
				t++;
			}	
		}
		for(i=t; i>=0; i--)
		{
			if(c[i]>9)	printf("%c",c[i]-10+'a');
			else	printf("%d",c[i]);	
		}	
		printf("\n"); 
	}
    return 0;
}
