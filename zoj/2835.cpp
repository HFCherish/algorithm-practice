#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		int a[n][n],b[1001]={0};
		int i,j,sum;
		int m,flag;
		flag = 1;	//��ʶ��� 
		for(i=0; i<n; i++)
		{
			sum = 0;
			for(j=0; j<n; j++)
			{
				scanf("%d",&a[i][j]);
				if(flag == 0)	continue;
				else
				{
						int t = a[i][j];
						if(b[t]) flag = 0;	//�ظ����� 
						else
						{
							sum += t;
							b[t] = 1;
						}
				}
			}
			if(flag == 0) 	continue;
			if(i==0)	m = sum;
			else if(sum != m)	flag = 0;	//�кͲ��� 
		}
		if(flag)
		{
			for(i=0; i<n; i++)
			{
				sum = 0;
				for(j=0; j<n; j++)
					sum += a[j][i];
				if(sum != m)	//�кͲ��� 
				{
					flag = 0;
					break;	
				}	
			}
			if(flag)
			{
				int sum2;
				sum = sum2 = 0;
				for(i=0; i<n; i++)
				{
					sum += a[i][i];
					sum2 += a[i][n-1-i];	
				}	
				if(sum!=m || sum2!=m)	flag = 0;	//�Խ��ߺͲ��� 
			}	
		}
		if(flag)	printf("Yes\n");
		else	printf("No\n");	
	} 
    return 0;
}
