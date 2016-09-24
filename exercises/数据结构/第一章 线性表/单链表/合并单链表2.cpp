#include "LinkedList.h"
#include <stdlib.h>
/*
   和“合并单链表1”类似，只是
   1、没有头结点
   2、数据相同的节点，不都合并到结果链表中
   3、b链表不能被破坏(即合并b到结果链表时，b链表不能断，需要生成新节点) 
   4、结果升序 
*/

void Union( LinkedList &la, LinkedList &lb ){
	LinkedList pa,pb,lc,r,pc;
	pa = la;
	pb = lb;
	lc = (LinkedList)malloc(sizeof(LNode));	//为以后方便，先弄一个头结点，最后再删 
	lc->next = la; 
	pc = lc;
	while( pa&&pb ){
		if( pa->data<pb->data ){
			pc->next = pa;
			printf("$$%d ",pc->data);
			pc = pa;
			pa = pa->next;
		}
		else if( pa->data>pb->data ){
			r = (LinkedList)malloc(sizeof(LNode));
			r->data = pb->data;
			pc->next = r;
			printf("##%d",pc->data);
			pc = r;
			pb = pb->next;
		}
		else{
			pc->next = pa;
			printf("@@%d",pc->data);
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}
	if( pa )
		pc->next = pa;
	if( pb )
		pc->next = pb;	//此时，并未破坏b的链表 
	free(lc);
}
			
			

int main()
{
	freopen("out.txt","w",stdout);
	LinkedList la,lb;
	char in[20];
	//printf("请输入la链表：\n");
	freopen("la.txt","r",stdin);
	create(la);
	//printf("\n请输入lb链表：\n");
	freopen("lb.txt","r",stdin); 
	create(lb); 
	printf("合并前la链表为：\n");
	print(la);
	printf("合并前lb链表为：\n");
	print(lb);
	Union(la,lb);
	printf("\n合并后la链表为：\n");
	print(la);
	printf("合并后lb链表为：\n");
	print(lb);  
    return 0;
}
