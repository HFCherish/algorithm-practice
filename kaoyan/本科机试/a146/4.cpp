#include <stdio.h>
#include <string.h>
#define N 100000

typedef struct{
	char name[30];
	int score;
}stu;

stu s[N];

void swap( stu *a, stu *b ) {
	stu t;
	strcpy( t.name,a->name );
	t.score = a->score;
	strcpy( a->name,b->name );
	a->score = b->score;
	strcpy( b->name,t.name );
	b->score = t.score;
}

int partition( int l,int h ) {
	int i,j,x;
	x = s[h].score;
	i=l-1;
	for( j=l; j<h; j++ ) {
		i++;
		if( s[j].score > x )
			swap( &s[i],&s[j] );
	}
	i++;
	swap( &s[i],&s[h] );
	return i;
}

void quickSort( int l,int h ) {
	if( l<h ) {
		int k = partition(l,h);
		quickSort( l,k-1 );
		quickSort( k+1,h );
	}
	return;
}

void print( int l,int h ) {
	int i;
	printf("ÐÕÃû  ³É¼¨\n");
	for( i=l; i<=h; i++ )
		printf("%s	%d\n",s[i].name,s[i].score);
}

int main() {
	freopen( "A.txt","r",stdin );
	freopen( "B.txt","w",stdout );
	int i=0;
	while( scanf("%s%d",s[i].name,&s[i].score)!=EOF )
		i++;
	quickSort( 0,i-1 );
	print( 0,i-1 );
	return 0;
}
