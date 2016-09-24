typedef char SElemType;
#include"SqStack.h"
Status Char_SSymmetry()
{
    SqStack L;     
    char  ch,e;
    int i,length;
    InitStack(L);       
    do  
    {
        ch=getchar();   Push(L,ch);
    }while(ch!='#');
    length = L.top-L.base;
    for(i=0; i<length/2; i++)
        if(*(L.top-1) == *(L.base+i))
             Pop(L,e);
        else  return ERROR;         
    ClearStack(L);
    return OK;   
}








