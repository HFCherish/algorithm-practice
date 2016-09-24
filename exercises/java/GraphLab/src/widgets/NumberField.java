
package widgets;

/**
 * A TextField for entering numbers.
 * 
 * <p> A NumberField is a kind of TextField which is specifically intended 
 * for entering integers.  If the user attempts to enter a string that
 * is not a valid integer (such as "xy78$") then it will clear the field.
 */
public class NumberField extends TextField {    
    /**
     * Creates a new NumberField with then given initial number.
     */
    public NumberField(int num) {
        super(String.valueOf(num));      
    }
    
    /**
     * Creates a new NumberField with the given size.
     * 
     * @param num      number which is initially in the field
     * @param columns  width of the field in characters
     */    
    public NumberField(int num, int columns) {
        super(String.valueOf(num), columns);      
    }  
    
    /**
     * Checks to make sure that the user has entered a valid number.
     * If the user has not entered a valid number, then this clears 
     * the NumberField.  
     * 
     * <p> Subclasses which override doAction() should call super.doAction()
     * to retain this functionality.  
     */
    public void doAction() {
        if (!isValidNumber()) setText("");
    }    
        
    /**
     * Returns true if the current text is a valid number, and false otherwise.
     */
    public boolean isValidNumber() {
        boolean v = true;
        
        try {
            Integer.decode(getText());
        }
        catch (NumberFormatException e) {
            v = false;            
        } 
        return v;
    }
    
    /**
     * Returns the number currently in this field.
     */
    public int getNumber() {
        Integer i;
        
        try {
            i = Integer.decode(getText());
        }
        catch (NumberFormatException e) {
            setText("");
            return 0;
        }        
        return i.intValue();
    }
    
    /**
     * Sets the number in this NumberField.
     */
    public void setNumber(int n) {
        setText(String.valueOf(n));
    }    
}
