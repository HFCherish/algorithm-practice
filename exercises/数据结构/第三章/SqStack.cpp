#include"Define.h" 
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
/*typedef struct
{
   char num[12];
   char name[20];
}SElemType;*/
typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;        
}SqStack;


//����һ����ջ 
Status InitStack(SqStack &L)
{
   L.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!L.base)  return OVERFLOW;   //�洢����ʧ��       
   L.top=L.base;
   L.stacksize=STACK_INIT_SIZE;
   return OK;
} 

//��ջ��Ϊ��ջ
Status ClearStack(SqStack &L)
{
    L.top=L.base;    return OK;       
} 

//����ջ
Status DestroyStack(SqStack &L)
{
    free(L.base);  //�ͷſռ� 
    return OK;
} 

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack L)
{
     return !L.stacksize;  //�շ���1�����շ���0    
} 
 
//����Ԫ��eΪ�µ�ջ��Ԫ�� 
Status Push(SqStack &L,SElemType e)
{
    if((L.top-L.base) >= L.stacksize)
    {
       L.base=(SElemType *)realloc(L.base,(L.stacksize+STACKINCREMENT)*sizeof(SElemType));
       L.stacksize+=STACKINCREMENT;
       L.top=L.base+L.stacksize;                  
    }       //�ռ��ٷ���
    *L.top++=e;
    return OK;
} 

//ɾ��ջ��Ԫ��,����e���� 
Status Pop(SqStack &L,SElemType &e)
{
    if(L.top == L.base) return ERROR;
    e = *(L.top-1); 
    L.top--;
    return  OK;       
} 

//��e����ջ��Ԫ��,������OK
Status GetTop(SqStack L,SElemType &e)
{
    e = *(L.top-1);
    return OK;
} 
