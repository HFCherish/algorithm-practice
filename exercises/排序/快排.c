#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b)    //���� 
{
   int t;
   t=*a;  *a = *b;  *b = t;     
}

void FastSort(int*p,int m,int n) //��������� 
{
    int s,t,i,j,flag;
    s=m;  t=n;
    if(t<=s+1)		//���Ž��� 
    {
        if(t==s+1 && p[t]<p[s])
             swap(&p[t],&p[s]);        
        return;
    }     
    i=s+1;  j=t;
    flag=p[s];	printf("%d## ",flag);
    do
    {
        while(p[i]<flag && i<j) i++;	//����߿�ʼ�Ҳ�С��flag��������� 
        while(p[j]>=flag && i<j) j--;		//���ұ߿�ʼ��С��flag��������� 
        if(i<j)
            swap(&p[i],&p[j]);
    }while(i<j);	//p[j]�����һ��С��flag���� 
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
