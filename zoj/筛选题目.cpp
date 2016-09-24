#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#define BN	40

using namespace std;

int main()
{
	freopen("problems1.txt","w",stdout); 
	FILE *fp1,*fp2;
	fp1 = fopen("a.txt","r");
	fp2 = fopen("b.txt","r"); 
	int t=0,i,j;
	char m[100];
	int a[100]={0},b[BN],c[100];
	printf("aÎª£º\n");
	while(fgets(m,100,fp1))
	{
		if(isdigit(m[0])) 
		{
			int p=1000;
			for(i=0; i<4; i++)
			{
				a[t] += (m[i]-'0')	* p;
				p /= 10;
			}
			t++;
		}	
	}
	for(i=0; i<t; i++)
		printf("%d ",a[i]); 
	printf("\nbÎª£º\n"); 
	for(i=0; i<BN; i++)
		{	fscanf(fp2,"%d",&b[i]); 	printf("%d ",b[i]); } 
	sort(a,a+t);
	int k=0;
	for(i=0,j=0; i<t; )
	{
		if(a[i] == b[j])
		{
			i++;	j++;	
		}	
		else if(a[i] < b[j])
		{
			c[k++] = a[i];
			i++;	
		}
			else	j++;
	}
	printf("\ncÎª£º\n"); 
	for(i=0; i<k; i++)
		printf("%d ",c[i]); 
    return 0;
}
