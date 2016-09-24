
package widgets;

import javax.swing.*;

/**
 * A single line of editable text.
 * 
 * <p> A TextField is a box containing a single line of text which can 
 * be edited by the user.  It is typically used as a blank box into which
 * the user can type textual information, such as names, addresses, etc.  
 * An action is triggered whenever the user enters a different piece of text.
 */
public class TextField extends Control {
    /**
     * Create a new TextField, which will initially hold the given string.
     * The width of the TextField is calculated from the string.
     */
    public TextField(String str) { 
        JTextField f = new JTextField(str);        
        this.jwidget = f;
        this.ebridge = new WEventBridge(f, this, WEventBridge.TEXTFIELD_ACTION);        
    }
    
    /**
     * Create a new TextField with the given width.
     * A TextField must be wide enough so that the user has space to type
     * information into the field.    
     * 
     * @param str      The string that the field will initially hold.
     * @param columns  The width of the field in characters.   
     */
    public TextField(String str, int columns) {
        JTextField f = new JTextField(str, columns);
        this.jwidget = f;
        this.ebridge = new WEventBridge(f, this, WEventBridge.TEXTFIELD_ACTION);        
    }        
    
    /**
     * Gets the current text in the field.
     */
    public String getText() {
        return ((JTextField) this.jwidget).getText();
    }
    
    /**
     * Sets the current text in the field.
     * Calling setText() will not trigger an action.  
     */
    public void setText(String str) {
        ((JTextField) this.jwidget).setText(str);
    }   
}
