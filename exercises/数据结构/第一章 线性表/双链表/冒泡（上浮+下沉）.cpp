#include "LinkList.h"
//#include <iostream>
//using namespace std;
#include <stdio.h>


void swap( LinkList &l1, LinkList &l2 ){
	l1->dt ^= l2->dt ^= l1->dt ^= l2->dt;
}
	

void BubbleSort( LinkList &l ){
	int change;
	LinkList front,rear,tp;
	change = 1;
	front = l->next;
	rear = l->pre;
	while( change && front!=rear && front && rear ){
		change = 0;
		tp = front;
		while( tp!=rear ){
			if( tp->dt > tp->next->dt ){
				swap( tp,tp->next );
				change = 1;
			}
			tp = tp->next;
		}
		rear = rear->pre;
		tp = rear;
		while( tp!=front ){
			if( tp->dt < tp->pre->dt ){
				swap( tp,tp->pre );
				change = 1;
			}
			tp = tp->pre;
		}
		front = front->next;
	}
} 

int main(){
	freopen( "in.txt","r",stdin );
	freopen( "out.txt","w",stdout );
	LinkList l;
	create(l);
	printf("ԭ����:	\n"); 
	//cout << "ԭ����:	" << endl; 
	print(l);
	BubbleSort(l);
	printf("\n���������\n"); 
	//cout << endl << "���������:	" << endl; 
	print(l);
	
	return 0;
}
