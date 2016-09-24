import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class BoxWindow extends JFrame
{
	public BoxWindow()
	{
		Container contentPane = getContentPane();
		contentPane.setLayout(new BoxLayout(contentPane,BoxLayout.Y_AXIS));
		
		addButton("1",contentPane);
		addButton("2",contentPane);
		addButton("3",contentPane);
		addButton("4",contentPane);
		addButton("5",contentPane);
		addButton("6",contentPane);
	}
	
	private void addButton(String str,Container container)
	{
		JButton button = new JButton(str);
		button.setAlignmentX(Component.CENTER_ALIGNMENT);
		container.add(button);
	}
	
	public static void main(String[] args)
	{
		BoxWindow window = new BoxWindow();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setTitle("BoxWindow Application");
		
		window.pack();
		window.setVisible(true);
	}
}