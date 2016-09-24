
package widgets;

import javax.swing.*;

/**
 * A horizontal row of widgets.
 * 
 * <p> An HLayout is a container for other widgets.  
 * It will lay out all of its children into a horizontal row.
 * 
 * @see WidgetGroup
 */

public class HLayout extends WidgetGroup {    
    public HLayout() { 
        jwidget = new JPanel();
        jwidget.setLayout(new BoxLayout(jwidget, BoxLayout.X_AXIS));
    }
}
