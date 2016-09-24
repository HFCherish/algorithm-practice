
import java.awt.Color;
import widgets.*;

class GraphCanvas extends Canvas implements Runnable {
         
    /*---------------
     * Problem 1:
     *---------------*/
    void drawWeb(GraphicPen g) 
    {

        for(double i=-8; i<=8; i++)
        {
            g.setColor(Color.pink);
        	g.drawLine(-8, i, -i, -8);
        	g.drawLine(8, i, -i, 8);
        }// TODO -- put your code here
    }
  
    
    /*---------------
     * Problem 2:
     *---------------*/
    void drawHatch(GraphicPen g) 
    {
        for(double i=-8,j=1; i<8; i+=0.02*j,j++)
        {
        	g.setColor(Color.blue);
        	g.drawLine(-8, i, 8, i);
        	g.drawLine(i, -8, i, 8);
        }// TODO -- put your code here
    }        
  
    
    /*----------------
     * Problem 3:
     *----------------*/            
    void drawCircles(GraphicPen g) { 
        double x,y,r;
    	g.setColor(Color.gray);
        for(double i=0; i<1.5; i+=0.5)
        	for(double j=-6.5-i; j<=6.5+i; j+=0.5)
        	{
        		x = j;   y=-8+i;
        		r = 0.33 - Math.sqrt(x*x + y*y)/33;
        		g.fillCircle(x, y, r);
        		g.fillCircle(x, -y, r);
        	}
        for(double i=-8; i<=8; i+=0.5)
        	for(double j=-6.5; j<=6.5; j+=0.5)
        	{
        		x = i;   y = j;
        		r = 0.33 -Math.sqrt(x*x + y*y)/33;
        		g.fillCircle(x, y, r);
        	}
    	// TODO -- put your code here  
    }
      
      
    /*-----------------
     * Problem 4:
     *-----------------*/
    double blobTime = 0;
    int    numBlobs = 8;
    
    void drawBlob(GraphicPen g) 
    {
        double blobiness = Math.cos(blobTime*Math.PI/180);         
        for(double radius=1; radius<=8; radius++)
        {
        	double oldx = polarX(radius,0), oldy = polarY(radius,0),x,y; 
        	for(double a=0; a<=360; a+=2)
        	{
        		double r = radius + blobiness * Math.sin(numBlobs*a*Math.PI/180);
        		x = polarX(r,a);
        		y = polarY(r,a);
        		g.setColor(Color.magenta);
        		g.drawLine(oldx, oldy, x, y);
        		oldx = x;
        		oldy = y;
        	}
        }
      // TODO -- put your code here
    }
    
	
    /*---------------
     * Problem 5:
     *---------------*/
    void drawFractCross(GraphicPen g) {
      fractCross(g, 6, 0, 0, 16);
    }
    
    void fractCross(GraphicPen g, int level, double x, double y, double width) {
        double a = width/2; 
    	g.setColor(Color.green);
         if(level == 0)
         {
        	 g.drawLine(x-a, y-a, x+a, y+a);
        	 g.drawLine(x-a, y+a, x+a, y-a);
        	 return;
         }
         double b = width/3;
         level--;
         fractCross(g, level, x, y, b);
         fractCross(g, level, x-b, y-b, b);
         fractCross(g, level, x-b, y+b, b);
         fractCross(g, level, x+b, y-b, b);
         fractCross(g, level, x+b, y+b, b);
         // TODO -- put your code here       
    }
    
    
    /*---------------
     * Problem 6:
     *---------------*/
    void drawMarble(GraphicPen g) {
      marble(g, 6, 0, 0, 16, new PreciseColor(0,0,0,1));
    }
    
    void marble(GraphicPen g, int level, double x, double y, double width, PreciseColor pcolor) 
    {
         double a = width/2;
         if(level == 0)
         {
        	 g.setColor(pcolor.getColor());
        	 g.fillRect(x-a, y-a, x+a, y+a);
        	 return;
         }
         level--;
         double b = width/4;
         pcolor = pcolor.blend(Color.yellow, 0.5);  //浅色区
         marble(g, level, x-b, y+b, a, pcolor);
         marble(g, level, x+b, y-b, a, pcolor);
         pcolor = pcolor.blend(Color.MAGENTA, 0.5);  //pcolor = pcolor.blend(Color.yellow, 0.5);//重色区
         marble(g, level, x-b, y-b, a, pcolor);
         marble(g, level, x+b, y+b, a, pcolor);
         // TODO -- put your code here
    }
    
    
    /*----------------
     * Problem 7:
     *----------------*/
    double  numSmaller   = 8;
    double  smallSize    = 0.18;
    double  radiusDec    = 0.7;
    double  twist        = 20;

    Color[] armColors = { Color.red,    Color.black, 
                          Color.yellow, Color.black,
                          Color.green,  Color.black,  
                          Color.blue,   Color.black  };     
                         
    
    void drawFractSpiral(GraphicPen g) {
      fractSpiral(g, 0, 0, 8, new PreciseColor(0,0,0,1));
    }
    
    void fractSpiral(GraphicPen g, double x, double y, double radius, PreciseColor pcolor) 
    {
      double pixSize = getXPixelSize()*0.75;
      
      // TODO -- put your code here
    }
   
        
    /*-------------
     * Problem 8:
     *-------------*/
    
    void animateBlob() {      
      while (animate && whatDraw == DrawBlob) {          
        redraw();     // redraw the picture
        delay(30);    // pause for 200 miliseconds; wait until drawing is complete
        GraphicPen g = new GraphicPen();
        drawBlob(g);
        blobTime += 2;
      }
      blobTime = 0;   // reset blobTime to initial value 
    }
    
    void animateFractSpiral() {    	  
    	while (animate && whatDraw == DrawFractSpiral) {    		
        redraw();    // redraw the picture
        delay(200);  // pause for 200 miliseconds; wait until drawing is complete
    	}
      twist = 20;    // reset twist to initial value
    }    
    
    /****************************
     * Bonus Question
     ****************************/
    
    int     whatDraw = 0;      // what do we draw?
    boolean animate  = false;  // should we animate it?
    
    void animateWeb() {
      while (animate && whatDraw == DrawWeb) {                
        redraw();
        delay(30);
      }
    }
    
    void animateHatch() {
      while (animate && whatDraw == DrawHatch) {        
        redraw();
        delay(30);
      }
    }
    
    void animateCircles() {       
      while (animate && whatDraw == DrawCircles) {        
        redraw();
        delay(30);
      }
    }
     
    void animateFractCross() {
      while (animate && whatDraw == DrawFractCross) {        
        redraw();
        delay(200);
      }
    }
    
    void animateMarble() {
      while (animate && whatDraw == DrawMarble) {           
        redraw();
        delay(200);
      }
    }
    

    /**********************************
     * Precise colors and color mixing
     **********************************/ 
    
    class PreciseColor {
      double red   = 0.0;
      double green = 0.0;
      double blue  = 0.0;
      double scale = 1.0;    
      
      PreciseColor(double r, double g, double b, double s) {
        red = r; green = g; blue = b; scale = s;
      }
            
      PreciseColor blend(Color ncol, double alpha) {
        double r = red   + scale * alpha * ncol.getRed()/255d;
        double g = green + scale * alpha * ncol.getGreen()/255d;
        double b = blue  + scale * alpha * ncol.getBlue()/255d;
        double s = scale * (1-alpha);
      
        return new PreciseColor(r,g,b,s);
      }    
   
      Color getColor() {
        double co = scale*0.5;
        return new Color((int) (255 * (red   + co)), 
                         (int) (255 * (green + co)), 
                         (int) (255 * (blue  + co)));
      }
    }
    
 /*********************************************************************************
  ********************************************************************************* 
  * GUI Logic.
  * You do not need to read anything below this line.
  ********************************************************************************** 
  *********************************************************************************/    
    
    Thread  animThread;    
    
    GraphCanvas(int xs, int ys) {
        super(xs,ys);
        animThread = new Thread(this);
        animThread.start();
    }
        
    public void draw(GraphicPen g) {   
      g.setColor(Color.black);
      switch (whatDraw) {
        case DrawWeb:          drawWeb(g);         break;       
        case DrawHatch:        drawHatch(g);       break;      
        case DrawCircles:      drawCircles(g);     break;
        case DrawBlob:         drawBlob(g);        break;   
        case DrawFractCross:   drawFractCross(g);  break;                   
        case DrawMarble:       drawMarble(g);      break; 
        case DrawFractSpiral:  drawFractSpiral(g); break;          
      }        
    }
    
    public void run() {
    	while (true) {
        if (animate) {
          switch (whatDraw) {
            case DrawWeb:         animateWeb();         break;
            case DrawHatch:       animateHatch();       break;  
            case DrawCircles:     animateCircles();     break;   
            case DrawBlob:        animateBlob();        break;   
            case DrawFractCross:  animateFractCross();  break; 
            case DrawMarble:      animateMarble();      break; 
            case DrawFractSpiral: animateFractSpiral(); break;
          }
        }
        else { delay(500); }
    	}
    }
    
    public void delay(long ms) {
    	try { Thread.sleep(ms); }
      catch (InterruptedException e) { }
    }
    
    /*****************************
     * Fields and constants 
     *****************************/ 

    static final int DrawWeb         = 1;
    static final int DrawHatch       = 2;
    static final int DrawCircles     = 3;
    static final int DrawBlob        = 4;  
    static final int DrawFractCross  = 5;  
    static final int DrawMarble      = 6;    
    static final int DrawFractSpiral = 7;    
}


public class GraphMain extends GUIApp {	
    GraphCanvas graph = null;
    
	  GraphMain() {
	    super("MyGUI");
    }
    
    class GraphButton extends Button {
      int what = 0;
        
      GraphButton(String s, int w) { super(s); what = w;  }
        
      public void doAction() { graph.whatDraw = what; graph.redraw(); }
    }
        
	  public Widget buildGUI() {
        graph = new GraphCanvas(600, 600);        
                        
        HLayout row1 = new HLayout();
        row1.add(new GraphButton("Web",      GraphCanvas.DrawWeb));
        row1.add(new GraphButton("Hatch",    GraphCanvas.DrawHatch));            
        row1.add(new GraphButton("Circles",  GraphCanvas.DrawCircles));                
        row1.add(new GraphButton("Blob",     GraphCanvas.DrawBlob));
        
        HLayout row2 = new HLayout();
        row2.add(new GraphButton("FractCross",  GraphCanvas.DrawFractCross));        
        row2.add(new GraphButton("Marble",      GraphCanvas.DrawMarble));        
        row2.add(new GraphButton("FractSpiral", GraphCanvas.DrawFractSpiral));
       
        VLayout buttons = new VLayout();
        buttons.add(row1);
        buttons.add(row2);
        
        HLayout controls = new HLayout();
        controls.add(buttons);
        controls.add(new CheckBox("Animate", false) {
          public void doAction() { 
            graph.animate = isChecked();
            graph.animThread.interrupt();
          }
        });
                
        VLayout root = new VLayout();
        root.add(controls);
        root.add(graph);                
        return root;
    }
	
	  public static void main(String[] args) {
      startApplication(new GraphMain());
    }   
}
