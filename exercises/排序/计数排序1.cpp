#include <stdio.h>
#include <stdlib.h>

//要求数组中的数不相同 
void countSort( int a[],int b[],int n ) {	 
	int i,j,count;
	for( i=0; i<n; i++ ) {
		 count = 0;
		 for( j=0; j<n; j++ )
		 	if( a[i]>a[j] ) count++;	//寻找比第i个记录小的数的个数 
		 b[count] = a[i];
	}
}

int main(){
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5],b[5];
	while( scanf("%d",&a[0]) != EOF ) {
		int i;
		for( i=1; i<5; i++ )	scanf("%d",&a[i]);
		countSort( a,b,5 );
		printf("原来："); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n");
		printf("排序："); 
		for( i=0; i<5; i++ )	printf("%d ",b[i]);
		printf("\n\n"); 
	}
    return 0;
}
