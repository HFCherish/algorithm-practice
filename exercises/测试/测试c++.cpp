#include <stdio.h>
#include <system>
#include <thread>

int main() {
	int i=0;
    while( 1 ) {
           for( i=0; i<9600000; i++ );
           sleep(10);
    }
    return 0;
}
