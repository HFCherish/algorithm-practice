#include <stdio.h>
#include <stdlib.h>

//Ҫ�������е�������ͬ 
void countSort( int a[],int b[],int n ) {	 
	int i,j,count;
	for( i=0; i<n; i++ ) {
		 count = 0;
		 for( j=0; j<n; j++ )
		 	if( a[i]>a[j] ) count++;	//Ѱ�ұȵ�i����¼С�����ĸ��� 
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
		printf("ԭ����"); 
		for( i=0; i<5; i++ )	printf("%d ",a[i]);
		printf("\n");
		printf("����"); 
		for( i=0; i<5; i++ )	printf("%d ",b[i]);
		printf("\n\n"); 
	}
    return 0;
}
