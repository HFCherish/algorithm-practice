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


//构造一个空栈 
Status InitStack(SqStack &L)
{
   L.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!L.base)  return OVERFLOW;   //存储分配失败       
   L.top=L.base;
   L.stacksize=STACK_INIT_SIZE;
   return OK;
} 

//把栈置为空栈
Status ClearStack(SqStack &L)
{
    L.top=L.base;    return OK;       
} 

//销毁栈
Status DestroyStack(SqStack &L)
{
    free(L.base);  //释放空间 
    return OK;
} 

//判断栈是否为空
Status StackEmpty(SqStack L)
{
     return !L.stacksize;  //空返回1，不空返回0    
} 
 
//插入元素e为新的栈顶元素 
Status Push(SqStack &L,SElemType e)
{
    if((L.top-L.base) >= L.stacksize)
    {
       L.base=(SElemType *)realloc(L.base,(L.stacksize+STACKINCREMENT)*sizeof(SElemType));
       L.stacksize+=STACKINCREMENT;
       L.top=L.base+L.stacksize;                  
    }       //空间再分配
    *L.top++=e;
    return OK;
} 

//删除栈顶元素,并用e返回 
Status Pop(SqStack &L,SElemType &e)
{
    if(L.top == L.base) return ERROR;
    e = *(L.top-1); 
    L.top--;
    return  OK;       
} 

//用e返回栈顶元素,并返回OK
Status GetTop(SqStack L,SElemType &e)
{
    e = *(L.top-1);
    return OK;
} 
