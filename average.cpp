#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
	int score[N];
	double a[N],b[N];
	freopen( "in1-pz.txt","r",stdin);
	freopen( "out.txt","w",stdout );
	
	int i=0;
	double sum = 0.0,credit = 0.0;
	while( scanf("%lf%d%lf",&a[i],&score[i],&b[i]) != EOF ) {
		sum += b[i] * score[i];
		credit += a[i];
		i++;
	}
	printf("%lf\n",sum/credit*0.85);
	return 0;
}
