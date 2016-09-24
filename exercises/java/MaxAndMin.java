import java.io.*;
import java.util.*;

public class MaxAndMin
{
	public static void main(String[] args)
	{
		
		try
		{
		  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		  int[] a = new int[10];
		  for(int i = 0; i<10; i++)
		  {
		  	  a[i] = Integer.parseInt(in.read());
		  }
		  
		}catch(IOException e){e.printStackTrace();}
		Arrayss ar = new Arrayss(a);
		System.out.println("max = " + ar.getMax());
		System.out.println("min = " + ar.getMin());
		
		in.close();
	}
}		

class Arrayss
{
	int max;
	int min;
	public Arrayss(int[] a)
	{
		if(a == null)  
		{
			System.out.println("Array doesn't exist!");
			return;			
		}
		int max = a[0], min = a[0];
		for(int i = 1; i < a.length; i++)
		{
			if(a[i] > max)  max = a[i];
			else
			  if(a[i] < min)  min = a[i];
		}
		this.max = max;
		this.min = min;
	}
	public int getMax()
	{
		return max;
	}
	public int getMin()
	{
		return min;
	}
}