import java.awt.*;

class FirstFrame extends Frame {
    FirstFrame() {
        Button b = new Button("Hello World");
        b.setBounds(300, 300, 300, 200);// setting button position
        add(b);// adding button into frame
        setSize(1000, 1000);// frame size 300 width and 300 height
        setLayout(null);// no layout now bydefault BorderLayout
        setVisible(true);// now frame willbe visible, bydefault not visible
    }

    public static void main(String args[]) {
        FirstFrame f = new FirstFrame();
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
        }
        System.exit(0);
    }
}