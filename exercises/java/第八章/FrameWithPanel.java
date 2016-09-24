import javax.swing.*;
import java.awt.*;

public class FrameWithPanel extends JFrame
{
	public FrameWithPanel(String str)
	{
	   super(str);
	}
	
	public static void main(String[] args)
	{
		FrameWithPanel fr = new FrameWithPanel("Hello!");
		fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fr.setSize(200,200);
		
		JPanel pan = new JPanel();
		//pan.setSize(200,100);
		pan.setBackground(Color.yellow);
		pan.setLayout(new GridLayout(2,1));
		pan.add(new JButton("È·¶¨")); //pan.add(new JButton("hi"));
		fr.setContentPane(pan);
		
		fr.setVisible(true);
	}
}