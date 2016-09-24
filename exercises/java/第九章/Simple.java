import java.awt.*;
import java.applet.*;
import java.util.*;

public class Simple extends Applet
{
	StringBuffer str;
	
	public void init()
	{
		str = new StringBuffer();
		addItem("Applet init	");
	}
	
	public void start()
	{
		addItem("Applet start	");
	}
	
	public void stop()
	{
		addItem("Applet stop	");
	}
	
	public void destroy()
	{
		addItem("Applet destroy		");
	}
	
	void addItem(String newWord)
	{
		System.out.println(newWord);
		str.append(newWord);
		repaint();
	}
	
	public void paint(Graphics g)
	{
		g.drawRect(0,0,getSize().width-1,getSize().height-1);
		g.drawString(str.toString(),5,15);
	}
}