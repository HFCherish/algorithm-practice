#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include <ctype.h>

void Change(char*a)
{
     int i,count=0;
     char b[10];
     for(i=0;i<strlen(a);i++)
     {
           if(isdigit(a[i]))   b[count++]=a[i];
           if(isupper(a[i]))  
           {
               if(a[i]>'Q')  a[i]-=1;
               b[count++]=(a[i]-'A')/3+2+'0';
           }                                 
     }  
     strcpy(a,b);     
}

int a[100000000];

int main()
{
   int ncase;  
   long i; 
   scanf("%d",&ncase);
   getchar();
 
   for(i=0;i<ncase;i++)
      a[i]=0;
   for(i=0;i<ncase;i++)  
   {
       char b[20];
       gets(b);
       Change(b); 
       a[atol(b)]++;
   }  
   for(i=0;i<100000000;i++)
   {
       if(a[i]>1)
       {
           char c[20];
           sprintf(c,"%ld",i);
           int j;
           for(j=0;j<3;j++)  putchar(c[j]);
           putchar('-');
           printf("%s %d\n",c+3,a[i]);   
       }                    
   }
   return 0;
}
