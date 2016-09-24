#include <stdio.h>

//#define LOCAL
#define INF 10000000    

/*int main()
{
   #ifdef LOCAL
          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
   #endif
   int sum = 0, max = -INF, min = INF;
   int n,count = 0;
   while(scanf("%d",&n) == 1)
   {
        sum += n;
        count++;
        if(n>max) max = n;
        else if(n<min)  min = n;     
   } 
   printf("%d %d %.3lf",min,max,sum/(double)count); 
   system("pause");
   return 0;
}*/

int main()
{
     FILE *fin,*fout;
     fin = fopen("input.txt","r");
     fout = fopen("output.txt","w");
     int sum = 0, max = -INF, min = INF;
   int n,count = 0;
   while(fscanf(fin,"%d",&n) == 1)
   {
        sum += n;
        count++;
        if(n>max) max = n;
        else if(n<min)  min = n;     
   } 
   fprintf(fout,"%d %d %.3lf\n",min,max,sum/(double)count); 
   fclose(fin);
   fclose(fout);
   system("pause");
   return 0;    
}



 
