#include <stdio.h>
#include <string.h>
#include <malloc.h>

//定义学生记录信息节点 
typedef struct node {
	char sno[12];
	double grade;
	struct node *next;
} LNode, *LinkList;

//初始化带头结点的空链表 
int initList( LinkList &l ) {
	l = (LinkList)malloc( sizeof(LNode) );
	if( !l ) 	return 0;
	l->next = NULL;
	return 1;
}

//向链表中插入一个节点
void insert( LinkList &l, char *a, double b ) {
	LinkList ln;
	ln = (LinkList)malloc( sizeof(LNode) );
	strcpy( ln->sno,a );
	ln->grade = b;
	ln->next = l->next;
	l->next = ln;
}

//创建包括n个记录的链表
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

//创建包括未知个记录的链表
void create( LinkList &l ) {
	char a[12];
	double b;
	initList(l);
	while( scanf("%s",a) != EOF ) {
		scanf("%lf",&b);
		insert( l,a,b );
	}
}

//输出记录，每行10个
void print( LinkList l ) {
	LinkList p;
	p = l->next;
	int i=0;
	while( p ) {
		printf("%s: %.2lf	",p->sno,p->grade);
		i++;
		if( i%10 == 0 )	
			printf("\n");
		p = p->next;
	}
} 
	

