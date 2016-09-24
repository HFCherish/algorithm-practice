#include<stdio.h>
#include<string.h>

int main()
{
   int k;
   scanf("%d",&k);
   int a[3]; 
   memset(a,0,sizeof(a));
   int i,m;
   for(i=0;i<k;i++)
   {
       scanf("%d",&m);
       switch(m)
       {
          case 1:a[0]++;break;
          case 5: a[1]++;  break;
          case 10: a[2]++; break;
          default: break;         
       }                
   } 
   for(i=0;i<3;i++)   printf("%d\n",a[i]); 
   system("pause");
   return 0;
}
