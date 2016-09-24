#include<stdio.h>

int main()
{
    char text[4][81];
    int letter[26],i,j;
    for(i=0;i<26;i++)  letter[i]=0; 
    for(i=0;i<4;i++)  
    {
      gets(text[i]);
      for(j=0;text[i][j]!='\0';j++)
        if(text[i][j]>64 && text[i][j]<91)
             letter[text[i][j]-65]++; 
    }
    int max=letter[0];
    for(i=1;i<26;i++)  max=(max>letter[i])?max:letter[i];
    for(i=0;i<max;i++)
    {    
        for(j=0;j<26;j++)
        {
            if(letter[j]<max)
            {
                printf("  ");
                letter[j]++;                 
            }               
            else  printf("* "); 
        }
        putchar('\n');
    } 
    for(i=0;i<26;i++)
      printf("%c ",'A'+i);
    getchar();
    getchar();
    return 0;
}
