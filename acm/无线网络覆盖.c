#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int main()
{
   int T,*l,*d,*r,*result;
   while(scanf("%d",&T)!=EOF)
   {
      if(T>=1 && T<=500)
      {
        l=(int*)malloc(sizeof(int)*T);
        r=(int*)malloc(sizeof(int)*T);
        d=(int*)malloc(sizeof(int)*T);
        result=(int*)malloc(sizeof(int)*T);
        int i;
        for(i=0;i<T;i++)
        {
          scanf("%d%d%d",&l[i],&d[i],&r[i]);
          if(l[i]>=1 && l[i]<=100000 && d[i]>=1 && d[i]<=50 && r[i]>=1 && r[i]<=200)
          {
              if(d[i]<2*r[i])
              {
                 double len;
                 len=sqrt(4*r[i]*r[i]-d[i]*d[i]);
                 if(len<1)  result[i]=0;
                 else             
                    result[i]=ceil((double)l[i]/len);                     
              }  
              else  result[i]=0;       
          }
        }
        for(i=0;i<T;i++)
          {
            if(result[i]==0)  printf("impossible\n");
            else printf("%d\n",result[i]);                
          }
      }                 
   }
   system("pause");
   return 0;
}
