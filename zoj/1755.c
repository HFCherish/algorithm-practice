#include <stdio.h>

int main()
{
   int n;
   while(scanf("%d",&n) && n!=-1)
   {
       int i,a,b,c,size[n];
       char name[n][9];
       for(i=0; i<n; i++)
       {
            scanf("%d%d%d",&a,&b,&c);
            getchar();
            scanf("%s",name[i]);
            size[i] = a * b * c; 
       }                     
       int maxsize,minsize,ma,mi;
       maxsize = minsize = size[0];
       ma = mi = 0;
       for(i=1; i<n; i++)
       {
            if(size[i] > maxsize)
            {
                 maxsize = size[i];
                 ma = i;           
            } 
            else if(size[i] < minsize)
            {
                 minsize = size[i];
                 mi = i;           
            }        
       }
       printf("%s took clay from %s.\n",name[ma],name[mi]); 
   } 
   system("pause");
   return 0;
}
