import javax.swing.*;
import java.awt.*;

public class BorderLayoutWindow extends JFrame
{
	public BorderLayoutWindow()
	{
	    setLayout(new BorderLayout());
	    add(new JButton("NORTH"),"North");
	    add(new JButton("WEST"),"West");
	    add(new JButton("CENTER"),"Center");
	    add(new JButton("EAST"),"East");
	    add(new JButton("SOUTH"),"South");
	}
	
	public static void main(String[] args)
	{
		BorderLayoutWindow window = new BorderLayoutWindow();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setTitle("BorderLayoutWindow Application");
		window.pack();
		window.setVisible(true);
	}
}