#include "LinkedList.h"

//插入排序 
void LINSort( LinkedList &l ) {
	LinkedList p1,p2,p;
	p1 = l->next->next;	//假设至少有一个节点 ，p1指向第二个节点 
	l->next->next = NULL;	//假设第一个记录有序 
	while( p1 ) {
		p = p1->next;	//记录p1的下一个节点 
		int tp = p1->data;
		for( p2=l; p2->next && p2->next->data<tp; p2=p2->next );
		p1->next = p2->next;		//将节点p1插入p2后面 
		p2->next = p1;
		p1 = p;
	}
}


int main(){
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	LinkedList l;
	create(l);
	printf("原链表：");
	print(l);
	LINSort(l);
	printf("排序后：");
	print(l); 
    return 0;
}
