#include<stdio.h>

void FastSort(int*p,int n) //°´ÉıĞò¿ìÅÅ 
{
    int s,t,i,j,temp,flag;
    s=0;  t=n-1;
    if(t<=s+1)
    {
        if(t==s+1 && p[t]<p[s])
        {
            temp=p[t];  p[t]=p[s]; p[s]= temp;
        }          
        return;
    }     
    i=s+1;  j=t;
    flag=p[s];
    do
    {
        while(p[i]<flag) i++;
        while(p[j]>flag) j--;
        if(i<j)
        {
           temp=p[i];  p[i]=p[j];  p[j]=temp;       
        }
    }while(i<j);
    p[s]=p[j];   p[j]=flag;
    FastSort(p,j);   FastSort(p+j+1,n-j-1);
    return;
}

int main()
{
    int a[16],b[15];
    while(scanf("%d",&a[0])==1 && a[0]!=-1)
    {
        int i=0,j,count=0;
        for(j=0;j<15;j++)  b[j]=0;
        j=0;     
        while(a[i]!=0)
        {
           if(a[i]%2==0)  b[j++]=a[i];
           scanf("%d",&a[++i]);             
        }
        FastSort(a,i);
        int m,n;
        for(m=0;m<i-1;m++)
          for(n=0;n<j;n++)
              if(b[n]==2*a[m])
              {
                count++;  break;                
              } 
        printf("%d\n",count);                      
    } 
    return 0;
}
