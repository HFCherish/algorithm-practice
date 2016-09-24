void GetTOH(int n,POLE Goal,POLE t1,POLE t2,POLE *curr)
{
    if(curr[n]==Goal)   GetTOH(n-1,Goal,t1,t2,curr);
    else
    {
       if(curr[n]==t1)  swap(t1,t2);  //将t1作为中转站 
       GetTOH(n-1,t1,Goal,t2,curr);   //将n-1块板弄到中转站t1上 
       move(t2,Goal);       //第n块放到目标上 
       GetTOH(n-1,Goal,t2,t1,curr);    //剩余n-1放到目标上 
    }    
}
