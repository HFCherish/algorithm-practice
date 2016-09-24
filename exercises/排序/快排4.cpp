#include <stdio.h>

void swap( int *a, int *b ) {
	int t;
	t=*a; *a=*b; *b=t;
}

int partition( int a[],int l, int h ) {
	int i,j,x;
	x = a[l];
	i = l;
	j = h;
	while( 1 ) {
		while( i<j && a[i]<=x )	i++;
		while( i<j && a[j]>=x )	j--;
		if( i<j )	swap( &a[i],&a[j] );
		else break;
	}
	if( a[i]>x ) i--;
	a[l] = a[i];
	a[i] = x;
	return i;	
}

void quickSort( int a[],int l, int h ) {
	if( l<h ) {
		int k = partition( a,l,h );
		quickSort( a,l,k-1 );
		quickSort( a,k+1,h );
	}
}

int main() {
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5],i;
	while( scanf("%d",&a[0]) != EOF ) {
		for( i=1; i<5; i++ )	scanf("%d",&a[i]);
		printf("Ô­À´£º"); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n");
		quickSort( a,0,4 );
		printf("ÅÅÐò£º"); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n\n"); 
	}
    return 0;
}
