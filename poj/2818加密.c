#include<stdio.h>
#include<malloc.h>

int main()
{
    int n,k,i,j,*a,*c;
    char *b,*d;
    while(scanf("%d",&n) && n!=0)
    {
        a=(int*)malloc(n*sizeof(int));  //为密钥a分配空间         
        for(i=0;i<n;i++)   scanf("%d",&a[i]);   
        while(scanf("%d",&k) && k!=0)    //输入加密次数k 
        {
             getchar();   
             b=(char*)malloc((n+1)*sizeof(char));    //为待加密信息b分配空间 
             d=(char*)malloc((n+1)*sizeof(char));   //最终加密信息d 
             for(i=0;i<n;i++)  d[i]=' ';
             d[n]='\0';         //d初始化为空格 
             gets(b);
             for(i=0;b[i]!='\0';i++); 
             c=(int*)malloc(i*sizeof(int));    //c存储待加密信息在加密后在信息中的位置 
             int p;
             for(j=0;j<i;j++)  c[j]=j;     //初始化c 
             for(j=0;j<k;j++) 
                 for(p=0;p<i;p++)
                     c[p]=a[c[p]]-1;  //k次加密中c的更新 
             for(p=0;p<i;p++)
                 d[c[p]]=b[p];     //最终加密信息暂存于d 
             puts(d); 
        }
        putchar('\n');                     
    } 
    free(a);  free(b);
    free(c);  free(d);
    return 0;
}
