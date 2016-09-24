#include <stdio.h>

typedef struct node {
	int a;
	struct node *next;
}*lnode;

void A( lnode pr,lnode p ) {
	if( p!=NULL ) {
		lnode tp;
		tp = p->next;
		p->next = pr;
		pr = p;
		p = tp;
	}
}

void B( lnode pr,lnode p ) {
	if( pr!=NULL ) {
		lnode tp;
		tp = pr->next;
		pr->next = p;
		p = pr;
		pr = tp;
	}
}