#include <iostream>
using namespace std;

void swap( int *a, int *b ) {
	//*a ^= *b ^= *a ^= *b;	�д� 
	int t;
	t=*a; *a=*b; *b=t;
}

void insertSort( int *a,int n ) {
	int i,tp;
	for( i=1; i<n; i++ ) {
		tp = a[i];
		int j;
		for( j=i-1; j>=0; j-- ) {
			if( a[j]>tp ) a[j+1] = a[j];
			else 	break;
		}
		a[j+1] = tp;
	}
}

int main() {
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5];
	while( cin >> a[0] ) {
		int i;
		cout << "ԭ���У�" << a[0]; 
		for( i=1; i<5; i++ ) {
			cin >> a[i];
			cout << ' ' << a[i];
		}
		insertSort( a,5 );
		cout << endl << "�����";
		for( i=0; i<5; i++ ) 
			cout << a[i] << ' '; 
		cout << endl;
	}
	return 0;
}
