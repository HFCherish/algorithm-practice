import javax.swing.*;
import java.awt.*;

public class GridBagLayoutWindow extends JFrame
{
	private void makeButton(String name,GridBagLayout gridBag,GridBagConstraints c)
	{
		JButton button = new JButton(name);
		gridBag.setConstraints(button,c);
		add(button);
	}
	
	public GridBagLayoutWindow()
	{
		GridBagLayout gridBag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();
		setLayout(gridBag);
		
		c.fill = GridBagConstraints.BOTH;
		c.weightx = 1.0;
		makeButton("Button1",gridBag,c);
		makeButton("Button2",gridBag,c);
		makeButton("Button3",gridBag,c);
		c.gridwidth = GridBagConstraints.REMAINDER;
		makeButton("Button4",gridBag,c);
		
		c.weightx = 0.0;
		makeButton("5",gridBag,c);
		
		c.gridwidth = GridBagConstraints.RELATIVE;
		makeButton("6",gridBag,c);
		c.gridwidth = GridBagConstraints.REMAINDER;
		makeButton("7",gridBag,c);
		
		c.weighty = 1.0;
		c.gridheight = 2;
		c.gridwidth = 1;
		makeButton("8",gridBag,c);
		
		c.weighty = 0.0;
		c.gridheight = 1;
		c.gridwidth = GridBagConstraints.REMAINDER;
		makeButton("9",gridBag,c);
		makeButton("10",gridBag,c);
	}
	
	public static void main(String[] args)
	{
		GridBagLayoutWindow window = new GridBagLayoutWindow();
		window.setTitle("Gridbaglayout Application");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		window.pack();
		window.setVisible(true);
	}
}