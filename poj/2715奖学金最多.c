#include<stdio.h>
#include<malloc.h>    //ע�������ַ����ַ���ʱҪ��ȥ֮ǰ����Ŀո���� 
 
typedef struct
{
   char name[20];
   int FinalAveGrade;
   int ClassMark;
   char Leader;
   char WestStu;
   int PaperNum;        
}*Data;


int main()
{
    int N,i,mmax=0,imax=0,all,AllMoney=0;
    scanf("%d",&N);  
    Data data;
    data=(Data)malloc(N*sizeof(Data));    
    for(i=0;i<N;i++)
    {
        all=0; 
        scanf("%s%d%d",data[i].name,&data[i].FinalAveGrade,&data[i].ClassMark);        
        getchar();    data[i].Leader=getchar();
        getchar();    data[i].WestStu=getchar();
        scanf("%d",&data[i].PaperNum);  
        if(data[i].FinalAveGrade>80)  
          if(data[i].PaperNum>0)  all+=8000;
        if(data[i].FinalAveGrade>85)
        {
         if(data[i].ClassMark>80) 
         {
            all+=4000;
           if(data[i].Leader=='Y')  all+=850;
         }
         if(data[i].WestStu=='Y') all+=1000;
        }
        if(data[i].FinalAveGrade>90)   all+=2000;
        AllMoney+=all;
        if(all>mmax)  
        {
           imax=i;                     
           mmax=all;
        }
    } 
    printf("%s\n%d\n%d\n",data[imax].name,mmax,AllMoney);    
    return 0;
}
