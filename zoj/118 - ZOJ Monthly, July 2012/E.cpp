#include <stdio.h>
#include <stdlib.h>

int t[101][101];
int v[101];

int find( int m, int k, int n ) {
	int i,tp[n],j=0,flag=1;
	if( m<0 )	return 0;
	if( m==0 )	return v[k];
	if( m>0 ) {
		for( i=1; i<=n; i++ )
			if( t[k][i] ) {
				int temp = t[k][i];
				t[k][i] = 0;
				t[i][k] = 0;
				tp[j++] = find( m-temp,i,n );
				flag = 0;
			}
		if( flag )	return v[k];
		int res=tp[0];
		for( i=1; i<j; i++ )	
			res = tp[i]>res?tp[i]:res;
		return res+v[k];		
	}
				
} 

int main(){
	int n;
	while( scanf("%d",&n) != EOF ) {
		for( int j=0; j<101; j++ )
			for( int k=0; k<101; k++ )
				t[j][k] = 0;
		int k,m,i,ti,tj;
		for( i=1; i<=n; i++ ) scanf("%d",&v[i]);
		for( i=1; i<n; i++ ) {
			scanf("%d%d",&ti,&tj);
			scanf("%d",&t[ti][tj]);
			t[tj][ti] = t[ti][tj];
		}
		scanf("%d%d",&k,&m);
		printf("%d\n",find(m/2,k,n));
	}
    return 0;
}
