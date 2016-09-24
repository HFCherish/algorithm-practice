#include <stdio.h>

/*int main() {
	int a[5],b[6];
	int i,j;
	for( i=0; i<5; i++ )	scanf("%d",&a[i] );
	for( j=0; j<6; j++ )	scanf("%d",&b[j] );
	i = -1;
	j = 0;
	int flag = 0;
	while( i<5 && j<6 ) {
		while( i<5 && a[++i]<b[j] );
		if( a[i] == b[j] ) {
			flag = 1;
			break;
		}
		while( j<6 && a[i]>b[++j] );
		if( a[i] == b[j] ) {
			flag = 1;
			break;
		}
	}
	if( flag )	printf("yes!\n");
	else printf("no!\n");
	return 0;
}*/

int main() {
	int a[5],b[6];
	int i,j;
	for( i=0; i<5; i++ )	scanf("%d",&a[i] );
	for( j=0; j<6; j++ )	scanf("%d",&b[j] );
	i = j = 0;
	while( i<5 && j<6 ) {
		if( a[i]==b[j] )	break;
		else if( a[i]<b[j] )	i++;
			 else	j++;
	}
	if( a[i] == b[j] )	printf("yes\n");
	else printf("no\n");
	return 0;
}