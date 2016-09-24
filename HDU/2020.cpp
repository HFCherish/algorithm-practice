#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int cmp(const int&a,const int&b)
{
	if(a>b)	return 1;
	return 0;	
}

int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		int a[n],i,c[n],j=0;
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i] < 0)
				c[j++] = a[i] = -a[i];
		}
		sort(a,a+n,cmp);
		sort(c,c+j,cmp);
		int t=0;	
		for(i=0; i<n-1; i++)
		{
			if(a[i] == c[t])	
				a[i] = -c[t++];
			printf("%d ",a[i]);
		}
		if(t<j)	a[i] = -c[t];
		printf("%d\n",a[i]);
	}
    return 0;
}
