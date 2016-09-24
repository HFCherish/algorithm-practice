#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,t;
	double e = 2.5;
	t = 2;
	printf("n e\n- -----------\n");
	printf("0 1\n1 2\n2 2.5\n"); 
	for(n=3; n<10; n++)
	{
		t*=n;	
		e += 1.0/t;
		printf("%d %.9lf\n",n,e); 
	}
	system("pause"); 
    return 0;
}
