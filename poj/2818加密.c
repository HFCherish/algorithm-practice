#include<stdio.h>
#include<malloc.h>

int main()
{
    int n,k,i,j,*a,*c;
    char *b,*d;
    while(scanf("%d",&n) && n!=0)
    {
        a=(int*)malloc(n*sizeof(int));  //Ϊ��Կa����ռ�         
        for(i=0;i<n;i++)   scanf("%d",&a[i]);   
        while(scanf("%d",&k) && k!=0)    //������ܴ���k 
        {
             getchar();   
             b=(char*)malloc((n+1)*sizeof(char));    //Ϊ��������Ϣb����ռ� 
             d=(char*)malloc((n+1)*sizeof(char));   //���ռ�����Ϣd 
             for(i=0;i<n;i++)  d[i]=' ';
             d[n]='\0';         //d��ʼ��Ϊ�ո� 
             gets(b);
             for(i=0;b[i]!='\0';i++); 
             c=(int*)malloc(i*sizeof(int));    //c�洢��������Ϣ�ڼ��ܺ�����Ϣ�е�λ�� 
             int p;
             for(j=0;j<i;j++)  c[j]=j;     //��ʼ��c 
             for(j=0;j<k;j++) 
                 for(p=0;p<i;p++)
                     c[p]=a[c[p]]-1;  //k�μ�����c�ĸ��� 
             for(p=0;p<i;p++)
                 d[c[p]]=b[p];     //���ռ�����Ϣ�ݴ���d 
             puts(d); 
        }
        putchar('\n');                     
    } 
    free(a);  free(b);
    free(c);  free(d);
    return 0;
}
