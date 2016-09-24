#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f = 1;
    char c;
    while((c=getchar()) != EOF)
    {
          if(c == '\"')    
          {
               printf("%s",f==1 ? "¡°":"¡±");                    
               f = !f;
          }
          else putchar(c);
    }
    system("pause");
    return 0;
}
