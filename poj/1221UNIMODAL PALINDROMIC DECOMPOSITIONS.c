#include<stdio.h>

int Div_Num(int n,int m)  //求正整数n的划分数，其最大划分数不大于m 
{
        if(n<1 || m<1)   return 0;
        if (n==1 || m==1)  return 1;
        if(n<m)  return Div_Num(n,n);
        if(n==m)  return 1+Div_Num(n,m-1);
        return  Div_Num(n,m-1)+Div_Num(n-m,m);
}

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
         long long num=1ll;
         int i;
         if(n%2==0)
         {
            num += (long long)Div_Num(n/2,n/2);
            for(i=2;i<n;i+=2)                 
                  num += (long long)Div_Num((n-i)/2,i);                    
         }  
         else 
            for(i=1;i<n;i+=2)
                  num+=(long long)Div_Num((n-i)/2,i);
         printf("%d %lld\n",n,num);                    
    }    
    system("pause");
    return 0; 
} 
