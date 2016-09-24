import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TestButton
{
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("Test");
		frame.setLayout(new FlowLayout(FlowLayout.CENTER));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(200,100);
		JButton bt = new JButton("Press Me");
		bt.addActionListener(new ButtonHandler());
		frame.add(bt);
		frame.pack();
		frame.setVisible(true);
	}
}

class ButtonHandler implements ActionListener
{
	public void actionPerformed(ActionEvent e)
	{
		System.out.println("Action occured");
		System.out.println("Button's label is :" + e.getActionCommand());
	}
}