#include<iostream>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
     if(n<100)
     {
       sum=0;
       for(int i=1; i<=n; i++)
          if(!(i/10==7 || i%7==0 || i%10==7)) sum+=i*i;        
       cout<<sum<<endl;
     }
     return 0;
} 
