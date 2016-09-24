#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,a,b;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d",&a,&b);
		int res = a*b;
		printf("Scenario #%d:\n%.2f\n\n",i+1,res%2==0?res:(res-1+sqrt(2)));	
	} 
    system("pause");
    return 0;
}
