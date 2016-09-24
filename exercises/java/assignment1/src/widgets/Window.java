package widgets;

import java.awt.event.*;
import javax.swing.JFrame;


/****************************************
 * Represents a window on the screen.
 * 
 * <p> A window has a title and a location on the screen.  A window
 * also contains a single {@link Widget} which holds the entire GUI for 
 * that window.
 * 
 * <p> Subclasses of Window must override buildGUI() to construct the 
 * 
 */

abstract public class Window implements WindowListener {
    private String  title      = "";
    private int     xpos       = 0;
    private int     ypos       = 0;
    public  JFrame  jframe     = null;
    public  Widget  rootWidget = null; 
        
    /**
     * Create a new window with the given title.
     */
    public Window(String title) { 
      this.title = title;
    }
    
    /**
     * Create a new window with the given title and position.
     * The position (xp, yp) is given in screen coordinates.  
     * @see Window#setLocation
     */
    public Window(String title, int xp, int yp) { 
      this.title = title;
      xpos = xp;
      ypos = yp;
    }
        
    /**
     * Override to build a widget for this window.
     * The widget fills the entire window.  
     */
    abstract public Widget buildGUI();
    
    /**
     * Override to perform final initialization right before the window is shown
     * for the first time. 
     */
    public void initWindow() { }
    
    /**
     * Show the window.  
     * The GUI for a window is built the first time it is shown.
     */
    public void show() {
      if (rootWidget == null) {
          rootWidget = buildGUI();
          if (rootWidget == null) return;
      }
      if (jframe == null) {        
          jframe = new JFrame(title);
          if (xpos > 0 || ypos > 0) jframe.setLocation(xpos, ypos);
          jframe.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
          jframe.addWindowListener(this);
          jframe.getContentPane().add(rootWidget.jwidget);
          initWindow();
          jframe.pack();
      }      
      jframe.setVisible(true);
    }
    
    /**
     * Hide (i.e. iconify) the window.  
     * A subsequent call to show() will restore it.
     */
    public void hide() {
      if (jframe != null) jframe.setVisible(false);
    }
    
    /**
     * Set the location of this window to screen coordinates (x,y).
     * Screen coordinates are measured in pixels.  The point (0,0)
     * is at the top left-hand corner of the screen, and y-values 
     * increase going down.  
     */
    public void setLocation(int x, int y) {
      if (jframe == null) {
        xpos = x;
        ypos = y;
      }
      else jframe.setLocation(x,y);
    }
    
    /**
     * Set the title of this window.
     */
    public void setTitle(String title) {
      this.title = title;
      if (jframe != null) {
        jframe.setTitle(title);
      }
    }
    
       
    /** @deprecated */
    public void windowClosing(WindowEvent e) {
        jframe     = null;
        rootWidget = null;
    }
    
    /** @deprecated */
    public void  windowActivated  (WindowEvent e) { }    
    /** @deprecated */
    public void  windowClosed     (WindowEvent e) { }
    /** @deprecated */
    public void  windowDeactivated(WindowEvent e) { }
    /** @deprecated */
    public void  windowDeiconified(WindowEvent e) { }
    /** @deprecated */
    public void  windowIconified  (WindowEvent e) { }
    /** @deprecated */
    public void  windowOpened     (WindowEvent e) { }
}
