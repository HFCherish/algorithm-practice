import javax.swing.*;
import java.awt.*;
public class FlowLayoutWindow extends JFrame
{
	public FlowLayoutWindow()
	{
		setLayout(new FlowLayout(FlowLayout.LEFT));
		add(new JLabel("Buttons"));
		add(new JButton("Button1"));
		add(new JButton("2"));
		add(new JButton("Long named Button4"));
		add(new JButton("Button5"));
	}
	
	public static void main(String[] args)
	{
	   FlowLayoutWindow window = new FlowLayoutWindow();
	   window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	   window.setTitle("FlowLayoutWindow Application");
	   window.pack();
	   window.setVisible(true);
	}
}