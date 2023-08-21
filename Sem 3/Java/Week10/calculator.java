//Frame Sample

import java.awt.*;
import java.awt.event.*;

public class calculator extends Frame implements ActionListener, TextListener {
    TextField tf1, tf2;
    Button b;
    Label l;
    int n1, n2;

    calculator() {
        setBackground(Color.LIGHT_GRAY);
        tf1 = new TextField();
        tf1.setBounds(20, 60, 65, 20);
        tf2 = new TextField();
        tf2.setBounds(20, 60, 65, 20);
        l = new Label("Enter Numbers : ");
        l.setBounds(20, 30, 100, 20);
        b = new Button("Calculate");
        b.setBounds(20, 90, 100, 20);
        b.addActionListener(this);
        tf1.addTextListener(this);
        tf2.addTextListener(this);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent w) {
                dispose();
            }
        });
        add(tf1);
        add(tf2);
        add(b);
        add(l);
        setSize(250, 350);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent a) {
        switch (op) {
            case '+':
                tf1.setText(String.valueOf(n1 + n2));
                break;
            case '-':
                tf1.setText(String.valueOf(n1 - n2));
                break;
            case '*':
                tf1.setText(String.valueOf(n1 * n2));
                break;
            case '/':
                tf1.setText(String.valueOf(n1 / n2));
                break;

        }
        l.setText("Completed!");
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }
        tf1.setText("");
    }

    public void textValueChanged(TextEvent te) {
        int n1 = Integer.valueOf(tf1.getText());
        int n2 = Integer.valueOf(Intf2.getText());
    }

    public static void main(String[] args) {
        new calculator();
    }
}
