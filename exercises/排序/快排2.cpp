#include <stdio.h>
#include <stdlib.h>

int partition( int a[], int l, int h ) {
	int i,j,x;
	x = a[l];
	i = l;
	j = h;
	while( i<j ) {
		while( i<j && a[j]>=x )	j--;
		if( i<j )	a[i] = a[j];
		while( i<j && a[i]<=x ) i++;
		if( i<j )	a[j] = a[i];
	}
	a[i] = x;
	return i;
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
