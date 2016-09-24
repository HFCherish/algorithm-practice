#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct
{
    char num[12];
    char name[20];        
}ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;        
}SqList;

//����һ���յ����Ա� 
int InitList(SqList &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;       
}

//����һ�����Ա�
int CreatList(SqList &L)
{
   int i=0;
   printf("������ѧ����Ϣ��\n");
   
   do
   {
      printf("ѧ�ţ�"); 
      scanf("%s",(L.elem)->num);   
      printf("������");
      scanf("%s",(L.elem)->name);    
      getchar();   //�������һ��enter�ַ� 
      L.length++;
      i++;                 
   }while((getchar()!= EOF) && (L.length<=L.listsize));
   if((L.length) > (L.listsize))return OVERFLOW;
   return OK;    
}

//��ӡ���Ա�
int PrintList(SqList L)
{
   int i;
   printf("num          name\n");
   for(i=0; i<L.length ;i++)
      printf("%-13s%-s\n",(L.elem+i)->num,(L.elem+i)->name);
   return OK;
} 

//�������Ա� 
void DestoryList(SqList &L)
{
    free(L.elem);   L.elem=NULL;     
}

//���Ա���� 
void ClearList(SqList &L) 
{
    L.length=0;     
}

//�жϱ��Ƿ�Ϊ�� 
int ListEmpty(SqList L)
{
    return !L.length;     //Ϊ��ʱ����1 
}

//����� 
int ListLength(SqList L)
{
    return L.length;    
}

//�ӱ��л�ȡ��i������Ԫ�صĵ�ַ 
ElemType *GetELem(SqList L,int i)
{
    if(i<1||i>L.length)
    {
       printf("%dis illegal!\n",i);
       exit(ERROR);                    
    }         
    else return L.elem+i-1;
}

//�ȽϺ��� 
int equal(char a[],char b[])
{
    return strcmp(a,b);   
}

//���ر��е�һ����e����compare������ϵ������Ԫ�ص�λ�� 
int LocateElem(SqList L,ElemType *e,int(*compare)(char a[],char b[]))
{
    int i;
    for(i=0; i<L.length; i++)
        if((*compare)((L.elem+i)->num,e->num)==0) return i;       
    printf("����Ҫ���Ԫ�ز����ڣ�\n");
    return INFEASIBLE;
}

//����ѧ�Ŵ�С��������
int ListSort(SqList &L)             //�������� 
{
    int i,j;
    char t[12];
    if(ListEmpty(L))
    {
        printf("List empty!\n");
        return ERROR;                
    }
    for(i=1; i < (L.length-1) ;i++)
    {
         j=i;   strcpy(t,(L.elem+i)->num);
         if(j>0 && strcmp(t,(L.elem+j-1)->num)<0)
         {
              strcpy((L.elem+j-1)->num,(L.elem+j)->num);
              j--;    
         }     
         strcpy((L.elem+j)->num,t);
    } 
    return OK;
} 

//����
int ListInsert(SqList &L,ElemType *x)
{
    int i; 
    if(ListSort(L))
    {
       if(L.length >= L.listsize)
       {
            ElemType *newbase;
            newbase=(ElemType *)realloc(L.elem,(LISTINCREMENT+L.listsize)*sizeof(ElemType));
            if(!newbase){printf("�洢�ռ��ٷ���ʧ�ܣ�\n");  exit(OVERFLOW);}
            L.elem = newbase;
            L.listsize += LISTINCREMENT;            
       }
       i=L.length;
       strcpy(x->num,(L.elem+i)->num);   strcpy(x->name,(L.elem+i)->name);
       L.length++;
       ListSort(L);
       return OK;   
    }   
}

//�Ƚ�����˳���Ĵ�С
int ListComp(SqList p,SqList q)
{
    if(ListSort(p) && ListSort(q))
    {
        int len1,len2,i;
        len1 = p.length;   len2 = q.length;
        for(i=0; i<len1 ;i++)
        {
            if(strcmp((p.elem+i)->num,(q.elem+i)->num)>0)return 1; 
            if(strcmp((p.elem+i)->num,(q.elem+i)->num)<0)return -1; 
        }              
        if(len1<len2)return -1;
        else if(len1==len2)return 0;
    }    
}

//˳���Ԫ�ص�����
int reverse(SqList &l) 
{
     if(ListSort(l))
     {
        ElemType *p,*q,*t;
        int i;
        t=(ElemType*)malloc(sizeof(ElemType));
        p=l.elem; q=p+1;
        for(i=0; i<l.length-1; i++)
        {
            t=q;q=p;p=t;
            q=t+1;                          
        }  
        return OK;             
     }    
}

//����˳���ϲ�
int UnionList(SqList &p,SqList q)
{
     int i;
     if((p.length+q.length) < p.listsize)
     {
            ElemType *newbase;
            newbase=(ElemType *)realloc(p.elem,(LISTINCREMENT+p.listsize)*sizeof(ElemType));
            if(!newbase) {printf("�洢�ռ��ٷ���ʧ�ܣ�\n");  exit(OVERFLOW);}
            p.elem = newbase;
            p.listsize += LISTINCREMENT;                        
     }
     for(i=0; i<q.length; i++)
     {
        if(!LocateElem(p,q.elem+i,equal))
        {
            ListInsert(p,q.elem+i);
            p.length++;
        }         
     }
     return OK; 
}




 //��˳���ϲ����浽һ���µĿռ��� 
int MergeList(SqList p,SqList q,SqList &l)
{
    int i=0,j=0,len1,len2;
    InitList(l);
    len1=p.length;  len2=q.length;
    if((len1+len2) < l.listsize)
     {
            ElemType *newbase;
            newbase=(ElemType *)realloc(l.elem,(LISTINCREMENT+l.listsize)*sizeof(ElemType));
            if(!newbase) {printf("�洢�ռ��ٷ���ʧ�ܣ�\n");  exit(OVERFLOW);}
            l.elem = newbase;
            l.listsize += LISTINCREMENT;                        
     }
     while(i<len1 &&j<len2)
     {
           if( strcmp((p.elem+i)->num,(q.elem+j)->num) <= 0)
           {
              ListInsert(l,p.elem+i);
              l.length++;    i++;                                               
           } 
           if( strcmp((p.elem+i)->num,(q.elem+j)->num) > 0)
           {
              ListInsert(l,q.elem+j);
              l.length++;    j++;                                        
           }            
     }
     while(i<=len1)
           ListInsert(l,p.elem+i++);
     while(j<len2)
           ListInsert(l,q.elem+j++);
     return OK;  
}

//������
int main()
{
      ElemType *e;
      e=(ElemType *)malloc(sizeof(ElemType)); 
      SqList La,Lb,Lc;
      InitList(La);   
      InitList(Lb);
      CreatList(La);   
      CreatList(Lb);
      ListComp(La,Lb);
      UnionList(La,Lb);   PrintList(La);
      MergeList(La,Lb,Lc);   PrintList(Lc); 
      printf("������Ҫ�����ѧ����Ϣ��\nѧ�ţ�");
      scanf("%s",e->num);
      printf("������");
      scanf("%s",e->name);
      ListInsert(La,e);  PrintList(La);
      return 0;   
} 





 



