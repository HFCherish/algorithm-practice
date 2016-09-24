#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int n,m,C;
	int t = 0;
	while(scanf("%d%d%d",&n,&m,&C) && !(n==0 && m==0 && C==0))
	{
		t++;
		int c[n],op[m],flag[n];
		int i,sum,blow,max;
		sum = blow = max = 0;
		memset(flag,0,sizeof(int)*n); 
		for(i=0; i<n; i++) scanf("%d",&c[i]);
		for(i=0; i<m; i++) scanf("%d",&op[i]);
		for(i=0; i<m; i++)
		{
			int j = op[i]-1;	
			if(flag[j] == 0)  flag[j] = 1;
			else	flag[j] = -flag[j];
			sum += flag[j]*c[j];
			if(sum <= C) max = max<sum?sum:max;
			else 
			{
				blow = 1; 
				break;
			}
		}
		printf("Sequence %d\n",t); 
		if(blow == 1)	printf("Fuse was blown.\n\n"); 
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max); 
	} 
    return 0;
}
