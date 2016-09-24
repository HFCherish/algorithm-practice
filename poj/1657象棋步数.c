#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

typedef struct
{
   char h[3];
   char t[3];        
}*site;

typedef struct 
{
   int W;
   int H;
   int J;
   int X;      
}*Num;
int main()
{
    int t,i;
    scanf("%d",&t);
    site s;
    Num num;
    s=(site)malloc(t*sizeof(site));
    num=(Num)malloc(t*sizeof(Num));
    for(i=0;i<t;i++)
    {
        scanf("%s%s",s[i].h,s[i].t);
        int a,b;
        a=abs(s[i].t[0]-s[i].h[0]);
        b=abs(s[i].t[1]-s[i].h[1]);
        if(a==0 && b==0)  num[i].W=num[i].H=num[i].J=num[i].X=0; 
        else
        {
        num[i].W=(a>=b)?a:b;  //求王的最小步数
        if(a==0 || b==0 || a==b) num[i].H=1;
        else num[i].H=2;    //求后的最小步数 
        if(a==0 || b==0)  num[i].J=1;
        else num[i].J=2;     //求车的最小步数 
        if(a==b) num[i].X=1;
        else if((a+b)%2==0) num[i].X=2;
             else num[i].X=-1;    // 求象的最小步数   
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    }
    for(i=0;i<t;i++)
    {
       printf("%d %d %d ",num[i].W,num[i]. H,num[i].J);
       if(num[i].X==-1)  printf("Inf\n");
       else printf("%d\n",num[i].X); 
    } 
    getchar();
    getchar();     
    return 0;
}
