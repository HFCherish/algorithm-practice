import java.io.*;

public class CopyBytes 
{
	public static void main(String[] args) throws IOException
	{
		File inputFile = new File("D:\\³ÌÐò\\Á·Ï°\\java\\farrago.txt");
		File outputFile = new File("outagainb.txt");
		
		FileInputStream in = new FileInputStream(inputFile);
		FileOutputStream out = new FileOutputStream(outputFile);
		
		int c;
		while((c = in.read()) != -1)
		   out.write(c);
		   
		in.close();
		out.close();
	}
}