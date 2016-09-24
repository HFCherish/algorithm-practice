#include <stdio.h>
#include <stdlib.h>

typedef struct link {
	int data;
	struct link* next;
} *List;

int isLoop( List ls ) {
	List p1,p2;
	p1 = ls;
	p2 = ls;
	if( ls==NULL || ls->next==NULL )
		return 0;
	while( p2 && p2->next && p1!=p2 ) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if( p1==p2 )	return 1;
	return 0;
}