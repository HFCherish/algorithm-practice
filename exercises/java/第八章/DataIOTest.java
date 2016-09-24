import java.io.*;

public class DataIOTest
{
	public static void main(String args[]) throws IOException
	{
		DataOutputStream out = new DataOutputStream(new FileOutputStream("invoice1.txt"));
		double[] prices = {19.99, 5.99, 4.99, 3.99,6.99};
		int[] unites = {12,8,3,4,5};
		String[] descs = {"Java Tshirt", "Java Mug", "Duke Juggling Dolls", "Java Pin", "Java Key Chain"};
	    
	    for(int i = 0; i < prices.length; i++)
	    {
	    	out.writeDouble(prices[i]);
	    	out.writeChar('\t');
	    	out.writeInt(unites[i]);
	    	out.writeChar('\t');
	    	out.writeUTF(descs[i]);
	    	out.writeChar('\t');
	    }	
		out.close();
		
		DataInputStream in = new DataInputStream(new FileInputStream("invoice1.txt"));
		
		double price;
		int unit;
		String desc;
		double total = 0.0;
		
		for(int i = 0; i < prices.length; i++)
		{
			price = in.readDouble();
			in.readChar();
			unit = in. readInt();
			in.readChar();
			desc = in.readUTF();
			in.readChar();
			
			System.out.println("You've ordered " + unit + "units of " + desc + "at $ " + price);
			total += unit * price;
		}
		System.out.println("For a Total of $ " + total);
		
		in.close();
	}
}