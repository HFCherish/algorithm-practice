#include<stdio.h>
#define PI 3.1415926

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
       float x,y;
       int j=1; 
       scanf("%f%f",&x,&y); 
       for(;x*x+y*y>(100*j/PI);j++);
       printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
    } 
    printf("END OF OUTPUT.");
    getchar();
    getchar();
    return 0;
}
