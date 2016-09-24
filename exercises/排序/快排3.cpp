#include <stdio.h>
#include <stdlib.h>

void swap( int *a, int *b ) {
	int t;
	t=*a; *a=*b; *b=t;
}

int partition( int a[], int l, int h ) {
	int i,j,x;
	i = l;
	j = h+1;
	x = a[l];
	while( 1 ) {
		while( a[++i]<x && i<h );
		while( a[--j]>x );
		if( i>=j )	break;
		swap( &a[i],&a[j] );
	}
	a[l] = a[j];
	a[j] = x;
	return j;
}

void quickSort( int a[], int l, int h ) {
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
