#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[200],b[200];
    int c[201];
    int i,j,m,n;
    scanf("%s%s",a,b);
    for(i=0;a[i]!='\0';i++);
    for(j=0;b[j]!='\0';j++);  
    if(i<=j)
    {        
        for(m=0;m<j-i;m++)  c[m+1]=b[m]-'0';
        for(;m<j;m++)  c[m+1]=a[m-j+i]-'0'+b[m]-'0';                 
    }
    else
    {        
        for(m=0;m<i-j;m++)  c[m+1]=a[m]-'0';
        for(;m<i;m++)  c[m+1]=b[m-i+j]-'0'+a[m]-'0';                 
    }
    n=m;
    for(;m>0;m--)
    {
       c[m-1]+=c[m]/10;
       c[m]%=10;                  
    } 
    m=(c[0]==0)?1:0;
    for(;m<=n;m++)  printf("%d",c[m]);
    system("pause");
    return 0;
}
