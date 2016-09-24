#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000

void print( int*a, int n ) {
	int i;
	for( i=0; i<n; i++ )
		printf("%d ",a[i]);
	printf("\n");
}

int main() {
	int n;
	scanf("%d",&n);
	srand((int)time(0));
	char M[N];
	int a[N],b[N],c[N],d[N];
	int i;
	scanf("%s",M);
	for( i=0; i<n; i++ ){
		a[i] = M[i]-'0';
		b[i] = rand()%2;
		c[i] = a[i]^b[i];
		d[i] = b[i]^c[i];
	}
	printf("明文M：\n");
	print( a,n );
	printf("密钥K：\n");
	print( b,n );
	printf("密文C：\n");
	print( c,n );
	printf("密明文M1：\n");
	print( d,n );
	return 0;
}