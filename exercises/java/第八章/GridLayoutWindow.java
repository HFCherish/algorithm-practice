import javax.swing.*;
import java.awt.*;

public class GridLayoutWindow extends JFrame
{
	public GridLayoutWindow()
	{
		setLayout(new GridLayout(0,2));
		add(new JButton("Button1"));
		add(new JButton("Button2"));
		add(new JButton("Button3"));
		add(new JButton("Button4"));
		add(new JButton("Button5"));
		add(new JButton("Button6"));
	}
	
	public static void main(String[] args)
	{
		GridLayoutWindow window = new GridLayoutWindow();
		window.setTitle("GridLayout Application");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		window.pack();
		window.setVisible(true);
	}
}