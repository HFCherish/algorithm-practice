typedef char QElemType;
typedef char SElemType;
#include"SqStack.h"
#include"SqQueue.h"
Status Char_QSymmetry()
{
     SqQueue Q;
     SqStack L;
     char ch;
     int i,len;
     InitQueue(Q);
     ch=getchar();
     while(ch!='#')
     {
         EnQueue(Q,ch);
         ch=getchar();              
     }       
     len=QueueLength(Q);
     InitStack(L);
     for(i=0; i<len/2; i++)
     {
         DeQueue(Q,ch);
         Push(L,ch);       
     }
     if(QueueLength(Q)/2 > len) DeQueue(Q,ch);
     for(i=0; i<QueueLength(Q)/2; i++)
     {
         Pop(L,ch);
         if(ch == Q.base[Q.front]) DeQueue(Q,ch);
         else return ERROR;         
     }
     ClearQueue(Q);
     ClearStack(L);
     return OK;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
