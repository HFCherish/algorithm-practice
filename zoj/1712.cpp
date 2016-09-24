#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char a[100];
	while(scanf("%s",a) && !(a[0]=='0' && a[1]=='\0'))
	{
		int sum,len;
		sum = 0;
		len = strlen(a);
		int i;
		for(i=0; i<len; i++)
		{
			if(a[i])
				sum += (a[i]-'0') * ((int)pow(2,len-i)-1);
		}
		printf("%d\n",sum);	
	} 
    return 0;
}
