/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
public class Circle extends Applet {
    @Override
    public void paint(Graphics g)
    {
        g.setColor(new Color(255,0,14));
        g.fillArc(0,0,50,50,0,360);
    }
}
