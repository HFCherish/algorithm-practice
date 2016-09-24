#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n;
	while(scanf("%d",&m) && m!=0)
	{
		scanf("%d",&n); 
		int a[m][n],b[m][n];
		int i,j,row=0,column=0,flag;
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)	
				scanf("%d",&a[i][j]);
		for(i=0; i<m; i++)
		{
			flag = 0;
			for(j=0; j<n; j++)	
			{
				scanf("%d",&b[i][j]);
				a[i][j] += b[i][j];
				if(a[i][j])	flag = 1;
			}
			if(flag==0)	row++;
		}	
		for(j=0; j<n; j++)
		{
			flag = 0;
			for(i=0; i<m; i++)
				if(a[i][j])	flag = 1;
			if(flag==0)	column++;
		}
		printf("%d\n",row + column); 
	} 
    return 0;
}
