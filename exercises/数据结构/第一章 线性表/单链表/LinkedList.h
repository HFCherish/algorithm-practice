#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkedList;

//创建一个有头结点的空链表，成功返回1，失败返回0 
int initList( LinkedList &l ){
	l = (LinkedList)malloc(sizeof(LNode));
	if( !l )	return 0; 
	l->next = NULL;
	return 1;
}

//在链表头插入一个节点，值为a 
void insert( LinkedList &l, int a ) {
	LinkedList ln = (LinkedList)malloc( sizeof(LNode) );
	ln->data = a;
	ln->next = l->next;
	l->next = ln;
}

/*插入一个值为a的节点到链表的尾部 
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

//删除一个值为a的节点。若存在，删除并返回1；否则，返回0 
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

//输入并构造一个链表
int create( LinkedList &l ){
	initList(l);
	int a;
	while( scanf("%d",&a)!=EOF ){
		insert(l,a); 
	}
	return 1;
}

//输出一个链表
void print( LinkedList l ){
	LinkedList tp;
	tp = l->next;
	while( tp->next ){
		printf("%d->",tp->data);
		tp = tp->next;
	}
	printf("%d\n",tp->data);
}
	
