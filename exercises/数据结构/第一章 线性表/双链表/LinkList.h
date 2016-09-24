#include <iostream>
using namespace std;

//˫������ڵ� 
typedef struct link {
	int dt;
	struct link * pre;
	struct link * next;
} LNode,*LinkList;

//��ʼ��˫������ 
int initList( LinkList &l ){
	l = (LinkList)malloc( sizeof(LNode) );
	if( !l )
		return 0;
	l->pre = l->next = NULL;
	return 1;
}

//��˫�������в���һ���ڵ�
void insert( LinkList &l, int a ){
	LinkList tp;
	tp = (LinkList)malloc( sizeof(LNode) );
	tp->dt = a;
	if( l->next == NULL ){
		l->next = l->pre = tp;
		tp->next = tp->pre = l;
	}
	else{
		l->next->pre = tp;
		tp->next = l->next;
		l->next = tp;
		tp->pre = l;
	}
}

//���벢����˫������ 
void create( LinkList &l ){
	int a;
	initList(l);
	LinkList ln;
	while( cin >> a )
		insert(l,a);
}

void print( LinkList &l ){
	LinkList tp;
	tp = l->next;
	while( tp && tp!=l ){
		cout << tp->dt << ' ';
		tp = tp->next;
	}
	cout << endl;
}

		
	
