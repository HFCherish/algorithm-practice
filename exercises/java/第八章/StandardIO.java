import java.io.*;

public class StandardIO
{
	public static void main(String args[]) //throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s;
		
		try
		{		
		s = in.readLine();
		while(!s.equals("Exit"))
		{
			System.out.println("Read: " + s);
			s = in.readLine();
		}
		
		in.close();
		}catch(IOException e)
		{   e.printStackTrace();
		}
	}
}