#include"Define.h" 
#define QUEUE_MAXSIZE 100
//typedef char QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;       
}SqQueue;         //定义循环队列的数据结构

//初始化队列 
Status InitQueue(SqQueue &L)
{
    L.base=(QElemType *)malloc(QUEUE_MAXSIZE*sizeof(QElemType));
    if(!L.base) return ERROR;
    L.front=L.rear=0;
    return OK;       
} 

//清空队列
Status ClearQueue(SqQueue &L)
{
    L.front=L.rear=0;
    return OK;      
}
 
//返回L的元素个数
int QueueLength(SqQueue &L)
{
    return (L.rear - L.front + QUEUE_MAXSIZE) % QUEUE_MAXSIZE;
}

//插入元素e为新的队尾元素
Status EnQueue(SqQueue &L,QElemType e)
{
    if((L.rear+1)%QUEUE_MAXSIZE == L.front)  return ERROR;
    L.base[L.rear]=e;
    L.rear = (L.rear+1)%QUEUE_MAXSIZE;
    return OK;       
} 

//若对不空，删除队头元素，并用e返回
Status DeQueue(SqQueue &L,QElemType &e)
{
    if(QueueLength(L)==0) return ERROR;
    e=L.base[L.front];
    L.front=(L.front+1)%QUEUE_MAXSIZE;
    return OK;       
} 













 
