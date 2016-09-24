#include<stdio.h>
#include<malloc.h>

typedef struct
{
   int i;
   int j;        
}*Coard;

int main()
{
    int N,**a,i,j,m=0,n=0;
    int area=0,girth=0;
    Coard TumerCoard;
    scanf("%d",&N);
    a=(int**)malloc(N*sizeof(int*));
    for(i=0;i<N;i++)  
      a[i]=(int*)malloc(N*sizeof(int));
    TumerCoard=(Coard)malloc(N*sizeof(Coard));
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
      {
         scanf("%d",&a[i][j]);
         if(a[i][j]<=50)
         {
            area++;
            TumerCoard[m].i=i;
            TumerCoard[m].j=j;
            m++;
         }                
      } 
    for(n=0;n<m;n++)
    {
        if(TumerCoard[n].i==0 || TumerCoard[n].j==0 || TumerCoard[n].i==N-1 || TumerCoard[n].j==N-1)
            girth++;
        else if(a[TumerCoard[n].i][TumerCoard[n].j-1]>50)  girth++;
             else if(a[TumerCoard[n].i][TumerCoard[n].j+1]>50) girth++;
                  else if(a[TumerCoard[n].i-1][TumerCoard[n].j]>50)  girth++;
                       else if(a[TumerCoard[n].i+1][TumerCoard[n].j]>50) girth++;                
    }
    printf("%d %d\n",area,girth); 
    return 0;
}
