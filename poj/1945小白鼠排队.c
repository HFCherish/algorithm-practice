#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap(int *a,int*b)    //½»»» 
{
   int t;
   t=*a;  *a = *b;  *b = *a;     
}

void FastSort(int*p,int n,int*a) //°´ÉıĞò¿ìÅÅ 
{
    int s,t,i,j,flag;
    s=0;  t=n-1;
    if(t<=s+1)
    {
        if(t==s+1 && p[t]<p[s])
        {
             swap(&p[t],&p[s]);        
             swap(&a[t],&a[s]);
        }
        return;
    }     
    i=s+1;  j=t;
    flag=p[s];
    do
    {
        while(p[i]<=flag && i<n) i++;
        while(p[j]>flag) j--;
        if(i<j)
        {
            swap(&p[i],&p[j]);
            swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&p[s],&p[j]);
    swap(&p[s],&p[j]);
    FastSort(p,j,a);   FastSort(p+j+1,n-j-1,a);
    return;
}


int main()
{
   int ncases;
   scanf("%d",&ncases);
   int weight[ncases],a[ncases];
   char color[ncases][11];
   int i;
   for(i=0;i<ncases;i++)  a[i]=i;
   for(i=0;i<ncases;i++)
   {
       scanf("%d",&weight[i]);  
       getchar();
       scanf("%s",color[i]);                            
   }
   FastSort(weight,ncases,a);
   for(i=0;i<ncases;i++)
       {printf("%s\n",color[a[i]]); printf("%d %d\n",a[i],weight[i]);} 
   system("pause");
   return 0;
}
