#include <stdio.h>
#include <math.h>

int main()
{
      int b,n;
      double a;
      while(scanf("%d%d",&b,&n) && b)
      {
           int low,high,lowx,highx;
           a = pow(10,log10(b)/n);
           low = (int)a;
           high = low + 1;
           lowx = b - pow(low,n);
           highx = pow(high,n) - b;           
           printf("%d\n",lowx<highx?low:high);
      }
      system("pause");
      return 0;    
}
