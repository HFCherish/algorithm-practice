
package widgets;

/**
 * A Control is a widget which performs actions.
 * Many widgets, including {@link Button}s, {@link CheckBox}es, and {@link TextField}s, 
 * perform actions in response to the user.  A button performs an action when it is
 * clicked, and a Checkbox performs an action when the user checks or unchecks the box. 
 */
public abstract class Control extends Widget {         
    /**
     * Override to perform an action.
     */
    public void doAction() { }
}
