#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[15],b[15];
	scanf("%s",a);
	getchar();
	scanf("%s",b); 
	while(!(a[0]=='0' && b[0]=='0'))
	{
		int len1,len2,res;
		len1 = strlen(a);
		len2 = strlen(b);
		res = 0;
		int i,j,m,n;
		i = len1-1;
		j = len2-1;
		m = n = 0;
		for(; i>=0&&j>=0; i--,j--)
		{
			m = a[i] + b[j] - 2*'0' + n;
			if(m>9)	 res++;
			n = m/10;
		}
		if(i>=0)	
		{
			for(; i>=0; i--)
			{
				m = a[i] + n -'0';
				n = m/10;
				if(n == 0)	break;
				else	res++;	
			}	
		}	
		else if(j>=0)
		{
			for(; j>=0; j--)
			{
				m = b[j] + n -'0';
				n = m/10;
				if(n == 0)	break;
				else	res++;	
			}	
		}
		if(res == 0)	printf("No carry operation.\n");
		else if(res>1)
			printf("%d carry operations.\n",res);
			else printf("%d carry operation.\n",res); 
		scanf("%s",a);
		getchar();
		scanf("%s",b); 
	} 
    return 0;
}
