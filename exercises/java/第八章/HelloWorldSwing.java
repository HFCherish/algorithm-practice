import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class HelloWorldSwing
{
    public static void main(String args[])
    {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("HelloWorld");
        final JLabel label = new JLabel("Hello World!");
        frame.getContentPane().add(label,BorderLayout.EAST);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(200,70);
        frame.setVisible(true);
    }	
}