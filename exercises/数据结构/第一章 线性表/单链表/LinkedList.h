#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkedList;

//����һ����ͷ���Ŀ������ɹ�����1��ʧ�ܷ���0 
int initList( LinkedList &l ){
	l = (LinkedList)malloc(sizeof(LNode));
	if( !l )	return 0; 
	l->next = NULL;
	return 1;
}

//������ͷ����һ���ڵ㣬ֵΪa 
void insert( LinkedList &l, int a ) {
	LinkedList ln = (LinkedList)malloc( sizeof(LNode) );
	ln->data = a;
	ln->next = l->next;
	l->next = ln;
}

/*����һ��ֵΪa�Ľڵ㵽�����β�� 
void insert( LinkedList &l, int a ){
	LinkedList tp,r;
	tp = l;
	while( tp->next )
		tp = tp->next;
	r = (LinkedList)malloc(sizeof(LNode));
	r->data = a;
	tp->next = r;
	r->next = NULL;
}*/

//ɾ��һ��ֵΪa�Ľڵ㡣�����ڣ�ɾ��������1�����򣬷���0 
int del( LinkedList &l, int a ){
	LinkedList now,pre,r;
	now = pre = l->next;
	while( now && now->data!=a ){
		pre = now;
		now = now->next;
	}
	if( now ){
		pre->next = now->next;
		free(now);
		return 1;
	}
	return 0;
}

//���벢����һ������
int create( LinkedList &l ){
	initList(l);
	int a;
	while( scanf("%d",&a)!=EOF ){
		insert(l,a); 
	}
	return 1;
}

//���һ������
void print( LinkedList l ){
	LinkedList tp;
	tp = l->next;
	while( tp->next ){
		printf("%d->",tp->data);
		tp = tp->next;
	}
	printf("%d\n",tp->data);
}
	
