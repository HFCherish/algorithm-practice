#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[200],b[200];
    unsigned int c[400]={0};
    int i,j;
    //for()
    scanf("%s%s",a,b);
    for(i=0;a[i]!='\0';i++)
      for(j=0;b[j]!='\0';j++)
         c[i+j]+=(a[i]-'0')*(b[j]-'0');
    int n,m;
    n=m=i+j-2;
    for(;m>0;m--)
    {
       c[m-1]+=c[m]/10;
       c[m]%=10;             
    }
    for(m=0;m<=n;m++)
       printf("%u",c[m]);
    system("pause");
    return 0;
}
