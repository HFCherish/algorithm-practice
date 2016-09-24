#include<iostream>
using namespace std;

int main(){
	freopen("out2.txt","w",stdout); 
 int num[201],i;
 for(i=2;i<=200;++i)
  num[i]=i*i*i;
 for(i=6;i<=200;++i){
  for(int j=2;j<i;++j){
   for(int k=j;k<i;++k){
    for(int l=k;l<i;++l){
     if(num[i]==num[j]+num[k]+num[l])
      cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
    }
   }
  }
 }
 system("pause"); 
}
