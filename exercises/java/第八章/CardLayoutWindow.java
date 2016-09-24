import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CardLayoutWindow extends JFrame implements ActionListener
{
	JPanel cards;
	CardLayout CLayout = new CardLayout();
	
	public CardLayoutWindow()
	{
		//setLayout(new BorderLayout());
		JPanel cp = new JPanel();
		JButton bt = new JButton("¿¨Æ¬ÇÐ»»");
		bt.addActionListener(this);
		cp.add(bt);
		add("North",cp);
		
		cards = new JPanel();
		cards.setLayout(CLayout);
		
		JPanel p1 = new JPanel();
		p1.add(new JButton("Button1"));
		p1.add(new JButton("Button2"));
		p1.add(new JButton("Button3"));
		
		JPanel p2 = new JPanel();
		p2.add(new JTextField("textfield:",20));
		
		cards.add("Card with buttons",p1);
		cards.add("Card with textfield",p2);
		
		add("Center",cards);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		CLayout.next(cards);
	}
	
	public static void main(String[] args)
	{
		CardLayoutWindow window = new CardLayoutWindow();
		window.setTitle("CardLayout Application");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		window.pack();
		window.setVisible(true);
	}
}