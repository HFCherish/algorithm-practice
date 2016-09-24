#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[6];
	while( 1 )
	{
		int i;
		for( i=0; i<6; i++ )
			scanf("%d",&a[i]);
		if( a[0]+a[1] == 0 )	break;
		int m,n;
		m = a[0]+a[1];
		n = (a[0]+a[2]+a[4]) - (a[1]+a[3]+a[5]);
		int win,loss;
		win = (m-n)/2;
		loss = n+win;
		printf("Anna's won-loss record is %d-%d.\n",win,loss);	
	}	
    return 0;
}
