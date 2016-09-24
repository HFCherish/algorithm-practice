
package widgets;

import java.awt.Font;
import javax.swing.*;

/**
 * Multiple lines of text, which may or may not be editable.
 * 
 * <p> A TextArea is much like a text label, except that it displays multiple lines 
 * of text.  The text may be editable or not, as needed.  An uneditable TextArea
 * is much like a mult-line {@link TextLabel}.  An editable TextArea is much like
 * a multi-line {@link TextField}.
 * 
 * <p> A TextArea will automatically scroll if it attempts to display more text 
 * than will fit in the TextArea.
 */

public class TextArea extends Widget {
	  final static Font textFont = new Font("Serif", Font.PLAIN, 16);
    public JTextArea jtext;
        
    /**
     * Creates an uneditable TextArea with the given initial string.
     * The size of the TextArea will be calculated from the string.
     */
    public TextArea(String str) {
        jtext = new JTextArea(str);
        jtext.setFont(textFont);
        jtext.setLineWrap(false);
        jtext.setEditable(false);        
        this.jwidget = new JScrollPane(jtext);    
    }
        
    /**
     * Creates an uneditable TextArea with the given width and height.
     * 
     * @param str      the text to initially show in this TextArea
     * @param rows     the number of lines of text 
     * @param columns  the number of characters per line
     */    
    public TextArea(String str, int rows, int columns) {
        this(str, rows, columns, false);       
    }
        
    /**
     * Creates an uneditable TextArea with the given width and height.
     * 
     * @param str      the text to initially show in this TextArea
     * @param rows     the number of lines of text 
     * @param columns  the number of characters per line
     * @param edit     if edit is true, the text area will be editable
     */    
    public TextArea(String str, int rows, int columns, boolean edit) {
        jtext = new JTextArea(str, rows, columns);
        jtext.setFont(textFont);
        jtext.setLineWrap(false);
        jtext.setEditable(edit);
        this.jwidget = new JScrollPane(jtext);        
    }
    
            
    /**
     * Gets the current text in the TextArea.
     */
    public String getText() {        
        return jtext.getText();
    }
    
    /**
     * Sets the text in the TextArea to str.
     */
    public void setText(String str) {        
        jtext.setText(str); 
    }   
    
    /**
     * Appends a string of text to the bottom of the TextArea.
     */
    public void append(String str) {      
        jtext.append(str);
    }
    
    /**
     * Clears all text in the TextArea.
     */
    public void clearText() {       
       setText("");   
    }
    
    /**
     * Gets the number of lines of text currently displayed, which
     * may be either shorter or longer than the height of the TextArea.
     */
    public int getNumLines() {
        return jtext.getLineCount();
    }
    
    /**
     * Gets the height of the TextArea, in lines of text.
     */
    public int getRows() {
        return jtext.getRows();  
    }
    
    /**
     * Gets the width of the TextArea in characters.
     */
    public int getColumns() {
        return jtext.getColumns();
    }    
}
