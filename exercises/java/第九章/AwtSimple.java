import java.awt.*;
import java.applet.*;

public class AwtSimple extends Applet
{
	TextField field;
	
	public void init()
	{
		field = new TextField();
		field.setEditable(false);
		setLayout(new GridLayout(10));
	    
	    add(field);
	    validate();
	    addItem("≥ı ºªØ°≠°≠");
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
	
	void addItem(String newword)
	{
		String t = field.getText();
		System.out.println(newword);
		field.setText(t + newword);
	}
	
}