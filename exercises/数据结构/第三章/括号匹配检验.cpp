typedef char SElemType;
#include"SqStack.h"
Status Bracket_Match()
{
   SqStack L;
   char ch,e;
   InitStack(L);
   ch=getchar();
   while(ch!=EOF)
   {
         switch(ch)
         {
            case '(': Push(L,ch);break;
            case '[': Push(L,ch);break;  
            case '{': Push(L,ch);break;
            case '<': Push(L,ch);break;    //��������ջ 
            case ')': if(!StackEmpty(L) && *(L.top-1) == '(') { Pop(L,e); break; }
                      else return ERROR;
            case ']': if(!StackEmpty(L) && *(L.top-1) == '[') { Pop(L,e); break; }
                      else return ERROR;
            case '}': if(!StackEmpty(L) && *(L.top-1) == '{') { Pop(L,e); break; }
                      else return ERROR;
            case '>': if(!StackEmpty(L) && *(L.top-1) == '<') { Pop(L,e); break; }
                      else return ERROR;   //�����ſ��Ƿ���ջ��Ԫ��ƥ�䣬��ƥ�䣬����ѭ�����������򣬷���0 
            default: break;
         }   
         ch=getchar();                        
   }
   if(StackEmpty(L))  return ERROR;
   ClearStack(L); 
   return OK;      
}
