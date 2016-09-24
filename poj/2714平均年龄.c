#include<stdio.h>

int main()
{
    int n,age,i,sum=0;
    double average;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&age);
       sum+=age;
    } 
    average=(double)sum/n;
    printf("%.2f\n",average); 
    return 0;
}
