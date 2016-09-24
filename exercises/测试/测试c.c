#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c;
    do {
        printf("A:Display the directory\n");
        printf("B:Display the information\n");
        printf("C:Change the date\n");
        printf("Q:Quit\n");
        printf("Choices:");
        
        c = getchar();
        c = toupper(c);
        
        if( c=='A' )
            system("DIR");
        if( c=='B' )
            system("CHKDSK");
        if( c=='C' )
            system("DATE");
    }while( c!='Q');
    
    return 0;
}
        
        
