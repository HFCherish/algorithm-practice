#include<stdio.h>
#include<malloc.h>
 

int main()
{
    int n,pixel,length=0,girth=0;
    int i,j,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
      {
          scanf("%d",&pixel);
          switch(flag)
          {
             case 0: if(pixel==0) {  flag=1;  girth++;   length++;}
                     break;
             case 1: if(pixel==255)  flag=2;
                     else {   girth++;  length++;}
                     break;
             case 2: if(pixel==0)  girth++;  break;
             default: break;           
          }                          
      } 
    printf("%d\n",(length-2)*(girth/2-length)); 
    return 0;
}
