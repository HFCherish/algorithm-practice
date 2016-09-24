#include<stdio.h>


int main()
{
    int days,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d",&days) && days!=-1)
    {
       int iyear,count,jmonth,m,p,dday;
       iyear=days/365;  count=365*iyear;
       days++;
       for(p=2000,m=days-count; p<2000+iyear && m>0; p+=2,m=days-count)
          if(p%4==0 && !(p%100==0 && p%400!=0))  count+=1;       //计算要求年份之前有多少天，m表示 
       if(m>0)  //要求年份为2000+iyear，m表示要求日期是当年第几天 
       {
          int t;
          if((2000+iyear)%4==0 && !((2000+iyear)%100==0 && (2000+iyear)%400!=0))  a[1]=29;
          for(jmonth=0,t=a[jmonth];m>t;t+=a[++jmonth]);         
          if(m<t)
          {
            dday=m-t+a[jmonth];
            jmonth--;
          }
          else  dday=a[jmonth];       
       } 
       else if(m=0)
            {
               iyear=p-2000-2; 
               jmonth=11; dday=31;
               printf("%d %d %d\n",iyear,jmonth,dday); 
            }  
       char wday[7][10]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};                            
       printf("%4d-%02d-%02d %s\n",2000+iyear-1,jmonth+1,dday,wday[days%7]);  
    } 
    getchar();
    getchar();
    return 0;
}
