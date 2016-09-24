#include<stdio.h>

int main()
{
    float c;
    while(scanf("%f",&c) && c>0.00)
    {
       float sum=0.00;
       int i;
       for(i=2;sum<c;sum+=(double)1/i,i++);
       printf("%d card(s)\n",i-2);                        
    } 
    getchar();
    getchar();
    return 0;
}
