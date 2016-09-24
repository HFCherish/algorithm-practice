#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node {
	char sno[12];
	double grade;
	struct node *next;
} LNode, *LinkList;

int initList( LinkList &l ) {
	l = (LinkList)malloc( sizeof(LNode) );
	if( !l ) return 0;
	l->next = NULL;
	return 1;
}

void insert( LinkList &l, char *a, double b ) {
	LinkList ln;
	ln = (LinkList)malloc( sizeof(LNode) );
	strcpy( ln->sno,a );
	ln->grade = b;
	ln->next = l->next;
	l->next = ln;
}

void create( LinkList &l, int n ) {
	int i;
	char a[12];
	double b;
	initList(l);
	for( i=0; i<n; i++ ) {
		scanf("%s%lf",a,&b);
		insert( l,a,b );
	}
}

void create( LinkList &l ) {
	initList(l);
	char a[12];
	double b;
	while( scanf("%s",a) != EOF ) {
		scanf("%lf",&b);
		insert( l,a,b );
	}
}

void print( LinkList l ) {
	LinkList p;
	int i=0;
	p = l->next;
	while( p ) {
		printf("%s£º%.2lf	",p->sno,p->grade);
		i++;
		if( i%10 == 0 )	printf("\n");
		p = p->next;
	}
	printf("\n");
} 
