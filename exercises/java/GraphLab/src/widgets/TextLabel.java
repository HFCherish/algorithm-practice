
package widgets;

import javax.swing.*;

/**
 * A single line of text which cannot be edited.
 * 
 * <p> A TextLabel is a single line of text, which is typically a word, phrase,
 * or short sentence.  A TextLabel merely displays the text, it does not 
 * respond to the mouse or keyboard.
 */

public class TextLabel extends Widget { 
    /**
     * Creates a new TextLabel which displays the given string.
     */
    public TextLabel(String str) {
        this.jwidget = new JLabel(str);     
    }
    
    /**
     * Gets the text of this label.
     */    
    public String getText() {
        return ((JLabel) jwidget).getText();
    }
    
    /**
     * Sets the text of this label.
     */
    public void setText(String str) {
        ((JLabel) jwidget).setText(str); 
    }
}
