import java.io.*;


public class BranchAndBound {
	public int MAX=50;
	public static int[][] M1,M2;//M1是长度矩阵，M2是费用矩阵
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
	
	
	public  int[][] Floyd(int[][] dd,int N)           /* 弗洛伊德算法的实现函数 */
	{
		int[][] d=new int[MAX][MAX]; //重新申请一个数组，很重要，不能直接用dd来求
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
		
	    int node_dist=0;//甲城市到当前节点城市的距离
	    int node_cost=0;//甲城市到当前节点城市的花费
		int[] stack=new int[50]; //存储走过的节点城市
		int current_mindist=9999;//当前从甲城市到乙城市的最短距离
		int current_cost=0; //当前从甲城市到乙城市的花费，对应最短距离的花费，不是最小花费
		int next=0;
		int current=0;
		int depth=0;
		int[] visited=new int[50];  //标志，visited=0表示未访问
		int[] path=new int[50];
		stack[0]=0;
		stack[1]=0;
		visited[0]=1;
		int i=0;
		
		while( depth>=0 )//表示遍历开始和结束条件，开始时从甲城市出发，栈空，depth=0；结束时遍历完毕，所有节点均被出栈，故栈也为空，depth=0
			           //整个while（）循环体用来实现从当前的城市中寻找一个邻近的城市 */
		{
			current = stack[depth];
			next = stack[depth+1];
			for( i=next+1; i<50; i++ ) //寻找下一个满足条件的城市，如果找到则退出循环，注意：只找第一个满足条件的城市
			{
				//两节点不连通，继续寻找下一个节点
				if( M1[current][i] == 9999 ) continue;    
				
				//经过当前节点的最短路已经超过目前最短路下界，或者经过当前节点的最小花费超过1500，截枝
				if( (mindist[current][49]+node_dist)>=current_mindist || (mincost[current][49]+node_cost)>1500 ) continue;
				
				//
				if( visited[i]==1 ) continue;
				
				//找到第一满足条件的城市就退出
				if( i<50 ) break;				
			}
			if(i==50)
			{
				depth--;
			    if(depth==-1)//-1说明退回了第一层，此时从甲到其他49个城市遍历完成，可以退出while了
					break;
				visited[stack[depth+1]]=0;
				node_dist -= M1[stack[depth]][stack[depth+1]];
				node_cost -= M2[stack[depth]][stack[depth+1]];
			}
			else
			{
							
				depth++;
				stack[depth] = i;
				stack[depth+1] = 0; //假设到达了丙城市，从丙城市开始向下遍历，还是要从1城市开始遍历，此处赋成0，保证了下次while循环中next从0开始
				node_dist += M1[stack[depth-1]][i]; //node_dist表示甲城市到current=stack[depth]节点的距离
				node_cost += M2[stack[depth-1]][i]; //node_cost表示甲城市到current=stack[depth]节点的距离
				visited[i] = 1;
				if(i==49)  //如果走到了最后一个城市，即乙城市，判断是否比当前路径更短，如果更短，就更新current_mindist和current_cost,并保存路径
				{
					if(node_cost<=1500 && node_dist<current_mindist) //花费少于1500，而且当前的距离小于曾经遇到的最短距离，那么就更新最短距离、花费、路径等信息
					{	
							
						current_cost = node_cost;
						current_mindist = node_dist;
						for(int m=0; m<depth+1; m++) //保存路径path，用-1表示结束
						{
							path[m] = stack[m];
							System.out.print(stack[m]+"  ");
						}
						for(int n=depth+1; n<50; n++)
							path[n]=-1;
						System.out.println("最短距离是："+current_mindist+"  耗费是："+current_cost);
							
						depth-=2;    //回退两层，因为前面向下走了一层，看if(i==49)上面depth++
						visited[stack[depth+1]]=0;
						visited[stack[depth+2]]=0;	  node_cost=node_cost-M2[stack[depth]][stack[depth+1]]-M2[stack[depth+1]][stack[depth+2]];
						node_dist=node_dist-M1[stack[depth]][stack[depth+1]]-M1[stack[depth+1]][stack[depth+2]];
						    
							
					}
						
				}
						
			}
				
		}
		System.out.println("最优路径是：");
		for(int m=0;m<path.length;m++)
		{
			if(path[m]!=-1)
			System.out.print(path[m]+"  ");
		}
		System.out.println();
		
		System.out.println("最短距离是:"+current_mindist+"  花费是："+current_cost);
	}
}


