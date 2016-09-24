#include<stdio.h>
#include<malloc.h>

typedef struct
{
   int h;
   int t;        
}*range;

int main()
{
    int L,M;
    int i,j,*a,count;
    range r;
    scanf("%d%d",&L,&M);
    count=L+1;
    a=(int*)malloc((L+1)*sizeof(int));
    for(i=0;i<L+1;i++)  a[i]=0; 
    r=(range)malloc(M*sizeof(range));
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&r[i].h,&r[i].t);
        for(j=r[i].h;j<=r[i].t;j++)
           if(a[j]==0){  a[j]=1;  count--;}                                     
    }
    printf("%d",count);
    return 0;
}
