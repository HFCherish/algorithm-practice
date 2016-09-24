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
            case '<': Push(L,ch);break;    //×óÀ¨ºÅÈëÕ» 
            case ')': if(!StackEmpty(L) && *(L.top-1) == '(') { Pop(L,e); break; }
                      else return ERROR;
            case ']': if(!StackEmpty(L) && *(L.top-1) == '[') { Pop(L,e); break; }
                      else return ERROR;
            case '}': if(!StackEmpty(L) && *(L.top-1) == '{') { Pop(L,e); break; }
                      else return ERROR;
            case '>': if(!StackEmpty(L) && *(L.top-1) == '<') { Pop(L,e); break; }
                      else return ERROR;   //ÓÒÀ¨ºÅ¿´ÊÇ·ñÓëÕ»¶¥ÔªËØÆ¥Åä£¬ÈôÆ¥Åä£¬Ìø³öÑ­»·¼ÌÐø£»·ñÔò£¬·µ»Ø0 
            default: break;
         }   
         ch=getchar();                        
   }
   if(StackEmpty(L))  return ERROR;
   ClearStack(L); 
   return OK;      
}
