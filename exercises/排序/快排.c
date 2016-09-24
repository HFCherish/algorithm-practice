#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b)    //交换 
{
   int t;
   t=*a;  *a = *b;  *b = t;     
}

void FastSort(int*p,int m,int n) //按升序快排 
{
    int s,t,i,j,flag;
    s=m;  t=n;
    if(t<=s+1)		//快排结束 
    {
        if(t==s+1 && p[t]<p[s])
             swap(&p[t],&p[s]);        
        return;
    }     
    i=s+1;  j=t;
    flag=p[s];	printf("%d## ",flag);
    do
    {
        while(p[i]<flag && i<j) i++;	//从左边开始找不小于flag的数的序号 
        while(p[j]>=flag && i<j) j--;		//从右边开始找小于flag的数的序号 
        if(i<j)
            swap(&p[i],&p[j]);
    }while(i<j);	//p[j]是最后一个小于flag的数 
    swap(&p[s],&p[j]);	
    FastSort(p,m,j-1);   FastSort(p,j+1,n);printf("$$$$\n");
}




int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
   int a[3],i;
   for(i=0;i<5;i++)
      scanf("%d",&a[i]);
   putchar('\n');
   FastSort(a,0,2);
   for(i=0;i<5;i++)
      printf("%d ",a[i]);
   return 0;    
}
