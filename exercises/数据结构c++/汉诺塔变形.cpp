void GetTOH(int n,POLE Goal,POLE t1,POLE t2,POLE *curr)
{
    if(curr[n]==Goal)   GetTOH(n-1,Goal,t1,t2,curr);
    else
    {
       if(curr[n]==t1)  swap(t1,t2);  //��t1��Ϊ��תվ 
       GetTOH(n-1,t1,Goal,t2,curr);   //��n-1���Ū����תվt1�� 
       move(t2,Goal);       //��n��ŵ�Ŀ���� 
       GetTOH(n-1,Goal,t2,t1,curr);    //ʣ��n-1�ŵ�Ŀ���� 
    }    
}
