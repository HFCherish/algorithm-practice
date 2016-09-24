#include"Define.h"
typedef struct BiTNode
{
   char data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//按先序创建二叉树 
Status CreatBiTree(BiTree &T)
{
    if(scanf("%c",T->data)==' ')  return ERROR;    
    CreatBiTree(T->lchild);
    CreatBiTree(T->rchild);
    return OK;
}

//先序递归算法
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


//中序递归遍历 
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

//后序递归遍历
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

//先序非递归
Status PreOrder(BiTree T)
{
           
} 

















