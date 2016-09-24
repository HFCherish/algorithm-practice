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

//构造一个空的线性表 
int InitList(SqList &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;       
}

//构造一个线性表
int CreatList(SqList &L)
{
   int i=0;
   printf("请输入学生信息：\n");
   
   do
   {
      printf("学号："); 
      scanf("%s",(L.elem)->num);   
      printf("姓名：");
      scanf("%s",(L.elem)->name);    
      getchar();   //吸收最后一个enter字符 
      L.length++;
      i++;                 
   }while((getchar()!= EOF) && (L.length<=L.listsize));
   if((L.length) > (L.listsize))return OVERFLOW;
   return OK;    
}

//打印线性表
int PrintList(SqList L)
{
   int i;
   printf("num          name\n");
   for(i=0; i<L.length ;i++)
      printf("%-13s%-s\n",(L.elem+i)->num,(L.elem+i)->name);
   return OK;
} 

//销毁线性表 
void DestoryList(SqList &L)
{
    free(L.elem);   L.elem=NULL;     
}

//线性表清空 
void ClearList(SqList &L) 
{
    L.length=0;     
}

//判断表是否为空 
int ListEmpty(SqList L)
{
    return !L.length;     //为空时返回1 
}

//求表长度 
int ListLength(SqList L)
{
    return L.length;    
}

//从表中获取第i个数据元素的地址 
ElemType *GetELem(SqList L,int i)
{
    if(i<1||i>L.length)
    {
       printf("%dis illegal!\n",i);
       exit(ERROR);                    
    }         
    else return L.elem+i-1;
}

//比较函数 
int equal(char a[],char b[])
{
    return strcmp(a,b);   
}

//返回表中第一个与e满足compare（）关系的数据元素的位序 
int LocateElem(SqList L,ElemType *e,int(*compare)(char a[],char b[]))
{
    int i;
    for(i=0; i<L.length; i++)
        if((*compare)((L.elem+i)->num,e->num)==0) return i;       
    printf("满足要求的元素不存在！\n");
    return INFEASIBLE;
}

//按照学号大小升序排序
int ListSort(SqList &L)             //插入排序 
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

//插入
int ListInsert(SqList &L,ElemType *x)
{
    int i; 
    if(ListSort(L))
    {
       if(L.length >= L.listsize)
       {
            ElemType *newbase;
            newbase=(ElemType *)realloc(L.elem,(LISTINCREMENT+L.listsize)*sizeof(ElemType));
            if(!newbase){printf("存储空间再分配失败！\n");  exit(OVERFLOW);}
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

//比较两个顺序表的大小
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

//顺序表元素的逆置
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

//两非顺序表合并
int UnionList(SqList &p,SqList q)
{
     int i;
     if((p.length+q.length) < p.listsize)
     {
            ElemType *newbase;
            newbase=(ElemType *)realloc(p.elem,(LISTINCREMENT+p.listsize)*sizeof(ElemType));
            if(!newbase) {printf("存储空间再分配失败！\n");  exit(OVERFLOW);}
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




 //两顺序表合并并存到一个新的空间中 
int MergeList(SqList p,SqList q,SqList &l)
{
    int i=0,j=0,len1,len2;
    InitList(l);
    len1=p.length;  len2=q.length;
    if((len1+len2) < l.listsize)
     {
            ElemType *newbase;
            newbase=(ElemType *)realloc(l.elem,(LISTINCREMENT+l.listsize)*sizeof(ElemType));
            if(!newbase) {printf("存储空间再分配失败！\n");  exit(OVERFLOW);}
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

//主函数
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
      printf("请输入要插入的学生信息：\n学号：");
      scanf("%s",e->num);
      printf("姓名：");
      scanf("%s",e->name);
      ListInsert(La,e);  PrintList(La);
      return 0;   
} 





 



