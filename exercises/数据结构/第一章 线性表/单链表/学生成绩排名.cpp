#include "stuList.h"

void selectSort( LinkList &l ) {
	LinkList p1,p2,preMax;
	p1 = (LinkList)malloc( sizeof(LNode) );	//Ϊ�����㣬�����Ŷ��в���һ��ͷ��� 
	p1->next = l->next;	//���Ŷ���ͷ�ڵ� 
	l->next = NULL;		//���Ŷ���ͷ��� 
	while( p1->next ) {
		preMax = p1;
		for( p2=p1->next; p2->next; p2 = p2->next ) {
			if( p2->next->grade > preMax->next->grade )	
				preMax = p2;
		}
		p2 = preMax->next;	//p2���汾�����ҵ������Ľ�� 
		preMax->next = p2->next;	//��p2�Ӵ��Ŷ�����ɾȥ,���´��Ŷ��� 
		p2->next = l->next;	//��p2�嵽���Ŷ����� 
		l->next = p2;
	}
	free(p1);
}
		

int main(){
	freopen( "info.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	LinkList l;
	create( l,50 );
	selectSort(l);
	printf("�ɼ��������£�\n-------------------------------------------------------------\n");
	print(l);
    return 0;
}
