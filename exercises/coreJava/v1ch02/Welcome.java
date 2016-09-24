class Welcome 
{
	public static void main(String[] args) 
	{
		String[] greetings = new String[3];
		greetings[0] = "welcome to java";
		greetings[1] = "by cay Horstmann";
		greetings[2] = "and Gary Cornell";
		
		for( String g : greetings )
			System.out.println( g );
	}
}
