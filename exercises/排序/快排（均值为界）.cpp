#include <iostream>
using namespace std;
//#include <stdio.h>
//#include <stdlib.h> 

void swap( int*a,int*b ){
	//*a ^= *b ^= *a ^= *b;	有错 
	int t;
	t=*a; *a=*b; *b=t;
} 

//以平均值作为轴进行快排 
int partition( int a[], int l, int h ) {
	int i,j,avg=0;
	for( i=l; i<=h; i++ )	avg += a[i];
	avg /= (h-l+1);	
	i = l-1;
	j = h+1;	
	while( i<j ) {
		while( a[++i]<avg && i<h );
		while( a[--j]>avg && j>l );
		if( i<j )	swap( &a[i],&a[j] );
	}
	return j;
	
}

void quickSort( int a[],int l,int h ) {
	if( l<h ) { 
		int i = partition( a,l,h );	
		quickSort( a,l,i );
		quickSort( a,i+1,h );
	}
}
/*	
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
}*/
int a[40000];
int main() {
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int i=0;
	while( cin >> a[i++] );
	quickSort( a,0,i-1 );
	cout << "排序："; 
	for( int j=0; j<i; j++ )	cout << a[j] << ' ';
	cout << endl <<endl; 
	
    return 0;
} 
