//Applet Program

import java.awt.Color;
import java.awt.Graphics;
import java.applet.Applet;

public class appletprgm extends Applet{
    public void init(){
        setBackground(Color.darkGray);
    }
    public void paint(Graphics g){
        g.setColor(Color.WHITE);
        g.drawString("Hasttin", 130, 175);
        g.setColor(Color.RED);
        g.drawOval(50, 50, 200, 250);
        g.drawArc(50, 50, 200, 250, 20, 20);

    }
}

/*<applet code = "appletprgm.class" width = "500" height = "500">
</applet>
*/