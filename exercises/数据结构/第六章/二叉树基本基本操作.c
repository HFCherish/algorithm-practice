#include"Define.h"
typedef struct BiTNode
{
   char data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//�����򴴽������� 
Status CreatBiTree(BiTree &T)
{
    if(scanf("%c",T->data)==' ')  return ERROR;    
    CreatBiTree(T->lchild);
    CreatBiTree(T->rchild);
    return OK;
}

//����ݹ��㷨
Status PreOrderTraverse(BiTree T,int(*visit)(char e))
{
    if(T)
    {
       visit(T->data);
       PreOrderTraverse(T->lchild,visit);
       PreOrderTraverse(T->rchild,visit);
       return OK;     
    }
    return OK;          
} 


//����ݹ���� 
Status InOrderTraverse(BiTree T,int(*visit)(char))
{
     if(T)
     {
          InOrderTraverse(T->lchild,visit);
          visit(T->data);
          InOrderTraverse(T->rchild,visit);
          return OK;     
     }       
     return OK;
}

//����ݹ����
Status PostOrderTraverse(BiTree T,int(*visit)(char))
{
     if(T)
     {
         PostOrderTraverse(T->lchild,visit);
         PostOrderTraverse(T->rchild,visit);
         visit(T->data);
         return OK;    
     }       
     return OK;
} 

//����ǵݹ�
Status PreOrder(BiTree T)
{
           
} 

















