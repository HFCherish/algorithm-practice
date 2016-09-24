import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

public class BouncePanel extends JComponent 
                         implements ComponentListener, Runnable {
	
	final static long serialVersionUID = 0;  // kill warning
	
    // constants
    final static BasicStroke stroke = new BasicStroke(2.0f);
      
    // fields
    float xsize,ysize;  // size of window
    float xpos,ypos;    // position of ball 
    float xlen,ylen;    // size of ball
    float speed;        // distance the ball moves in each frame
    float dx,dy;        // current speed + direction of ball 
    
    int    delay;       // delay between frames in miliseconds
    Thread animThread;  // animation thread                       
                
    /*************************************************
     * Draws the ball on the screen.
     *************************************************/                                
    public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g.create();
        
        // get the current window size     
        Dimension dim = getSize();
        xsize = dim.width;
        ysize = dim.height; 
        
        // clear background to white
        g2.setPaint(Color.white);
        g2.fill(new Rectangle2D.Double(0,0,xsize,ysize));       
                
        // draw ball                 
        g2.setPaint(Color.red);
        g2.fill(new Ellipse2D.Double(xpos, ysize-ypos-ylen, xlen, ylen));
        g2.setColor(Color.black);
        g2.draw(new Ellipse2D.Double(xpos, ysize-ypos-ylen, xlen, ylen));
 
        g2.dispose();
    }
    
    // empty methods that are required by the GUI event loop
    public void componentHidden (ComponentEvent e)  { }
    public void componentMoved  (ComponentEvent e)  { }
    public void componentResized(ComponentEvent e)  { }
    public void componentShown  (ComponentEvent e)  { }
    
    /****************************************************
     * Checks to see if the ball has hit any walls.
     * Called from within run(). 
     ****************************************************/
    public void checkWalls() {
       if (xpos + xlen >= xsize) { 
           xpos = xsize - xlen;
           dx   = -dx;
       } 
       if (xpos < 0) {
           xpos = 0;
           dx   = -dx; 
       } 
       if (ypos + ylen >= ysize) {
           ypos = ysize - ylen;
           dy   = -dy;
       }             
       if (ypos < 0) {
           ypos = 0;
           dy   = -dy;
       }
    }
    
    /***********************************************************
     * This is the animation thread.  
     * The code here is what actually causes the ball to bounce.
     ***********************************************************/ 
    public void run() {
      while (true) {  // loop forever          
        // update position
        xpos += dx;
        ypos += dy;
                
        // check to see if the ball has hit any walls
        checkWalls();
            
        // sleep a bit until the next frame
        try { Thread.sleep(delay); } 
        catch (InterruptedException e) { break; }
        
        // refresh the display
        repaint();  
      }
    }
        
    /****************************************************
     * This is a constructor for the BouncePanel class.
     * It initializes all the values that the class needs
     * in order to work properly.
     ****************************************************/
    
    public BouncePanel() {
        // set values for all the variables
        xsize = 480;
        ysize = 360;
        xpos  = 240;
        ypos  = 180;
        xlen  = 60;
        ylen  = 60;
        speed = 5;
        dx    = speed;
        dy    = speed;
        delay = 10;
        
        // set up window properties
        setBackground(Color.white);
        setOpaque(true);
        setPreferredSize(new Dimension((int) xsize, (int) ysize));
        setFocusable(true);
        addComponentListener(this);
        
        // start the animation thread
        animThread = new Thread(this);
        animThread.start();
    }
}
