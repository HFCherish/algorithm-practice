#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void FastSort(int*,int);

int main()
{
    FILE *in,*out;
    int TypeNum,*num,*energy,i;
    if((in=fopen("file1","w"))==NULL)
       exit(0);
    if((out=fopen("file2","w"))==NULL)    
       exit(0);
    scanf("%d",&TypeNum);   
     
    if(TypeNum<1 || TypeNum>10000)  exit(0);
    putw(TypeNum,in);
    fputc('\n',in);    
    num=(int*)malloc(sizeof(int)*TypeNum);
    for(i=0;i<TypeNum;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<1 || num[i]>20000)  exit(0);
        putw(num[i],in);
        fputc(' ',in);                      
    } 
   // printf("%d",TypeNum);   
    FastSort(num,TypeNum);
    int tail=TypeNum-1;
    energy=(int*)malloc(sizeof(int)*(TypeNum-1));
    for(i=0;tail>0;i++,tail--)
    {
       num[tail-1]=num[tail-1]+num[tail];    
       energy[i]=num[tail-1];         
    }
    int sum=0;
    for(i=i-1;i>=0;i--)  sum+=energy[i];
    if(i>=231)  exit(0);
    putw(sum,out);
    printf("%d",sum);
    system("pause");
    fclose(in);
    fclose(out);
    return 0;
}


void FastSort(int*p,int n) //°´½µÐò¿ìÅÅ 
{
    int s,t,i,j,temp,flag;
    s=0;  t=n-1;
    if(t<=s+1)
    {
        if(t==s+1 && p[t]<p[s])
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





