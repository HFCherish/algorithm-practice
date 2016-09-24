#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void countSort2( int *a, int *b, int n ) {
	int i,j,c[n];
	memset( c,0,sizeof(c) );
	for( i=0; i<n; i++ ) {
		for( j=i+1; j<n; j++ ) {
			if( a[i]>a[j] )	c[i]++;
			else	c[j]++;
		}
		b[c[i]] = a[i];
	}
}

int main() {
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5],b[5],i;
	while( scanf("%d",&a[0]) != EOF ) {
		for( i=1; i<5; i++ )	scanf("%d",&a[i]);
		countSort2( a,b,5 );
		printf("Ô­À´£º"); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n");
		printf("ÅÅÐò£º"); 
		for( i=0; i<5; i++ )	printf("%d ",b[i]);
		printf("\n\n"); 
	}
    return 0;
} 
