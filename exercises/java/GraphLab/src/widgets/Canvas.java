/************************************************
 * Canvas implements a black widget upon which
 * other pictures can be drawn.
 ************************************************/

package widgets;

import java.awt.*;
import javax.swing.*;


/**
 * A blank widget which can be drawn upon.
 * 
 * <p> A Canvas is a blank box which contains graphics.  Subclasses
 * of Canvas should override the draw() method to draw the appropriate
 * graphics in the box.
 * 
 * <p> Subclasses of Canvas may also override mouseMoved(), mouseClicked()
 * etc. to respond to mouse and keyboard events.  
 */

public class Canvas extends Widget { 
    int           xsize, ysize;             // size of the canvas  (cannot change)
    public double xmin, ymin, xmax, ymax;   // min and max ranges
    public Color  background;               // background color
		
    /**
     * Creates a new canvas with the given coordinate system.
     * By default the X and Y axes range from -10 to 10.
     * 
     * @param xsize  -- the width of the canvas in pixels
     * @param ysize  -- the height of the canvas in pixels
     */
    public Canvas(int xsize, int ysize) {
	      this(xsize, ysize, -10, -10, 10, 10);
    }
		
    /**
     * Creates a new canvas with the given coordinate system.
     * 
     * @param xsize  -- the width of the canvas in pixels
     * @param ysize  -- the height of the canvas in pixels
     * @param xmin  the x-coordinate of the left edge of the canvas.
     * @param xmax  the x-coordinate of the right edge of the canvas.
     * @param ymin  the y-coordinate of the bottom edge of the canvas.
     * @param ymax  the y-coordinate of the top edge of the canvas.
     */    
    public Canvas(int xsize, int ysize, 
                  double xmin, double ymin, 
                  double xmax, double ymax) {
	      this.xsize = xsize;
	      this.ysize = ysize;
	      this.xmin  = xmin;
        this.ymin  = ymin;
        this.xmax  = xmax;
        this.ymax  = ymax;
        background = Color.white;
        
        JComponent jw = new JCanvasComponent(xsize, ysize, this); 
        setJWidget(jw, new WEventBridge(jw, this));
    }
    
    
    /**
     * Override to draw something on this canvas.
     * The GraphicPen can be used to do actual drawing.
     */
    public void draw(GraphicPen g) { }
    
    /**
     * Sets the background color.  The canvas starts out as a blank box
     * with the given color.
     */
    public void setBackground(Color c) {
        background = c;
        redraw();
    }
    
    /**
     * Sets the coordinate system used to draw graphics.
     * 
     * @param xmin  the x-coordinate of the left edge of the canvas.
     * @param xmax  the x-coordinate of the right edge of the canvas.
     * @param ymin  the y-coordinate of the bottom edge of the canvas.
     * @param ymax  the y-coordinate of the top edge of the canvas.
     */
    public void setBounds(double xmin, double ymin, double xmax, double ymax) {
        this.xmin = xmin;
        this.ymin = ymin;
        this.xmax = xmax;
        this.ymax = ymax;
        redraw();
    }
    
    public double getXLength() { return Math.abs(xmax - xmin); }
    public double getYLength() { return Math.abs(ymax - ymin); }
    public double getXSize()   { return xsize; }
    public double getYSize()   { return ysize; }
    
    public double getXPixelSize() { return getXLength()/getXSize(); }
    public double getYPixelSize() { return getYLength()/getYSize(); }  

    /**
     * Returns the cartesian x-coordinate of the given distance and angle.
     * 
     * @param distance  the distance from the origin
     * @param angle     the angle, where the x-axis has angle 0
     */    
    public static double polarX(double distance, double angle) {
        return Math.cos(angle*Math.PI/180)*distance;
    }
        
    /**
     * Returns the cartesian y-coordinate of the given distance and angle.
     * 
     * @param distance  the distance from the origin
     * @param angle     the angle, where the x-axis has angle 0
     */   
    public static double polarY(double distance, double angle) {
        return Math.sin(angle*Math.PI/180)*distance;
    }    
        
    /*================================
     * Internal methods for widget
     *================================*/
    
    double getLocalXCoord(int x) { return x*getXPixelSize() + xmin; }
    double getLocalYCoord(int y) { return (ysize - y)*getYPixelSize() + ymin; }    
}


/**
 * For internal use only.
 */
class JCanvasComponent extends JComponent {
    public final static BasicStroke stroke = new BasicStroke(1.0f);
  
    static final long serialVersionUID = 0;  // kill warning
    Canvas canvas;
    
    JCanvasComponent(int xsize, int ysize, Canvas c) {
        canvas = c;
        setBackground(canvas.background);
        setOpaque(true);
        setPreferredSize(new Dimension((int) xsize, (int) ysize));
        setFocusable(true);
    }
    
    public void paintComponent(Graphics g) {
        // get the current window size     
        Dimension dim = getSize();
        canvas.xsize = dim.width;
        canvas.ysize = dim.height;
                        
        Graphics2D g2 = (Graphics2D) g;
        
        // clear background to white
        g2.setPaint(canvas.background);
        g2.fillRect(0,0, canvas.xsize, canvas.ysize);   
        
        g2.setStroke(stroke);
        g2.setColor(Color.black);
        
        GraphicPen gp = new GraphicPen(g2, canvas.xsize, canvas.ysize,
                                           canvas.xmin,  canvas.ymin,
                                           canvas.xmax,  canvas.ymax);                
        canvas.draw(gp);
    }
}


