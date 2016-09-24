#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[50];
	while( scanf("%d",&a[0]) && a[0]!=0 )
	{
		int n;	
		for( n=1; scanf("%d",&a[n]) && a[n]!=0; n++ );
		int st=0,i,u,d,un,dn,eq;
		u = d = eq = un = dn = 0;
		for( i=0; i<n-1; i++ )
		{ 
			if( st==0 )	//表初态
			{
				if( a[i+1]>a[i] )
				{
					un++;
					u++;
					st = 1;	
				}	
				else if( a[i+1]<a[i] )
				{
					dn++;
					d++;
					st = 2;	
				}
				else
				{
					eq++;
					st = 3;	
				}
			} 
			else if( st==1 )	//表up态 
			{
				if( a[i+1]>=a[i] ) u++;
				else if( a[i+1]<a[i] )
				{
					d++;
					dn++;
					st = 2;	
				}
			}
			else if( st==2 )	//表down态  
			{
				if( a[i+1]<=a[i] ) d++;
				else if( a[i+1]>a[i] )
				{
					u++;
					un++;
					st = 1;	
				}	
			}
			else	//表相等态
			{
				if( a[i+1]<a[i] )
				{
					dn++;
					d += eq+1;
					st = 2;	
					eq = 0;
				}	
				else if( a[i+1]>a[i] )
				{
					u += eq+1;
					un++;
					st = 1;	
					eq = 0;
				}
				else eq++;
			}	
		}
		if( un==0 ) un = 1;
		if( dn==0 ) dn = 1;
		printf("Nr values = %d:  %.6lf %.6lf\n",n,u/(double)un,d/(double)dn); 
	} 
    return 0;
}
