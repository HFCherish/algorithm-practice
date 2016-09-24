#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n>=0 && n<=100)
		{
			char a;
			switch(n/10)
			{
			case 10:
			case 9: a = 'A';	break;
			case 8: a = 'B';	break;
			case 7: a = 'C';	break;
			case 6: a = 'D';	break;
			default: a = 'E';	break;	
			}	
			printf("%c\n",a);
		}
		else printf("Score is error!\n"); 
	} 
    system("pause");
    return 0;
}
