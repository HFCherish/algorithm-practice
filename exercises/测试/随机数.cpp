#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	freopen( "in.txt","w",stdout );
	int i;
	srand( (unsigned)time(NULL) );
	//printf("%d",RAND_MAX);
	for( i=0; i<RAND_MAX+1; i++ )
		printf("%d ",rand());
	//system("pause");
	return 0;
}
