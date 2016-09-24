#include "LinkedList.h"
#include <stdlib.h> 
/*
    ��������Ԫ��ֵ���������Ա����Ե�������ʽ�洢���ֽ���������鲢Ϊ
һ����Ԫ��ֵ�ݼ��ĵ���������ԭ��������������ڵ��Ź鲢��ĵ�����
*/ 
	
void Union( LinkedList &la, LinkedList &lb ){ 
	LinkedList pa,pb,r;
	pa = la->next;
	pb = lb->next;	
	la->next = NULL;	//la����������ͷָ�� 
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
	//printf("������la����\n");
	freopen("la.txt","r",stdin);
	create(la);
	//printf("\n������lb����\n");
	freopen("lb.txt","r",stdin);
	create(lb); 
	printf("\n�ϲ�ǰla����Ϊ��\n");
	print(la);
	printf("�ϲ�ǰlb����Ϊ��\n");
	print(lb);
	Union(la,lb);
	printf("�ϲ���la����Ϊ��\n");
	print(la);
	printf("�ϲ���lb����Ϊ��\n");
	print(lb); 
    return 0;
}
