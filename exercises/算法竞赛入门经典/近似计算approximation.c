#include <stdio.h>
#include <math.h>

int main()
{
    double pi_4 = 0.0;
    int i;
    double m;
    for(i=1,m=1.0/i; fabs(m)>10e-7;)
      {
                      pi_4 += m;
                      i++;
                      m = pow(-1,i-1)/i;                  
      } 
    printf("%lf\n",pi_4); 

    system("pause");
    return 0;
}
