#include<stdio.h>

int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
       struct 
       {
          int hour;
          int minute;
          int second;       
       }time[n];
       for(i=0;i<n;i++)
          scanf("%d%d%d",&time[i].hour,&time[i].minute,&time[i].second);
       int j,t,c[n];
       for(i=0;i<n;i++)  c[i]=i;
       for(i=0;i<n-1;i++)
       {
          for(j=1;j<n-i;j++)
            if(time[c[j-1]].second>time[c[j]].second) 
         {int p;
          p=c[j-1];
          c[j-1]=c[j];
          c[j]=p; }
       }
       for(i=0;i<n-1;i++)
       {
          for(j=1;j<n-i;j++)
            if(time[c[j-1]].minute>time[c[j]].minute) 
          {int p;
          p=c[j-1];
          c[j-1]=c[j];
          c[j]=p; } 
       }
       for(i=0;i<n-1;i++)
       {
          for(j=1;j<n-i;j++)
            if(time[c[j-1]].hour>time[c[j]].hour) 
          {int p;
          p=c[j-1];
          c[j-1]=c[j];
          c[j]=p; } 
       }  
       for(i=0;i<n;i++)
         printf("%d %d %d\n",time[c[i]].hour,time[c[i]].minute,time[c[i]].second);                        
    } 
    getchar();
    getchar();
    return 0;
}
