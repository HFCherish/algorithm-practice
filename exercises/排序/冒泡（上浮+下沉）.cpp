#include <iostream>
using namespace std;

void swap( int*a,int*b ){
	//*a ^= *b ^= *a ^= *b;	�д� 
	int t;
	t=*a; *a=*b; *b=t;
} 

void BubbleSort2( int a[],int n ){
	int change,low,high,i;
	change = 1;
	low = 0;
	high = n-1;
	while( low<high && change ){
		change = 0;	//���豾��û�иı� 
		for( i=low; i<high; i++ ){	//�ϸ���������� 
			if( a[i]>a[i+1] ) {
				swap( &a[i],&a[i+1] );
				change = 1;
			}
		}
		high--;	//���Ĵ��Ŷ��� 
		for( i=high; i>low; i-- ){	//�³�������С�� 
			if( a[i]<a[i-1] ){
				swap( &a[i],&a[i-1] );
				change = 1;
			}
		}
		low++;	//���Ĵ��Ż��� 
	}
} 
				 


int main(){
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	int a[5];
	while( cin>>a[0] ){
		int i;
		cout << "ORI:" << endl;
		cout << a[0];
		for( i=1; i<5; i++ ){
			cin >> a[i];
			cout << ' ' << a[i];
		}	
		cout << endl;	
		BubbleSort2(a,5);
		cout << "SORT:" << endl;
		for( i=0; i<5; i++ )
			cout << a[i] << ' ';
		cout<<endl;
	}	
    return 0;
}
