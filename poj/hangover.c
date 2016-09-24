#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float c,sum[100];  int res[100];
    int i,count=0;
    for(i=0;i<100;i++)  {res[i]=0;  sum[i]=0.0;}
   
    scanf("%1.2f",&c);
    while(fabs(c-0.00)>1e-6) 
    {
        for(i=2;i<=(int)(2*c);i++)  
           sum[count]+=1/(double)i;
        for(;sum[count]+1/(double)i<c;i++);
        res[count]=i;
        count++;
        scanf("%1.2f",&c);
    }
    for(i=0;i<count;i++)   
       printf("%d cards(s)\n",res[i]); 
    system("pause");
    return 0;
}
