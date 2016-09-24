#include <stdlib.h>

typedef struct link {
	int data;
	struct link* next;
} *List;

void traverse( List &ls ) {
	List p1,p2,p3;
	while( ls && ls->next ) {
		p1 = ls;
		p2 = p1->next;
		p1->next = NULL;
		while( p2 ) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		ls = p1;
	}
}