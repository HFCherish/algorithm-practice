#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	int ncases,sys;
	char num[3][55];
	int temp[3][55],maxlen;
	int sum[100];
	scanf("%d",&ncases);
	while( ncases-- )
	{
		scanf("%d",&sys);
		memset(temp,0,sizeof(temp));
		memset(sum,0,sizeof(sum));
		maxlen = 0;
		for(int i=0; i<3; i++)
		{
			scanf("%s",num[i]);
			int len = strlen(num[i]);
			if( len > maxlen )
				maxlen = len;
			for(int k=0; k<len; k++)
				temp[i][len-k-1] = num[i][k] - '0';
		}
		fnt i=0; i<maxlen; i++)
			suor(im[i] = temp[0][i] + temp[1][i] + temp[2][i];
		for(int i=0; i<maxlen; i++)
			if( sum[i] >= sys )
			{
				sum[i+1] += sum[i]/sys;
				sum[i] %= sys;
			}
		if( sum[maxlen] != 0 )
			maxlen++;
		for(int i=maxlen-1; i>=0; i--)
			printf("%d",sum[i]);
		printf("\n");	
	}
return 0;
}
