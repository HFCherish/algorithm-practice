
package widgets;

/**
 * Base class for composite widgets.
 * 
 * <p> A WidgetGroup packs a number of smaller widgets into one 
 * big widget.  Every window has a single <i> root widget </i>, which
 * contains all of the buttons, labels, fields, etc. which are displayed
 * in that window.  The smaller widgets within a WidgetGroup are called
 * its <i> children. </i>
 * 
 * <p> A WidgetGroup is responsible for laying out all of its children
 * into rows and columns.  Complex layouts can be created by packing
 * rows into columns of rows (i.e. a grid) and so on.  The {@link VLayout}
 * and {@link HLayout} classes provide concrete implementations of 
 * WidgetGroup.      
 * 
 * <p> Here's an example which creates the keypad of a calculator:
 <code>
        VLayout digits1 = new VLayout();
        digits1.add(new DigitButton("7"));
        digits1.add(new DigitButton("4"));
        digits1.add(new DigitButton("1"));
        digits1.add(new DigitButton("0"));
        
        VLayout digits2 = new VLayout();
        digits2.add(new DigitButton("8"));
        digits2.add(new DigitButton("5"));
        digits2.add(new DigitButton("2"));
        digits2.add(new Button(" "));
        
        VLayout digits3 = new VLayout();
        digits3.add(new DigitButton("9"));
        digits3.add(new DigitButton("6"));
        digits3.add(new DigitButton("3"));
        digits3.add(new EqualsButton());
        
        VLayout ops = new VLayout();
        ops.add(new OperatorButton("+", AddOp));
        ops.add(new OperatorButton("-", SubtractOp));
        ops.add(new OperatorButton("*", MultiplyOp));
        ops.add(new OperatorButton("/", DivideOp));
        
        HLayout buttons = new HLayout();
        buttons.add(digits1);
        buttons.add(digits2);
        buttons.add(digits3);
        buttons.add(ops);
                
        numField = new NumberField(0);
        
        VLayout root = new VLayout();
        root.add(numField);
        root.add(buttons);  
 </code>
 * @see HLayout
 * @see VLayout
 */

public abstract class WidgetGroup extends Widget {     
    /**
     * Adds a new child 
     */
    public void add(Widget w) {
      if (w.jwidget != null) jwidget.add(w.jwidget);     
    }
    
    /**
     * Adds a new child with the given name.
     */
    public void add(Widget w, String name) {
      if (w.jwidget != null) jwidget.add(w.jwidget, name);
    }
}
