#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = "`1234567890-=\\qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    char c;
    while ((c = getchar()) != EOF)
    {
          int i;
          for(i=1; s[i] && s[i]!=c; i++);
          if(s[i])  putchar(s[i-1]);
          else putchar(c);       //”–Œ Ã‚ 
    } 
    system("pause");
    return 0;
}
