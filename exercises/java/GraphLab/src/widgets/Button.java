
package widgets;

import javax.swing.*;


/**
 * A button which can be clicked.
 * 
 * <p> A Button is a box which surrounds a string of text. 
 * An action is triggered whenever the button is clicked.
 */
public class Button extends Control {        
    /**
     * Constructs a new button with the given text.
     */
    public Button(String str) { 
        JButton b    = new JButton(str);
        this.jwidget = b;
        this.ebridge = new WEventBridge(b, this, WEventBridge.BUTTON_ACTION);        
    }    
    
    /**
     * Get the text of this button.
     */
    public String getText() {
        return ((JButton) this.jwidget).getText();
    }
    
    /**
     * Set the text of this button. 
     */
    public void setText(String str) {
        ((JButton) this.jwidget).setText(str);
    }   
}
