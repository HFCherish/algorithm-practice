#include "LinkedList.h"
#include <stdlib.h>
/*
   �͡��ϲ�������1�����ƣ�ֻ��
   1��û��ͷ���
   2��������ͬ�Ľڵ㣬�����ϲ������������
   3��b�����ܱ��ƻ�(���ϲ�b���������ʱ��b�����ܶϣ���Ҫ�����½ڵ�) 
   4��������� 
*/

void Union( LinkedList &la, LinkedList &lb ){
	LinkedList pa,pb,lc,r,pc;
	pa = la;
	pb = lb;
	lc = (LinkedList)malloc(sizeof(LNode));	//Ϊ�Ժ󷽱㣬��Ūһ��ͷ��㣬�����ɾ 
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
		pc->next = pb;	//��ʱ����δ�ƻ�b������ 
	free(lc);
}
			
			

int main()
{
	freopen("out.txt","w",stdout);
	LinkedList la,lb;
	char in[20];
	//printf("������la����\n");
	freopen("la.txt","r",stdin);
	create(la);
	//printf("\n������lb����\n");
	freopen("lb.txt","r",stdin); 
	create(lb); 
	printf("�ϲ�ǰla����Ϊ��\n");
	print(la);
	printf("�ϲ�ǰlb����Ϊ��\n");
	print(lb);
	Union(la,lb);
	printf("\n�ϲ���la����Ϊ��\n");
	print(la);
	printf("�ϲ���lb����Ϊ��\n");
	print(lb);  
    return 0;
}
