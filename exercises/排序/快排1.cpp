#include <stdio.h>
#include <stdlib.h>

void swap( int*a,int*b ){
	//*a ^= *b ^= *a ^= *b;	有错 
	int t;
	t=*a; *a=*b; *b=t;
} 

//a[p..i]中的数都小于界值，a[i+1..j-1]中的数都大于界值 
int partition( int a[], int l, int h ) {
	int x = a[h];
	int i,j;
	i = l-1;
	for( j=l; j<h; j++ )
		if( a[j]<=x ) {
			i++;
			swap( &a[i],&a[j] );
		}
	swap( &a[i+1],&a[h] );
	return i+1;
}

void quickSort( int a[],int l, int h ) {
	if( l<h ) {
		int i = partition( a,l,h );
		quickSort( a,l,i-1 );
		quickSort( a,i+1,h );
	}
}


int main() {
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5],i;
	while( scanf("%d",&a[0]) != EOF ) {
		for( i=1; i<5; i++ )	scanf("%d",&a[i]);
		printf("原来："); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n");	
		quickSort( a,0,4 );
		printf("排序："); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n\n"); 
	}
    return 0;
} 
