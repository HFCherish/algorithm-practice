#include <stdio.h>

struct result
{
       char sport[30];
       char sex;
       char school[50];
       float score;
       int grade;       
}res[5];

int main()
{
   int i, m, w;
   m = w = 0;
   for(i = 0; i < 5; i++)
       if(res[i].sex == 'm')
           m += res[i].grade;
       else 
           w += res[i].grade;
   printf("school: %s        man: %d    woman: %d   sum: %d\n", res[0].school, m, w, m+w); 
   system("pause");
   return 0;
}
