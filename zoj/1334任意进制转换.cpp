#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/*int start[1000],ans[1000],res[1000];	//±»³ıÊı¡¢ÓàÊı

void change( char *a )
{
	start[0] = strlen(a);
	int i;
	for( i=0; i<start[0]; i++ )
	{
		if( a[i]>='A' && a[i]<='Z' )	start[i+1] = a[i]-'A'+10;
		else if( a[i]>='a' && a[i]<='z' )	start[i+1] = a[i]-'a'+10;
		else	start[i+1] = a[i]-'0';	
	}	
}

int solve( int ori,int to )
{
	memset(res,0,sizeof(res));
	int i;
	while( start[0] > 0 )
	{
		memset(ans,0,sizeof(ans));
		int y = 0;
		ans[0] = start[0];
		for( i=1; i<=start[0]; i++ )
		{
			y = y*ori + start[i];
			ans[i] = y/to;
			y %= to;	
		}
		res[++res[0]] = y;
		if( res[0]>7 )
		{
			return 0;	
		}
		for( i=1; i<=ans[0] && ans[i]==0; i++ );
		if( i>ans[0] ) break;
		memset(start,0,sizeof(start));
		for( int j=i; j<=ans[0]; j++ )
			start[++start[0]] = ans[j];
	}
	return 1; 	
}

int main()
{
	char a[1000];
	int ori,to;
	while( scanf("%c",&a[0])!=EOF )
	{
		while( a[0] == ' ' )
			scanf("%c",&a[0]);
		scanf("%s%d%d",a+1,&ori,&to);	
		getchar();
		change(a);
		if( solve(ori,to) )
		{
			int i;
			for( i=0; i<7-res[0]; i++ )
				printf(" "); 
			for( int i=res[0]; i>0; i-- )
			{
				if( res[i]>9 )	printf("%c",res[i]-10+'A');
				else	printf("%d",res[i]);	
			} 
		}
		else	printf("  ERROR");
		printf("\n"); 
	} 
    return 0;
}*/

int main()
{
	char num[50];
	int ori,to;
	while( scanf("%s%d%d",num,&ori,&to)!=EOF )
	{
		int len = strlen(num);
		int i,sum = 0,a,b=1;
		for( i=len-1; i>=0; i-- )
		{
			if( num[i]>='A' && num[i]<='Z' )	a = num[i]-'A'+10;
			else a = num[i]-'0';
			sum += a*b;
			b *= ori;
		}
		int res[8];
		i = 0;
		while( sum )
		{
			res[i++] = sum%to;
			sum /= to;
			if( i>7 )	break;
		} 
		if( i>7 )	printf("  ERROR");
		else
		{
			for( int j=0; j<7-i; j++ )	printf(" ");
			for( i=i-1; i>=0; i-- )	
			{
				if( res[i]>9 )	printf("%c",res[i]-10+'A');
				else	printf("%c",res[i]+'0');	
			}
		}
		printf("\n");
	}	
	return 0;
}








