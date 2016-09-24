#include <stdio.h>

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
    FILE *fin,*fout;
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");
     
    int n;
    //scanf("%d",&n);
    fscanf(fin,"%d",&n); 
    int a[n];
    int i;
    for(i=0; i<n; i++)
             //scanf("%d",&a[i]);
             fscanf(fin,"%d",&a[i]); 
    int m;
    //scanf("%d",&m); 
    fscanf(fin,"%d",&m); 
    int count = 0;
    for(i=0; i<n; i++)
             if(a[i]<m) count++;
    printf("%d\n",count); 
    //fprintf(fout,"%d\n",count); 
    system("pause");
    return 0;
}
