import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class FindMax extends Applet implements ActionListener
{
     Label result;
     TextField in1,in2,in3;
     Button bt;
     int a = 0, b = 0, c = 0,max;
     
     public void init()
     {
     	result = new Label("��������3�����Ƚϵ�����");
     	in1 = new TextField(5);
     	in2 = new TextField(5);
     	in3 = new TextField(5);
     	bt = new Button("�Ƚ�");
     	add(in1);
     	add(in2);
     	add(in3);
     	add(bt);
     	add(result);
     	bt.addActionListener(this);
     }
     
     public static void main(String[] args)
     {
     	FindMax find = new FindMax();
     	Frame f = new Frame("Find Max");
     	f.addWindowListener(new WindowAdapter(){
     		   public void windowCloseing(WindowEvent e)
     		   {
     		      System.exit(0);	
     		   }
     		});
     	f.setLayout(new FlowLayout());
     	f.setSize(400,200);
     	f.add(find);
     	find.init();
     	f.setVisible(true);
     }
     
     public void actionPerformed(ActionEvent e)
     {
     	a = Integer.parseInt(in1.getText());
     	b = Integer.parseInt(in2.getText());
     	c = Integer.parseInt(in3.getText());
     	if(a>b)
     	  max = (a>c)?a:c;
     	else
     	  max = (b>c)?b:c;
     	result.setText("3���������ֵ��:"+max);
     }
}