#include<stdio.h>

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
       if(a%4==0)
       {
          if(a%100==0 && a%400!=0)  printf("N\n");
          else  if(a%3200==0)  printf("N\n");
                else  printf("Y\n");          
       }                       
       else  printf("N\n"); 
    } 
    getchar();
    getchar();
    return 0;
}
