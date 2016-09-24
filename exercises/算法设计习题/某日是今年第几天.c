#include<stdio.h>

int f(int year,int month,int day)  //计算某年某月某日是当年的第几天 
{
     int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     if(year%4==0 && !(year%100==0 && year%400!=0))
       a[1]=29;
     int i,count=0;
     for(i=0;i<month-1;i++)   count+=a[i];
     return count+day;
}
