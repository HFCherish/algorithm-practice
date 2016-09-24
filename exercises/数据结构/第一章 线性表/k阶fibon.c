#include <stdio.h>

int fibon(int k, int m)   //k½×fibonµÚm¸öÔªËØ 
{
    if(m < k)  return 0;
    if(m <= k + 1)  return 1;
    int f1, f2, f3;
    f1 = f2 =1;
    int i;
    for(i = 1; i < m-k; i++)
    {
       f3 = f1 + f2;
       f1 = f2;
       f2 = f3;     
    }    
    return f3;
}

int main()
{
    int k, m;
    scanf("%d %d",&k, &m); 
    printf("%d\n", fibon(k, m));
    system("pause");
    return 0;    
}
