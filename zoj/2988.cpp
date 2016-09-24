#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		double a,m;
		char s[2];
		scanf("%lf",&a);
		getchar();
		scanf("%s",s);
		printf("%d ",i+1); 
		if(s[0] == 'k')	printf("%.4lf lb",a*2.2046);
		else if(s[0] == 'g') printf("%.4lf l",a*3.7854);
			else if(s[0]=='l' && s[1])	printf("%.4lf kg",a*0.4536);
				else printf("%.4lf g",a*0.2642);
		if(i<n-1) putchar('\n');	
	} 
	system("pause"); 
    return 0;
}
