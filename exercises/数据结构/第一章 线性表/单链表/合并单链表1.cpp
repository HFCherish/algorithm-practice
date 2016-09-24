#include "LinkedList.h"
#include <stdlib.h> 
/*
    有两个按元素值递增的线性表，均以单链表形式存储。现将两单链表归并为
一个按元素值递减的单链表，且用原来的两个单链表节点存放归并后的单链表
*/ 
	
void Union( LinkedList &la, LinkedList &lb ){ 
	LinkedList pa,pb,r;
	pa = la->next;
	pb = lb->next;	
	la->next = NULL;	//la作结果链表的头指针 
	while( pa&&pb ){
		if( pa->data<=pb->data ){
			r = pa->next;
			pa->next = la->next;
			la->next = pa;
			pa = r;
		}
		else{
			r = pb->next;
			pb->next = la->next;
			la->next = pb;
			pb = r;
		}
	} 
	while( pa ){
		r = pa->next;
		pa->next = la->next;
		la->next = pa;
		pa = r;
	}
	while( pb ){
		r = pb->next;
		pb->next = la->next;
		la->next = pb;
		pb = r;
	}	 
} 


int main()
{
	freopen("out.txt","w",stdout);
	LinkedList la,lb;
	//printf("请输入la链表：\n");
	freopen("la.txt","r",stdin);
	create(la);
	//printf("\n请输入lb链表：\n");
	freopen("lb.txt","r",stdin);
	create(lb); 
	printf("\n合并前la链表为：\n");
	print(la);
	printf("合并前lb链表为：\n");
	print(lb);
	Union(la,lb);
	printf("合并后la链表为：\n");
	print(la);
	printf("合并后lb链表为：\n");
	print(lb); 
    return 0;
}
