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


//初始化链表
Status InitList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(!L)  return(OVERFLOW);
    L->next=NULL;
    return OK;       
}

//创建链表
Status CreateList(LinkList &L)
{
    LinkList P;  
    while( 1 )
    {
       P=(LinkList)malloc(sizeof(LNode));
       printf("学号：");
       scanf("%s",(P->elem).num);
       if( strcmp((P->elem).num,"#")==0 )	 break;	//'#'表示学生信息输入结束 
       printf("姓名：");
       scanf("%s",(P->elem).name);
       P->next=L->next;  L->next=P;                        
    }
    return OK;
} 

//打印链表
Status PrintList(LinkList L)
{
    
    printf("学号            姓名\n"); 
    while(L->next)
    {
        printf("%-14s%-s\n",(L->next->elem).num,(L->next->elem).name);
        L=L->next;           
    }
    return OK;       
} 

//插入操作
Status ListInsert(LinkList &L,int i)
{
    
}

//排序
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

//删除链表中介于mink和maxk中的结点
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

//逆置
Status LinkList_Reverse(LinkList &L)  //链表中至少有两个结点 
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

//两链表合并
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
 
 
//主函数
int main()
{
   LinkList La,Lb;
   char mink[12],maxk[12];
   InitList(La);   InitList(Lb);
   printf("请依照提示输入LA：\n");
   CreateList(La);  
   printf("请依照提示输入LB：\n");
   CreateList(Lb);
   LinkList_Union(La,Lb);   
   printf("\n合并后现在链表la信息为:\n");
   PrintList(La);
   LinkList_Reverse(La);     
   printf("\n逆置后链表信息为：\n");
   PrintList(La);
   printf("\n请依次输入删除学生信息的学号上、下界：\n");
   scanf("%s%s",mink,maxk);
   Del_Between(La,mink,maxk);   
   printf("删除后链表信息为：\n\n");
   PrintList(La);
   return 0;   
} 









 

