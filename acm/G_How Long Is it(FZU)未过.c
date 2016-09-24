#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926

int    Ri = 6378;

double geodist(double L1,double phi1,double L2,double phi2)

{
   double d,res;
   L1=fabs(L1); 
   phi1=fabs(phi1);
   L2=fabs(L2);
   phi2=fabs(phi2);
   d = ( Ri * acos(sin(phi1*(pi/180))*sin(phi2*(pi/180)) + cos(phi1*(pi/180))*cos(phi2*(pi/180))*cos((L1 - L2)*(pi/180))));
   res = round(d);
   return(res);
}

int main()
{
   int ncase,i;
   double a[4];
   scanf("%d",&ncase);
   for(i=0;i<ncase;i++)
   {
       int j;
       for(j=0;j<4;j++)  scanf("%lf",&a[i]); 
       double res;
       res=geodist(a[0],a[1],a[2],a[3]);
       printf("%.2lf",res);                   
   }
   system("pause");
   return 0;
}
