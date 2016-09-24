#include <stdio.h>
#include <string.h>
#include <malloc.h>

//����ѧ����¼��Ϣ�ڵ� 
typedef struct node {
	char sno[12];
	double grade;
	struct node *next;
} LNode, *LinkList;

//��ʼ����ͷ���Ŀ����� 
int initList( LinkList &l ) {
	l = (LinkList)malloc( sizeof(LNode) );
	if( !l ) 	return 0;
	l->next = NULL;
	return 1;
}

//�������в���һ���ڵ�
void insert( LinkList &l, char *a, double b ) {
	LinkList ln;
	ln = (LinkList)malloc( sizeof(LNode) );
	strcpy( ln->sno,a );
	ln->grade = b;
	ln->next = l->next;
	l->next = ln;
}

//��������n����¼������
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

//��������δ֪����¼������
void create( LinkList &l ) {
	char a[12];
	double b;
	initList(l);
	while( scanf("%s",a) != EOF ) {
		scanf("%lf",&b);
		insert( l,a,b );
	}
}

//�����¼��ÿ��10��
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
	

