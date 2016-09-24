#include<stdio.h>
#include<string.h> 

int main()
{
    char start[20],end[4],res[100][201];
    int i,j=0;    
    while(scanf("%s",start) && strcmp(start,"ENDOFINPUT")!=0)
    {
         char ciphertext[201];
         getchar();
         gets(ciphertext);
         for(i=0;ciphertext[i]!='\0';i++)
         {    
             if(ciphertext[i]>='A' && ciphertext[i]<='Z')
                res[j][i]=(ciphertext[i]+21-'A')%26+'A';
             else  res[j][i]=ciphertext[i];
         }
         res[j][i]='\0'; 
         scanf("%s",end);
         j++;                                              
    } 
    for(i=0;i<j;i++)
       puts(res[i]); 
    getchar();
    getchar();
    return 0;
}
