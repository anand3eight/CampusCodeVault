//Frame Sample

import java.awt.*;
import java.awt.event.*;

public class sampleframe extends Frame implements ActionListener, TextListener{
    TextField tf;
    Button b;
    Label l;
    String str;
    sampleframe(){
        setBackground(Color.LIGHT_GRAY);
        tf = new TextField();
        tf.setBounds(20, 60, 170, 20);
        l = new Label("Enter Numbers : ");
        l.setBounds(20, 30, 100, 20);
        b = new Button("Calculate");
        b.setBounds(20, 90, 100, 20);
        b.addActionListener(this);
        tf.addTextListener(this);
        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent w){
                dispose();
            }
    });
        add(tf);
        add(b);
        add(l);
        setSize(250, 350);
        setLayout(null);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent a){
        int n1 = str.toCharArray()[0] - '0', n2 = str.toCharArray()[2] - '0';
        char op = str.toCharArray()[1];
        System.out.println(op);
        switch(op){
            case '+' : 
                tf.setText(String.valueOf(n1+n2));
                break;
            case '-' :
                tf.setText(String.valueOf(n1-n2));
                break;
            case '*' :
                tf.setText(String.valueOf(n1*n2));
                break;
            case '/' :
                tf.setText(String.valueOf(n1/n2));
                break;

        }
        tf.setText(String.valueOf(n1+n2));
        l.setText("Completed!");
        try{Thread.sleep(500);}
        catch(Exception e){}
        tf.setText("");
    }        
    public void textValueChanged(TextEvent te){
        str = tf.getText();
        System.out.println("Text Value Changed");
    }



    public static void main(String[] args) {
        new sampleframe();
    }
}