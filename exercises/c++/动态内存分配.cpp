#include<iostream>
#include<iomanip>
using namespace std;
void display(int [],int);
void swap(int**,int**);
int main()
{
   const int size1=5;
   const int size2=7;
   int *a=new int [size1];
   int *b=new int [size2];
   for(int i=0;i<size1;i++)  a[i]=i;
   for(int i=0;i<size2;i++)  b[i]=2*i;
   cout<<"交换前a为："<<endl;
   display(a,size1);
   cout<<endl<<"b为："<<endl;
   display(b,size2);
   swap(&a,&b);
   cout<<"交换后a为："<<endl;
   display(a,size2);
   cout<<endl<<"b为："<<endl;
   display(b,size1);
   cin.get();
   return 0;    
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
      cout<<setw(5)<<a[i]<<" ";
    cout<<endl;   
} 
void swap(int** a,int** b)
{
    int* t;
    t=*a;
    *a=*b;
    *b=t;     
}










