#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a[50],b[50],cc;
	int am,res;
	while( scanf("%s",a) && a[0]!='#' )
	{
		res = 0;
		while( a[0]!='0' )
		{
			scanf("%s%d",b,&am);
			getchar();
			cc = getchar();
			if( cc=='F' )	res += am*2;
			else if(cc=='B' ) res += (am+1)/2*3;
			else if( am<500 ) res += 500;
				else res += am;
			scanf("%s",a);	
		} 
		printf("%d\n",res); 
	} 
    return 0;
}
