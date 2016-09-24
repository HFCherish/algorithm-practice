#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void FastSort(int* p,int n);
int putw(int,FILE*);

int main()
{
    FILE *in,*out;
    int TypeNum,*num,i;
    if((in=fopen("file1","w"))==NULL)
       exit(0);
    if((out=fopen("file2","w"))==NULL)    
       exit(0);
    scanf("%d",&TypeNum);   //�������������     
    if(TypeNum<1 || TypeNum>10000)  exit(0);
    putw(TypeNum,in);    //������������д�������ļ� 
    fputc('\n',in);    
    num=(int*)malloc(sizeof(int)*TypeNum); 
    for(i=0;i<TypeNum;i++)
    {
        scanf("%d",&num[i]);  
        if(num[i]<1 || num[i]>20000)  exit(0);
        putw(num[i],in);
        fputc(' ',in);                      
    }      //����ÿ�ѹ��ӵ���Ŀ��д�������ļ� 
    FastSort(num,TypeNum);  //�Թ�����Ŀ���������� 
    int tail=TypeNum-1;
    for(i=0;tail>0;i++,tail--)
       num[tail-1]=num[tail-1]+num[tail];           
    int sum=0;
    for(i=0;i<TypeNum-1;i++)  sum+=num[i]; 
    if(i>=231)  exit(0);
    putw(sum,out);   //������Сֵ��д������ļ� 
    fread(&i,sizeof(int),1,out);
    printf("%d",i);
    system("pause");
    fclose(in);
    fclose(out);
    return 0;
}


void FastSort(int*p,int n) //��������� 
{
    int s,t,i,j,temp,flag;
    s=0;  t=n-1;
    if(t<=s+1)
    {
        if(t==s+1 && p[t]>p[s])
        {
            temp=p[t];  p[t]=p[s]; p[s]= temp;
        }          
        return;
    }     
    i=s+1;  j=t;
    flag=p[s];
    do
    {
        while(p[i]>flag) i++;
        while(p[j]<flag) j--;
        if(i<j)
        {
           temp=p[i];  p[i]=p[j];  p[j]=temp;       
        }
    }while(i<j);
    p[s]=p[j];   p[j]=flag;
    FastSort(p,j);   FastSort(p+j+1,n-j-1);
    return;
}

int putw(int i,FILE* p)
{
   char* s;
   s=(char*)&i;
   putc(s[0],p);putc(s[1],p);  
   return i;    
} 



