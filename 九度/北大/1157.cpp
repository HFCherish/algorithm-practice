#include <stdio.h>
#include <stdlib.h>

void swap( int*a, int*b ){
	a ^= b ^= a ^= b;
} 

//¿ìÅÅ,ÉıĞò 
int partion( int* a,int p,int q ) {
	if( q == p ) return p;
	if( q == p+1 ) {
		if( a[q] < a[p] ) swap( &a[p],&a[q] );
		return p;
	}
	int i,j,flag = a[p];
	i = p+1;
	j = q;
	while( i<j ) {
		while( a[i]<flag && i<j )	i++;
		while( a[j]>=flag && i<j )	j--;
		if( i<j ) {
			swap( &a[i],&a[j] );
			i++;
			j--;
		}
	}
		
		

int main()
{

    return 0;
}
