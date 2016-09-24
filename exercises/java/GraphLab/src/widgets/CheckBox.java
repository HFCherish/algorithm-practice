
package widgets;

import javax.swing.*;


/**
 * A box which can be checked or unchecked.
 * 
 * <p> A Checkbox consists of a text label, and a small box which can
 * be checked or unchecked.  An action is triggered whenever the user
 * checks or unchecks the box.
 */
public class CheckBox extends Control {   
    /**
     * Creates a new checkbox.
     * 
     * @param str      string of text to label the check box
     * @param checked  true if the check box is initially checked, false otherwise
     */
    public CheckBox(String str, boolean checked) {
        JCheckBox b  = new JCheckBox(str, checked);
        setJWidget(b, new WEventBridge(b, this, WEventBridge.BUTTON_ACTION));       
    }    
       
    /**
     * Returns true if the checkbox is initially checked, and false otherwise.
     */
    public boolean isChecked() {
        return ((JCheckBox) this.jwidget).isSelected();
    }
    
    /**
     * Set the checkbox to checked if b is true, or unchecked if b is false.
     */
    public void setChecked(boolean b) {
        ((JCheckBox) this.jwidget).setSelected(b);
    }
    
    /**
     * Get the label of this Checkbox.
     */
    public String getText() {
        return ((JCheckBox) this.jwidget).getText();
    }
    
    /**
     * Set the label of this Checkbox.
     */
    public void setText(String str) {
        ((JCheckBox) this.jwidget).setText(str);
    }   
}
