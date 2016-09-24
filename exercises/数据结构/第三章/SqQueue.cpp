#include"Define.h" 
#define QUEUE_MAXSIZE 100
//typedef char QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;       
}SqQueue;         //����ѭ�����е����ݽṹ

//��ʼ������ 
Status InitQueue(SqQueue &L)
{
    L.base=(QElemType *)malloc(QUEUE_MAXSIZE*sizeof(QElemType));
    if(!L.base) return ERROR;
    L.front=L.rear=0;
    return OK;       
} 

//��ն���
Status ClearQueue(SqQueue &L)
{
    L.front=L.rear=0;
    return OK;      
}
 
//����L��Ԫ�ظ���
int QueueLength(SqQueue &L)
{
    return (L.rear - L.front + QUEUE_MAXSIZE) % QUEUE_MAXSIZE;
}

//����Ԫ��eΪ�µĶ�βԪ��
Status EnQueue(SqQueue &L,QElemType e)
{
    if((L.rear+1)%QUEUE_MAXSIZE == L.front)  return ERROR;
    L.base[L.rear]=e;
    L.rear = (L.rear+1)%QUEUE_MAXSIZE;
    return OK;       
} 

//���Բ��գ�ɾ����ͷԪ�أ�����e����
Status DeQueue(SqQueue &L,QElemType &e)
{
    if(QueueLength(L)==0) return ERROR;
    e=L.base[L.front];
    L.front=(L.front+1)%QUEUE_MAXSIZE;
    return OK;       
} 













 
