#include<stdio.h>
#include<string.h>

int main()
{
   int ncases,i,sure[12];
   char l[13],r[13],cmp[5],lpos[12],upos[12];   
   scanf("%d",&ncases); 
   getchar();
   for(i=0;i<ncases;i++)
   {
       memset(sure,0,sizeof(sure));
       memset(lpos,'o',sizeof(lpos));
       memset(upos,'o',sizeof(upos)); 
       int j;
       for(j=0;j<3;j++)
       {
             scanf("%s%s%s",l,r,cmp);
             int k,len,t;
             len = strlen(l);
             t=strcmp(cmp,"even");            
             if(t==0)
                 for(k=0;k<len;k++)
                 {
                    sure[l[k]-'A']=1;   
                    sure[r[k]-'A']=1;  
                 }              
             else
                if(t>0)
                    for(k=0;k<len;k++)
                    {   
                         int m,n;
                         m=l[k]-'A';
                         n=r[k]-'A';
                         if(sure[m]==0) 
                            upos[m] = l[k];
                         if(sure[n]==0) 
                            lpos[n] = r[k];     
                    }                                         
                else
                    for(k=0;k<len;k++)
                    { 
                       int m,n;
                       m=l[k]-'A';
                       n=r[k]-'A';
                       if(sure[m]==0) 
                          lpos[m] = l[k];
                       if(sure[n]==0) 
                          upos[n] = r[k];   
                    }                               
       }         
       for(j=0;j<12;j++)
           if(lpos[j]!='o' && sure[lpos[j]-'A']==0)
           {
              printf("%c is the counterfeit coin and it is light.\n",lpos[j]);
              break;                        
           }     
          else
            if(upos[j]!='o' && sure[upos[j]-'A']==0)
            {
                printf("%c is the counterfeit coin and it is heavy.\n",upos[j]);
                break;                        
            }  
   }
   system("pause");                        
   return 0;
}
