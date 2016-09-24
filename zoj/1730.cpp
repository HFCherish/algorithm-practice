#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
   *a^=*b^=*a^=*b;     
}

int Procedure_BubbleSort(int*a,int n)
{
     int i,j,LastExchangeIndex,res=0;
     i=n;
     while(i>0)
     {
        LastExchangeIndex=0;
        for(j=1;j<i;j++)
        {
            if(a[j]>a[j-1])
            {
                swap(&a[j],&a[j-1]);
                res++;
                LastExchangeIndex=j;               
            }                
        }          
        i=LastExchangeIndex;
     }  
	 return res;   
}

int main()
{
	int n;
	scanf("%d",&n);
	for( int i=0; i<n; i++ )
	{
		int m;
		scanf("%d",&m);	
		int a[m-2];
		for( int j=0; j<m-2; j++ )	a[j] = j;
		printf("%d\n",Procedure_BubbleSort(a,m-2)+1);
	}	
	return 0;
}
