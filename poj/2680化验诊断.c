#include<stdio.h>
#include<malloc.h>

typedef struct
{
    char sex[10];
    double a[5];        
}*Data;

int main()
{
    int k,i;
    double lbound[5]={4.0,3.5},ubound[5]={10.0,5.5};
    lbound[4]=100;  ubound[4]=300;
    scanf("%d",&k);
    Data data;
    data=(Data)malloc(k*sizeof(Data));
    for(i=0;i<k;i++)
    {
       int count=0,j;
       scanf("%s",data[i].sex);
       if(data[i].sex[0]=='m')
       {
           lbound[2]=120;  lbound[3]=42;  ubound[2]=160;  ubound[3]=48;                       
       } 
       else  
       {
            lbound[2]=110;  lbound[3]=36;  ubound[2]=150;  ubound[3]=40;     
       }
       for(j=0;j<5;j++) 
       {
           scanf("%lf",&data[i].a[j]);
           double p=data[i].a[j]-lbound[j],q=data[i].a[j]-ubound[j];
           if(p<0 || q>0)
                 count++;
       }
       if(count==0)  printf("normal\n");
       else printf("%d\n",count);                
    } 
    getchar();
    getchar();
    return 0;
}
