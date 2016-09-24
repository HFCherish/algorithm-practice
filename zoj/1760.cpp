#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
   int a[16];
   while(scanf("%d",&a[0]) && a[0]!=-1)
   {
        int count = 0;
        while(scanf("%d",&a[++count]) && a[count]);
        sort(a,a+count);
        int i,num = 0;
        for(i=0; i<count-1; i++)
        {
            if(a[i]*2 > a[count-1])  break;
            int j;
            for(j=1; j<count; j++)        
            {
                 if(a[j] == 2*a[i]) 
                 {
                     num++;
                     break;        
                 }        
            }
        }
        printf("%d\n",num); 
   } 
   system("pause");
   return 0;
}
