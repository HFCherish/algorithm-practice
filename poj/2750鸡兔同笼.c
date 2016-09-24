#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct
{
   int min;
   int max;        
}*result;

int main()
{
    int n,*a,i;
    result b;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    b=(result)malloc(n*sizeof(result));
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);  
       if(a[i]%2) b[i].min=b[i].max=0;
       else
       {  
          b[i].min=(a[i]+3)/4;
          b[i].max=a[i]/2;
          if(b[i].min>b[i].max) b[i].min=b[i].max=0;  
       }
    } 
    for(i=0;i<n;i++)
      printf("%d %d\n",b[i].min,b[i].max); 
    system("pause");
    return 0;
}
