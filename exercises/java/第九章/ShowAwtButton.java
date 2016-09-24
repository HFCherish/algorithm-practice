import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class ShowAwtButton extends Applet implements ActionListener
{
	private Frame myFrame = new GUIWindow("AWT显示窗口");
	
	public void init()
	{
		Button bt = new Button("单击此处观看AWT所有组件");
		bt.addActionListener(this);
		add(bt);		
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(myFrame.isVisible())
		   myFrame.setVisible(false);
		else
		{
		    myFrame.setSize(500,300);
		    myFrame.setVisible(true);	
		}
	}
	
}

class GUIWindow extends Frame implements ActionListener
{
	final String FILEDIALOGMENUITEM = "file dialog...";
	public GUIWindow(String str)
	{
		super(str);
		Panel bottomPanel = new Panel();
		Panel centerPanel = new Panel();
		
		MenuBar mb = new MenuBar();
		Menu m =new Menu("menu");
		m.add(new MenuItem("1"));
		m.add(new MenuItem("2"));
		m.add(new MenuItem("3"));
		m.add(new MenuItem("-"));
		
		MenuItem fileMenuItem = new MenuItem(FILEDIALOGMENUITEM);
		fileMenuItem.addActionListener(this);
		m.add(fileMenuItem);
		mb.add(m);
		setMenuBar(mb);
		
		//在窗口底部摆放一个panel
		bottomPanel.add(new TextField("Textfield"));
		bottomPanel.add(new Button("Button"));
		bottomPanel.add(new Checkbox("Checkbox"));
		Choice c = new Choice();
		c.add("11");
		c.add("22");
		c.add("33");
		bottomPanel.add(c);
		add("South",bottomPanel);
		
		//在窗口中间摆放一个panel
		centerPanel.setLayout(new GridLayout(1,2));
		centerPanel.add(new myCanvas());
		Panel p = new Panel();
		p.add("North",new Label("Label",Label.CENTER));
		p.add("Center",new TextArea("TextArea",5,20));
		centerPanel.add(p);
		add("Center",centerPanel);
		
		//在窗口右侧摆放list
		List l = new List(3,false);
		for(int i =1; i<=10; i++)
		   l.add(""+i+i+i);
		add("East",l);
		
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e)
			{
				  dispose();
			}
		    });//setDefaultCloseOperation(Frame.CLOSE_ON_EXIT);
		
	}
	
	public void actionPerformed(ActionEvent e)
	{
		FileDialog fd = new FileDialog(this,"Dialog");
		fd.setVisible(true);
	}
}

class myCanvas extends Canvas
	{
		public void paint(Graphics g)
		{
			int w = getSize().width;
		    int h = getSize().height;
		    g.drawRect(0,0,w-1,h-1);
		    g.drawString("Canvas",(w - g.getFontMetrics().stringWidth("Canvas"))/2,10);
		    g.setFont(new Font("Helvetica",Font.PLAIN,8));
		    g.drawLine(10,10,100,100);
		    g.fillRect(9,9,3,3);
		    g.drawString("(10,10)",13,10);
		    g.fillRect(49,49,3,3);
		    g.drawString("(50,50)",53,50);
		    g.fillRect(99,99,3,3);
		    g.drawString("(100,100)",103,100);
		}
	}