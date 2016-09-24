#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;        
}BiNode,*BiTree;

//构造二叉排序树 
BiTree BST(int*p,int n)
{
    if(n==0)  return NULL;
    BiTree T;
    T=(BiTree)malloc(sizeof(BiNode));
    T->data=p[0];
    if(n==1)  {T->lchild=NULL;  T->rchild=NULL;  return T;}
    if(p[1]>p[0])  T->rchild=BST(p+1,n-1);
    else if(p[1]<p[0])   T->lchild=BST(p+1,n-1); 
    return T;
}

//中序遍历二叉排序树
void InOrderTraverse(BiTree T,int(*visit)(int))
{
     //if(!T) return;
   if(T)
   {
     InOrderTraverse(T->lchild,visit);
     visit(T->data);
     InOrderTraverse(T->rchild,visit);
   }
   else return;
}

//visit函数
int print(int a)
{
   printf("%d ",a);
   return 1;    
}
 
 
//二叉排序
int main()
{
   int a[5];
   int i;
   for(i=0; i<5; i++)
      scanf("%d",&a[i]);
   BiTree T;
   T=BST(a,5);
   InOrderTraverse(T,print);
   system("pause");
   return 0;          
} 









