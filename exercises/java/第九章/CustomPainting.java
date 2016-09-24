import java.awt.*;
import java.applet.*;
import javax.swing.*;

public class CustomPainting extends JApplet
{
	static String[] imageFile = {"1.jpg","2.jpg","3.jpg"};
	public void init()
	{
		Container c = getContentPane();
		c.setLayout(new GridLayout(1,3));
		for(int i=0; i<imageFile.length;i++)
		{
			Image image = getImage(getCodeBase(),imageFile[i]);
	        ImagePanel imagePanel = new ImagePanel(image);
	        c.add(imagePanel);
		}
	}
}

class ImagePanel extends JPanel
{
    Image image;
    public ImagePanel(Image image)
    {
    	this.image = image;
    }	
    
    public void paintComponent(Graphics g)
    {
    	super.paintComponent(g);
    	g.drawImage(image,0,0,this);
    }
}
