
package widgets;

import javax.swing.*;
import java.awt.event.*;

/**
 * GUIApp represents a typical application with a graphical user interface.
 * It starts up the java event loop, and opens up a single main window.
 * Subclasses of GUIApp must implement buildGUI() to construct the contents
 * of the main window.  
 * 
 * Subclasses of GUIApp must also supply a main() method which instantiates
 * the application object, and then calls startApplication(), as shown in
 * the example below.
 * 
 <code>
 class GUIMain extends GUIapp {
    ...
    public static void main(String[] args) {
        startApplication(new GUIMain());
    } 
 }
 </code>
 * 
 */

public abstract class GUIApp {
  public Window mainWindow = null;

  /**
   * Starts the application.
   * This method should be called from within main().
   */
  public static void startApplication(GUIApp app) {    
    javax.swing.SwingUtilities.invokeLater(new StarterThread(app));
  }
    
  /**
   * Creates a new application.
   * The application will open a main window with the given title.
   */
  public GUIApp(String title) {
    mainWindow = new MainWindow(title, this);
  }        
    
  /**
   * Override to initialize the application.
   * init() is triggered immediately after the main window is created.  
   */
  public void init() { }
    
  /**
   * Override to create the widget for the main window.
   */
  public abstract Widget buildGUI(); 
    
  /**
   * Override to perform final initialization right before the window is shown
   * for the first time. 
   */
  public void initWindow() { }
  
  /**
   * Override to perform cleanup before the application exits.
   */    
  public void close() { }
}


class StarterThread implements Runnable {
  GUIApp app = null;
  
  StarterThread(GUIApp a) {
    app = a;
  }
  
  public void run() {
    // make sure we have a decent GUI
    JFrame.setDefaultLookAndFeelDecorated(false);           
    app.mainWindow.show(); 
    app.init();
  }
}  


class MainWindow extends Window {
  GUIApp app = null;
      
  MainWindow(String title, GUIApp a) {
    super(title);
    app = a;
  }

  public Widget buildGUI() {
    return app.buildGUI();
  }
  public void initWindow() {
    app.initWindow();
  }
  
  public void  windowClosing(WindowEvent e) {
    app.close();
    jframe.dispose();
    System.exit(0);
  } 
}

