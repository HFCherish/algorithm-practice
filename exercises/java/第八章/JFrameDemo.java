import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JFrameDemo
{
    public static void main(String[] args)
    {
        JFrame.setDefaultLookAndFeelDecorated(true);
        
        JFrame frame = new JFrame("FrameDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JLabel emptyLabel = new JLabel("");
        emptyLabel.setPreferredSize(new Dimension(175,100));
        frame.getContentPane().add(emptyLabel);
        
        frame.pack();
        frame.setVisible(true);
    }	
}