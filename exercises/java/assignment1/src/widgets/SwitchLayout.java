
package widgets;

import java.awt.CardLayout;
import javax.swing.*;

public class SwitchLayout extends WidgetGroup {
  public SwitchLayout() {
    jwidget = new JPanel();
    jwidget.setLayout(new CardLayout());
  }
  
  public void switchTo(String s) {
    CardLayout cl = (CardLayout) (jwidget.getLayout());
    cl.show(jwidget, s);
  }  
}
