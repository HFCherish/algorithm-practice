#include <stdio.h>
#include <stdlib.h>

int main()
{
	int y,m,d;
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d/%d/%d",&y,&m,&d) != EOF)
	{
		int flag = 0;
		int sum = 0;
		if((y%4==0 && y%100!=0) || y%400==0)
			flag = 1;
		for(int i=0; i<m-1; i++)
			sum += a[i];
		sum += d;
		if(flag && m>2)	sum += 1;
		printf("%d\n",sum);	
	} 
    system("pause");
    return 0;
}
