#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct
{
    char num[12];
    char name[20];        
}ElemType;
typedef struct student
{
    ElemType elem;
    struct student *next;
}LNode,*LinkList;
typedef int Status;


//��ʼ������
Status InitList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(!L)  return(OVERFLOW);
    L->next=NULL;
    return OK;       
}

//��������
Status CreateList(LinkList &L)
{
    LinkList P;  
    while( 1 )
    {
       P=(LinkList)malloc(sizeof(LNode));
       printf("ѧ�ţ�");
       scanf("%s",(P->elem).num);
       if( strcmp((P->elem).num,"#")==0 )	 break;	//'#'��ʾѧ����Ϣ������� 
       printf("������");
       scanf("%s",(P->elem).name);
       P->next=L->next;  L->next=P;                        
    }
    return OK;
} 

//��ӡ����
Status PrintList(LinkList L)
{
    
    printf("ѧ��            ����\n"); 
    while(L->next)
    {
        printf("%-14s%-s\n",(L->next->elem).num,(L->next->elem).name);
        L=L->next;           
    }
    return OK;       
} 

//�������
Status ListInsert(LinkList &L,int i)
{
    
}

//����
Status SortList(LinkList &L)
{
    LinkList p1,p2,head1,p;
    head1=L->next->next;
    L->next->next=NULL;
    while(head1!=NULL)
    {
        p1=L->next;   p2=L;
        p=head1;
        head1=head1->next;
        while(strcmp((p->elem).num,(p1->elem).num)>0)
        {
            p2=p2->next;  p1=p1->next;                                             
        }                  
        if(strcmp((p->elem).num,(p1->elem).num)<0)
        {
            p2->next = p;   p->next = p1;                                          
        }
    }
    return OK;      
} 

//ɾ�������н���mink��maxk�еĽ��
Status Del_Between(LinkList &L,char mink[],char maxk[])
{
    LinkList Lmin,Lmax;
    SortList(L);
    Lmin=L;
    while((Lmin->next)!=NULL && strcmp((Lmin->next->elem).num,mink)<0)
        Lmin=Lmin->next;                                    
    if(Lmin->next->next)
    {
        Lmax=Lmin->next->next;
        while(Lmax!=NULL && strcmp((Lmax->elem).num,maxk)<0)
            Lmax=Lmax->next;
        Lmin->next=Lmax;
    }
    return OK;
} 

//����
Status LinkList_Reverse(LinkList &L)  //������������������� 
{
    LinkList p,q,t;
    p=L->next;q=p->next;
    p->next=NULL;
    while(q)
    {
        t=q->next;  q->next=p;  
        p=q;    q=t;       
    }
    return OK;       
} 

//������ϲ�
Status LinkList_Union(LinkList &La,LinkList Lb)
{
    LinkList pc,pa,pb;
    SortList(La);   SortList(Lb);
    pc=La;  pa=La->next; pb=Lb->next; 
    while(pa&&pb)
    {
       if(strcmp((pa->elem).num,(pb->elem).num)>0)
       {
          pc->next=pb;   pc=pb;  pb=pb->next; 
       }
       else
       {
          pc->next=pa;   pc=pa;   pa=pa->next;   
       }                                                                
    }
    pc->next=pa?pa:pb;
    free(Lb);
    return OK;
}
 
 
//������
int main()
{
   LinkList La,Lb;
   char mink[12],maxk[12];
   InitList(La);   InitList(Lb);
   printf("��������ʾ����LA��\n");
   CreateList(La);  
   printf("��������ʾ����LB��\n");
   CreateList(Lb);
   LinkList_Union(La,Lb);   
   printf("\n�ϲ�����������la��ϢΪ:\n");
   PrintList(La);
   LinkList_Reverse(La);     
   printf("\n���ú�������ϢΪ��\n");
   PrintList(La);
   printf("\n����������ɾ��ѧ����Ϣ��ѧ���ϡ��½磺\n");
   scanf("%s%s",mink,maxk);
   Del_Between(La,mink,maxk);   
   printf("ɾ����������ϢΪ��\n\n");
   PrintList(La);
   return 0;   
} 









 

