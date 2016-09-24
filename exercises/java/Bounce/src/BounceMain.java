import javax.swing.*;

/*************************************************
 * This is the main application class.
 * All it does is initialize the application,
 * and open a single window.
 * BouncePanel does all the work.
 *************************************************/

public class BounceMain {
	JFrame      mainWindow;
	BouncePanel helloPanel;
	
	// Create a new window, and put helloPanel inside it.
	public BounceMain() {
		mainWindow = new JFrame("Bouncing Ball");
		mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		helloPanel = new BouncePanel();
		mainWindow.getContentPane().add(helloPanel);
        
		mainWindow.pack();
		mainWindow.setVisible(true);
	}
    
	private static void createAndShowGUI() {
		// Make sure we have nice window decorations.
		JFrame.setDefaultLookAndFeelDecorated(false);
		// Create an actual instance of HelloBounceApp
		new BounceMain();		
	}

	public static void main(String[] args) {
		// Schedule a job for the event-dispatching thread:
		// creating and showing this application's GUI.
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createAndShowGUI();
			}
		});
	}
}
