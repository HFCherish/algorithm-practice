#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int a[16],b[15],i,j=0;
        for(i=2;i<=16;i++)
        {
           int count=0,m=n;
           while(m!=0)
           {
               a[count++]=m%i;
               m=m/i;          
           }          
           int p=0,q=count-1; 
           for(;p<q;p++,q--)
           {
              if(a[p]!=a[q])   break;                 
           }  
           if(p>=q)
              b[j++]=i;     
        }  
        if(j>0)
        {
            printf("Number %d is palindrom in basis",n);
            for(i=0;i<j;i++)    printf(" %d",b[i]);     
        }
        else  printf("Number %d is not a palindrom",n);
        putchar('\n');                 
    } 
    system("pause"); 
    return 0;
}
