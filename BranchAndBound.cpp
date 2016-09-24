import java.io.*;


public class BranchAndBound {
	public int MAX=50;
	public static int[][] M1,M2;//M1�ǳ��Ⱦ���M2�Ƿ��þ���
	public void init()
	{
		M1=new int[MAX][MAX];
		M2=new int[MAX][MAX];
		
		try{
		Reader r = new BufferedReader(new FileReader("E:\\m1.txt"));  
		StreamTokenizer stok = new StreamTokenizer(r);  
		stok.parseNumbers();  
		stok.nextToken();  
		
			for(int i=0;i<MAX;i++)
				for(int j=0;j<MAX;j++)
				{
		         if (stok.ttype == StreamTokenizer.TT_NUMBER)  
		           M1[i][j]=(int)stok.nval; 
		         else  
		           j--; 
		        stok.nextToken();  
				}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		try{
			Reader r = new BufferedReader(new FileReader("E:\\m2.txt"));  
			StreamTokenizer stok = new StreamTokenizer(r);  
			stok.parseNumbers();   
			stok.nextToken();  
		
				for(int i=0;i<MAX;i++)
					for(int j=0;j<MAX;j++)
					{
			        if (stok.ttype == StreamTokenizer.TT_NUMBER)  
			             M2[i][j]=(int)stok.nval; 
			        else  
			             j--; 
			      stok.nextToken();  
					}
			}
			catch(Exception e)
			{
				System.out.println(e);
				}
	}
	
	
	public  int[][] Floyd(int[][] dd,int N)           /* ���������㷨��ʵ�ֺ��� */
	{
		int[][] d=new int[MAX][MAX]; //��������һ�����飬����Ҫ������ֱ����dd����
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				d[i][j]=dd[i][j];
		int u=0,v=0,w=0;
		for(u=0;u<N;u++)
		{
			for(v=0;v<N;v++){
				for(w=0;w<N;w++)
				{
					if(d[v][u]+d[u][w]<d[v][w])
					{
						d[v][w]=d[v][u]+d[u][w];
					}
				}
			}
		}
		return d;
	}

	public static void main(String args[])
	{
		BranchAndBound a=new BranchAndBound();
	    a.init();
	    
	    int[][] mindist=a.Floyd(M1,50);
		int[][] mincost=a.Floyd(M2,50);
		
	    int node_dist=0;//�׳��е���ǰ�ڵ���еľ���
	    int node_cost=0;//�׳��е���ǰ�ڵ���еĻ���
		int[] stack=new int[50]; //�洢�߹��Ľڵ����
		int current_mindist=9999;//��ǰ�Ӽ׳��е��ҳ��е���̾���
		int current_cost=0; //��ǰ�Ӽ׳��е��ҳ��еĻ��ѣ���Ӧ��̾���Ļ��ѣ�������С����
		int next=0;
		int current=0;
		int depth=0;
		int[] visited=new int[50];  //��־��visited=0��ʾδ����
		int[] path=new int[50];
		stack[0]=0;
		stack[1]=0;
		visited[0]=1;
		int i=0;
		
		while( depth>=0 )//��ʾ������ʼ�ͽ�����������ʼʱ�Ӽ׳��г�����ջ�գ�depth=0������ʱ������ϣ����нڵ������ջ����ջҲΪ�գ�depth=0
			           //����while����ѭ��������ʵ�ִӵ�ǰ�ĳ�����Ѱ��һ���ڽ��ĳ��� */
		{
			current = stack[depth];
			next = stack[depth+1];
			for( i=next+1; i<50; i++ ) //Ѱ����һ�����������ĳ��У�����ҵ����˳�ѭ����ע�⣺ֻ�ҵ�һ�����������ĳ���
			{
				//���ڵ㲻��ͨ������Ѱ����һ���ڵ�
				if( M1[current][i] == 9999 ) continue;    
				
				//������ǰ�ڵ�����·�Ѿ�����Ŀǰ���·�½磬���߾�����ǰ�ڵ����С���ѳ���1500����֦
				if( (mindist[current][49]+node_dist)>=current_mindist || (mincost[current][49]+node_cost)>1500 ) continue;
				
				//
				if( visited[i]==1 ) continue;
				
				//�ҵ���һ���������ĳ��о��˳�
				if( i<50 ) break;				
			}
			if(i==50)
			{
				depth--;
			    if(depth==-1)//-1˵���˻��˵�һ�㣬��ʱ�Ӽ׵�����49�����б�����ɣ������˳�while��
					break;
				visited[stack[depth+1]]=0;
				node_dist -= M1[stack[depth]][stack[depth+1]];
				node_cost -= M2[stack[depth]][stack[depth+1]];
			}
			else
			{
							
				depth++;
				stack[depth] = i;
				stack[depth+1] = 0; //���赽���˱����У��ӱ����п�ʼ���±���������Ҫ��1���п�ʼ�������˴�����0����֤���´�whileѭ����next��0��ʼ
				node_dist += M1[stack[depth-1]][i]; //node_dist��ʾ�׳��е�current=stack[depth]�ڵ�ľ���
				node_cost += M2[stack[depth-1]][i]; //node_cost��ʾ�׳��е�current=stack[depth]�ڵ�ľ���
				visited[i] = 1;
				if(i==49)  //����ߵ������һ�����У����ҳ��У��ж��Ƿ�ȵ�ǰ·�����̣�������̣��͸���current_mindist��current_cost,������·��
				{
					if(node_cost<=1500 && node_dist<current_mindist) //��������1500�����ҵ�ǰ�ľ���С��������������̾��룬��ô�͸�����̾��롢���ѡ�·������Ϣ
					{	
							
						current_cost = node_cost;
						current_mindist = node_dist;
						for(int m=0; m<depth+1; m++) //����·��path����-1��ʾ����
						{
							path[m] = stack[m];
							System.out.print(stack[m]+"  ");
						}
						for(int n=depth+1; n<50; n++)
							path[n]=-1;
						System.out.println("��̾����ǣ�"+current_mindist+"  �ķ��ǣ�"+current_cost);
							
						depth-=2;    //�������㣬��Ϊǰ����������һ�㣬��if(i==49)����depth++
						visited[stack[depth+1]]=0;
						visited[stack[depth+2]]=0;	  node_cost=node_cost-M2[stack[depth]][stack[depth+1]]-M2[stack[depth+1]][stack[depth+2]];
						node_dist=node_dist-M1[stack[depth]][stack[depth+1]]-M1[stack[depth+1]][stack[depth+2]];
						    
							
					}
						
				}
						
			}
				
		}
		System.out.println("����·���ǣ�");
		for(int m=0;m<path.length;m++)
		{
			if(path[m]!=-1)
			System.out.print(path[m]+"  ");
		}
		System.out.println();
		
		System.out.println("��̾�����:"+current_mindist+"  �����ǣ�"+current_cost);
	}
}


