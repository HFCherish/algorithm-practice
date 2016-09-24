#include<stdio.h>
#include<stdlib.h>
#define INF 1000

void Dijkstra(int n,int v,int prev[],int dist[],int **c)
{
     int i,s[n];
     for(i=0;i<n;i++)
     {
        dist[i] = c[v-1][i];
        s[i] = 0;
        if(dist[i] == INF)
           prev[i]=0;               
        else prev[i]=v;
     }  
     dist[v] = 0;
     s[v] = 1;
     for(i=1; i<n; i++)
     {
        int u=v,min = INF;
        int j; 
        for(j=0; j<n; j++)
        {
            if(!s[j] && dist[j]<min)
            {
                u=j;
                min = dist[j];         
            }         
            s[u] = 1;
            int k;
            for(k=0; k<n; k++)
            {
               if(!s[k] && c[u][k]<INF)
               {
                   int newdist = dist[u] + c[u][k];
                   if(newdist<dist[k])
                   {
                      dist[k] = newdist;
                      prev[k] = u+1;                   
                   }         
               }         
            }
        }         
     }
}

int main()
{
   int n,v;
   printf("Enter num of the point n & the source point v:\n"); 
   scanf("%d%d",&n,&v); 
   int dist[n],prev[n],c[n][n],i,j;
   printf("Enter the weight:\n"); 
   for(i=0; i<n; i++)
     for(j=0; j<n; j++)
      scanf("%d",&c[i][j]); 
   Dijkstra(n,v,dist,prev,c);
   system("pause");
   return 0;
}
