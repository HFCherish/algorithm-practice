#include<iostream>
using namespace std;
double f1(int);
double f2(int);
double twice(double (*)(int),int);
int main()
{
   int a=1,b=2;
   cout<<twice(f1,2)<<endl;
   cout<<twice(f2,2)<<endl;
   cin.get();
   return 0;    
} 
double f1(int n)
{
   return  n*n;   
}
double f2(int n)
{
   return n*n*n;       
}
double twice(double (*p)(int),int n)
{
    return 2*p(2);       
}


