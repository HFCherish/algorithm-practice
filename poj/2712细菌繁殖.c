#include<stdio.h>


int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       int m[2],d[2],days=0,k;
       long int num;
       scanf("%d%d%ld%d%d)",&m[0],&d[0],&num,&m[1],&d[1]);
       for(k=m[0];k<m[1];k++)
           switch(k)
           {
              case 1:  days+=31;break;
              case 2:  days+=28;break;
              case 3:  days+=31;break;
              case 4:  days+=30;break;
              case 5:  days+=31;break;
              case 6:  days+=30;break;
              case 7:  days+=31;break;
              case 8:  days+=31;break;
              case 9:  days+=30;break;
              case 10: days+=31;break;
              case 11: days+=30;break;
              case 12: days+=31;break;
              defaule: break;         
           }               
       days=days-d[0]+d[1];
       for(k=0;k<days;k++)
          num*=2;
       printf("%ld\n",num); 
    } 
    getchar();
    getchar();
    return 0;
}
