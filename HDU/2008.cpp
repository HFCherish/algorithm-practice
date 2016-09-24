#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	double a;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int x,y,z;
		x = y = z = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&a);
			if(a<0)	x++;
			else if(a>0) z++;
				else y++;	
		}	
		printf("%d %d %d\n",x,y,z); 
	} 
    system("pause");
    return 0;
}
