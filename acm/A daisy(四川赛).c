#include<stdio.h>
#include<malloc.h>

int visited[250];

int FirstAdjVex(int **a,int v,int n)
{
    int i;
    for(i=0;i<n;i++)
       if(a[v][i]==1)  return i;
    return -1;
}

int NextAdjvex(int **a,int v,int w,int n)
{
    int i;
    for(i=w+1;i<n;i++)
       if(a[v][i]==1)  return i;
    return -1;    
}

void DFS(int **a,int v,int n)
{
        visited[v]=1;
        int i;
        for(i=FirstAdjVex(a,v,n);i>=0;i=NextAdjvex(a,v,i,n))
           if(!visited[i])  DFS(a,i,n);
}

int main()
{
    int n,**a,m,i,j,c1,c2;
    while(scanf("%d%d",&n,&m)==2)
    {
    a=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
       a[i]=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)  a[i][j]=0;  
    for(i=0;i<m;i++)
    {
       scanf("%d%d",&c1,&c2);
       a[c1-1][c2-1]=1;   
       a[c2-1][c1-1]=1;            
    } 
    
    for(i=0;i<n;i++)  visited[i]=0;    
    DFS(a,0,n);
    int flag=0;     
    
    for(i=1;i<n;i++)
      if(visited[i]==0)  { printf("%d\n",i+1);  flag=1;}
    if(flag==0) printf("0\n"); 
    }
    getchar();
    getchar(); 
    return 0;
}
