
package widgets;

import java.awt.*;

/**
 * Draws graphics to the screen.
 * 
 * <p> A GraphicPen is used to draw graphics to the screen.  There is no
 * way to create a GraphicPen by hand.  The windowing system controls 
 * when and where graphics can be drawn.  
 * 
 * A {@link Canvas} widget receives a GraphicPen as an argument to its draw() 
 * method.  That pen can then be used to draw upon the canvas.
 * 
 * @see Canvas
 */

public class GraphicPen {
       
    /**
     * Sets the drawing color.  All subsequent commands will use that color.
     */
    public void setColor(Color c) {
        g2.setColor(c);
    }
   
    /**
     * Sets the current line width, in pixels.  All subsequent lines, circles, etc. 
     * will be drawn in the given width.
     */
    public void setLineWidth(double width) {
        g2.setStroke(new BasicStroke((float) width)); 
    }
   
    /**
     * Draws a single pixel at point (x,y) 
     */
    public void drawPoint(double x, double y) { 
        g2.drawLine(toXpix(x), toYpix(y), toXpix(x), toYpix(y));
    }   
   
    /**
     * Draws a small circle at point (x,y)
     */
    public void drawDot(double x, double y) {
        g2.drawOval(toXpix(x)-2, toYpix(y)-2, 4, 4);
    }
    
    /**
     * Draws a line from point (x1,y1) to point (x2,y2)
     */
    public void drawLine(double x1, double y1, double x2, double y2) {
        g2.drawLine(toXpix(x1), toYpix(y1), toXpix(x2), toYpix(y2));
    }
    
    /**
     * Draws a rectangle from point (x1,y1) to point (x2,y2)
     */
    public void drawRect(double x1, double y1, double x2, double y2) {
        g2.drawRect(toXpix(x1), toYpix(y1)-toYdim(y2-y1), toXdim(x2-x1), toYdim(y2-y1));                    
    }
    
    /**
     * Draws a filled rectangle from point (x1,y1) to point (x2,y2)
     */
    public void fillRect(double x1, double y1, double x2, double y2) {
        g2.fillRect(toXpix(x1), toYpix(y1)-toYdim(y2-y1), toXdim(x2-x1), toYdim(y2-y1));                    
    }
    
    /**
     * Draws a circle at position (x,y) with radius r
     */
    public void drawCircle(double x, double y, double r) {
        int rx = toXdim(r);
        int ry = toYdim(r);
        g2.drawOval(toXpix(x)-rx, toYpix(y)-ry, rx*2, ry*2);
    }
    
    /**
     * Draws a circle at position (x,y) with radius r
     */
    public void fillCircle(double x, double y, double r) {
        int rx = toXdim(r);
        int ry = toYdim(r);
        g2.fillOval(toXpix(x)-rx, toYpix(y)-ry, rx*2, ry*2);
    }
    
    /**
     * Draws an arc.  
     * An arc is defined as a portion of an ellipse.  
     * 
     * @param x            x coordinate of the center of the ellipse
     * @param y            y coordinate of the center of the ellipse
     * @param xrad         x-radius (half the width)
     * @param yrad         y-radius (half the height)
     * @param startAngle   starting angle, in degrees
     * @param endAngle     ending angle, in degrees
     */
    public void drawArc(double x, double y, double xrad, double yrad, 
                        double startAngle, double endAngle) {
        int rx = toXdim(xrad);
        int ry = toYdim(yrad);
        g2.drawArc((int) toXpix(x)-rx, toYpix(y)-ry, rx*2, ry*2, 
                   (int) startAngle, (int) endAngle);
    }
    
    /*========================================
     * internal methods and fields -- ignore
     *========================================*/
    
    double xmin, ymin;
    int    xsize, ysize;
    double xscale, yscale;
    public Graphics2D  g2;
   
    GraphicPen(Graphics2D g, int xs, int ys, 
               double xmn, double ymn, double xmx, double ymx) 
    {
        g2 = g;
        setScale(xs,ys,xmn,ymn,xmx,ymx);
    }
      
    void setScale(int xs, int ys, double xmn, double ymn, double xmx, double ymx) {
        xmin   = xmn;
        ymin   = ymn;
        xsize  = xs;
        ysize  = ys;
        xscale = xs/(xmx-xmn);
        yscale = ys/(ymx-ymn);
    }
    
    int toXpix(double x) {
        return (int) Math.round((x - xmin)*xscale);
    }
    
    int toYpix(double x) {
        return ysize - (int) Math.round((x - xmin)*yscale);
    }
    
    int toXdim(double xd) {
        return (int) Math.round(xd*xscale);
    }
    
    int toYdim(double yd) {
        return (int) Math.round(yd*yscale);
    }
}
