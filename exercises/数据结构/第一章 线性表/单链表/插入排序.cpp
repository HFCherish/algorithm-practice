#include "LinkedList.h"

//�������� 
void LINSort( LinkedList &l ) {
	LinkedList p1,p2,p;
	p1 = l->next->next;	//����������һ���ڵ� ��p1ָ��ڶ����ڵ� 
	l->next->next = NULL;	//�����һ����¼���� 
	while( p1 ) {
		p = p1->next;	//��¼p1����һ���ڵ� 
		int tp = p1->data;
		for( p2=l; p2->next && p2->next->data<tp; p2=p2->next );
		p1->next = p2->next;		//���ڵ�p1����p2���� 
		p2->next = p1;
		p1 = p;
	}
}


int main(){
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	LinkedList l;
	create(l);
	printf("ԭ����");
	print(l);
	LINSort(l);
	printf("�����");
	print(l); 
    return 0;
}
