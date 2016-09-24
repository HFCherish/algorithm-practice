import java.awt.*;
import java.applet.*;
import javax.swing.*;

public class SwingSimple extends JApplet
{
	JTextField field;
	
	public void init()
	{
		Container contentPane = getContentPane();
		field = new JTextField();
		field.setEditable(false);
		contentPane.setLayout(new GridLayout(1,N0));
	    
	    contentPane.add(field);
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