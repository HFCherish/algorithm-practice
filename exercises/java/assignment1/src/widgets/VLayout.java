
package widgets;

import javax.swing.*;

/**
 * A vertical column of widgets.
 * 
 * <p> A VLayout is a container for other widgets.  
 * It will lay out all of its children into a vertical column.
 * 
 * @see WidgetGroup
 */

public class VLayout extends WidgetGroup {
    public VLayout() {        
        jwidget = new JPanel();
        jwidget.setLayout(new BoxLayout(jwidget, BoxLayout.Y_AXIS));
    }
}
