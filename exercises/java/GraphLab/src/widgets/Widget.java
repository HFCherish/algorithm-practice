
package widgets;
import javax.swing.*;

public class Widget { 	
  
  /**
   * Constructs a new widget
   */
  public Widget() { }
  
  /**
   * Override to respond to mouse movements.
   * The mouseMoved() method is triggered whenever the mouse moves within this 
   * widget.  It is not triggered by mouse movements outside of this widget.
   */
  public void mouseMoved  (double x, double y) { }
  
  /**
   * Override to respond to mouse clicks.
   * The mouseClicked() method is triggered whenever the mouse is clicked
   * within this widget.  
   * 
   * @param x       X-coordinate of the mouse when the click occured
   * @param y       Y-coordinate of the mouse when the click occured
   * @param button  which button was clicked:  left = 1, middle = 2, right = 3
   * @param nclicks the number of clicks: single = 1, double = 2, triple = 3
   */
  public void mouseClicked(double x, double y, int button, int nclicks) { }
  
  /**
   * Override to respond to mouse drag events.
   * The mouseDragged() method is triggered whenever the mouse is dragged 
   * within this widget -- i.e. when it is moved with one of the buttons 
   * held down.
   */
  public void mouseDragged(double x, double y) { }
  
  /**
   * Override to repond when the mouse moves into this widget. 
   */
  public void mouseEnter() { }
  
  /**
   * Override to respond when the mouse moves out of this widget.
   */
  public void mouseLeave() { }
    
  /**
   * Override to respond when a key is pressed on the keyboard.
   * The keyTyped() method is only triggered when this widget has keyboard focus.
   */
  public void keyTyped(char key) { }
  
  
  /**
   * Returns the width of this widget in local coordinates.
   */
  public double getWidth()  { return jwidget.getWidth();  }
  
  /**
   * Returns the height of this widget in local coordinates.
   */
  public double getHeight() { return jwidget.getHeight(); }
  
  /**
   * Forces java to redraw this widget.
   * The redraw() command should be used whenever the information being displayed
   * by this widget has changed, and the widget needs to be redrawn on the screen.
   */
  public void redraw() {
    if (jwidget != null) jwidget.repaint();        
  }
        
  /*=================================
   * Internal fields -- ignore these 
   *=================================*/
 
  /** For internal use only. */
  public JComponent jwidget = null;  
  WEventBridge      ebridge = null;
    
  /** @deprecated */
  public Widget(JComponent jc, WEventBridge eb) {
    this.jwidget = jc;
    this.ebridge = eb;
  }
  
  void setJWidget(JComponent jc, WEventBridge eb) {
    this.jwidget = jc;
    this.ebridge = eb;
  }
  
  double getLocalXCoord(int x) { return x; }
  double getLocalYCoord(int y) { return jwidget.getHeight() - y; }
}
