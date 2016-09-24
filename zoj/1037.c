#include <stdio.h>
#include <math.h>

int main()
{
    int number,m,n,i;
    scanf("%d",&number);
    for(i=0; i<number; i++)
    {
             scanf("%d%d",&m,&n);
             int points = m * n;
             double min;
             if(points % 2 == 0)
                       min = points;
             else min = points - 1 + sqrt(2);
             printf("Scenario #%d:\n%0.2f\n\n",i+1,min);
   }
   system("pause");
   return 0;                
}
