
package widgets;

import java.awt.event.*;
import javax.swing.*;

class WEventBridge implements ComponentListener, 
                              MouseListener,
                              MouseMotionListener,
                              KeyListener,
                              ActionListener,
                              FocusListener
{   
    static final int NO_ACTIONS       = 0;
    static final int BUTTON_ACTION    = 1;
    static final int TEXTFIELD_ACTION = 2;
 
    JComponent jsource;        // Java component (event source)
    Widget     targetWidget;   // Widget object  (event target)    
    boolean    doesActions;    // how does it handle actions?
 
    WEventBridge(JComponent jc, Widget w) {
        jsource      = jc;
        targetWidget = w;
        doesActions  = false;
        
        jc.addComponentListener(this);
        jc.addMouseListener(this);
        jc.addMouseMotionListener(this);
        jc.addKeyListener(this);                
    }
    
    WEventBridge(JComponent jc, Widget w, int act) {
        jsource      = jc;
        targetWidget = w;
        
        if (act == BUTTON_ACTION || act == TEXTFIELD_ACTION)
           doesActions = true;
        
        jc.addComponentListener(this);
        jc.addMouseListener(this);
        jc.addMouseMotionListener(this);
        jc.addKeyListener(this);
        
        if (act == BUTTON_ACTION) {
            ((AbstractButton) jc).addActionListener(this);
        }
        else if (act == TEXTFIELD_ACTION) {
            ((JTextField) jc).addActionListener(this);
            // make sure we call doAction when losing keyboard focus
            ((JTextField) jc).addFocusListener(this);
        }
    }
  
    
    public void actionPerformed(ActionEvent e) {
      if (doesActions) ((Control) targetWidget).doAction();
    }
    public void focusGained(FocusEvent e) { }
    public void focusLost  (FocusEvent e) {
      if (doesActions) ((Control) targetWidget).doAction();
    }
    
    // empty methods that are required by the GUI event loop
    public void componentHidden (ComponentEvent e)  { }        
    public void componentShown  (ComponentEvent e)  { }               
    public void componentMoved  (ComponentEvent e)  { }
    public void componentResized(ComponentEvent e)  { }  
    
    // mouse methods        
    public void mouseClicked (MouseEvent e) {
        int b = 0;
        if (e.getButton() == MouseEvent.BUTTON1) b = 1;
        if (e.getButton() == MouseEvent.BUTTON2) b = 2;
        if (e.getButton() == MouseEvent.BUTTON3) b = 3;
        
        targetWidget.mouseClicked(targetWidget.getLocalXCoord(e.getX()), 
                                  targetWidget.getLocalYCoord(e.getY()),            
                                  b, e.getClickCount());         
    }     
    
    public void mouseMoved(MouseEvent e) {
        targetWidget.mouseMoved(targetWidget.getLocalXCoord(e.getX()), 
                                targetWidget.getLocalYCoord(e.getY()));          
    }
          
    public void mouseDragged (MouseEvent e) {       
        targetWidget.mouseDragged(targetWidget.getLocalXCoord(e.getX()), 
                                 targetWidget.getLocalYCoord(e.getY()));
    }
    
    public void mouseEntered (MouseEvent e) {
        targetWidget.mouseEnter(); 
    }
     
    public void mouseExited  (MouseEvent e) {
        targetWidget.mouseLeave(); 
    } 
    
    public void keyTyped(KeyEvent e) {       
        targetWidget.keyTyped(e.getKeyChar());
    }
    
    // more empty methods
    public void mousePressed (MouseEvent e) { } 
    public void mouseReleased(MouseEvent e) { }
    
    
    public void keyPressed (KeyEvent e) { }
    public void keyReleased(KeyEvent e) { }
}
