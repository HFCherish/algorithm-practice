#include "stuList.h"

void selectSort( LinkList &l ) {
	LinkList p1,p2,preMax;
	p1 = (LinkList)malloc( sizeof(LNode) );	//为处理方便，给待排队列插入一个头结点 
	p1->next = l->next;	//待排队列头节点 
	l->next = NULL;		//已排队列头结点 
	while( p1->next ) {
		preMax = p1;
		for( p2=p1->next; p2->next; p2 = p2->next ) {
			if( p2->next->grade > preMax->next->grade )	
				preMax = p2;
		}
		p2 = preMax->next;	//p2保存本次所找到的最大的结点 
		preMax->next = p2->next;	//将p2从待排队列中删去,更新待排队列 
		p2->next = l->next;	//将p2插到已排队列中 
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
	printf("成绩排名如下：\n-------------------------------------------------------------\n");
	print(l);
    return 0;
}
