#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE* fp;
  char ch,filename[10];
  printf("please enter the filename:\n");
  scanf("%s",filename);
  if((fp=fopen(filename,"w"))==NULL)
  {
    printf("cannot open file\n");
    exit (0);         
  }
  ch=getchar();
  printf("please enter the string:\n");
  ch=getchar();
  while(ch!='#')
  {
    fputc(ch,fp);putchar(ch);
    ch=getchar();
  }
  putchar(10);
  fclose(fp);
  system("pause");
  return 0;
}

