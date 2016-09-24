#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n); 
    printf("%d\n",n); 
    int i;
    for(i=0;i<n;i++)
    {
       struct date
       {
         int day;
         char month[7];
         int year;       
       }Haab;
       char HMonth[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
                           "zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"}; 
       struct 
       {
          int num;
          char day[10];       
          int year;
       }Tzolkin;
       char TName[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk",
                           "ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"}; 
       scanf("%d. %s %d",&Haab.day,Haab.month,&Haab.year); 
       int days,j;
       days=Haab.year*365;
         for(j=0;j<19;j++)
           if(strcmp(Haab.month,HMonth[j])==0)
           {
              days+=j*20+Haab.day+1;
              break;                                   
           }
       Tzolkin.year=days/260;
       int sday=days%260;
       if(sday==0)  
       {
         Tzolkin.year=days/260-1;
         Tzolkin.num=13;
         strcpy(Tzolkin.day,TName[19]);
       }
       
       else
       {
           Tzolkin.num=sday%13;
           if(Tzolkin.num==0)  Tzolkin.num=13;  
           strcpy(Tzolkin.day,TName[(sday+19)%20]); 
       }
       printf("%d %s %d\n",Tzolkin.num,Tzolkin.day,Tzolkin.year); 
    }
    getchar();
    getchar();
    return 0;
}
