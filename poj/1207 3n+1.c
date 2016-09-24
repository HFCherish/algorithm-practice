#include <stdio.h>

int cycleLength(int i)
{
    int len = 1;
    while(i != 1)
    {            
            if(i % 2 == 0) i /= 2;
            else i = i*3 + 1; 
            len++;           
    }
    return len;
}

int main()
{
   int i,j;
   while((scanf("%d%d",&i,&j)) != EOF)
   {
         int min = i,max =j;
         if(i>j)
         {
                min = j;
                max = i;
         }
         int k,l,m = 0;
         for(k=min; k<=max; k++)
         {
                l = cycleLength(k);
                m = (m < l)?l : m;
         }
         printf("%d %d %d\n",i,j,m);
   } 
   system("pause");
   return 0;
}
