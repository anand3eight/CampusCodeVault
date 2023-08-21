//Applet class check 1

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class appletprgm extends Applet {
    String word;

    public void init() {
        setBackground(Color.WHITE);
        word = "Hello World ";
    }

    public void start() {
        word = word + "Anand!";
    }

    public void paint(Graphics g) {
        String str = getParameter("msg");
        g.drawString(str, 100, 150);
        g.drawOval(50, 200, 100, 200);
    }

    public void stop() {
    }

    public void destroy() {
    }
}

/*
 * <applet code = "appletcheck.class" width = "3000" height = "3000">
 * <param name = "msg" value = "Hello World!!>
 * </applet>
 */