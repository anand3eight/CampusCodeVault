package studentrank;

import studentgrade.studgrade;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class studrank {
    public static void rankcal(studgrade[] ob, int num){
        studgrade temp;
        for(int i=0;i<num;i++){
            for(int j=i;j<num;j++){
                if(ob[i].totalmark<ob[j].totalmark){
                    temp = ob[i];
                    ob[i] = ob[j];
                    ob[j] = temp;
                }
            }
        }
        int ran=1;
        ob[0].rank = 1;
        for (int i = 1; i < num; i++) {
            if (ob[i - 1].totalmark == ob[i].totalmark) {
                ob[i].rank = ran;
            }
            else {
                ran++;
                ob[i].rank = ran;
            }
        }
    }
    public static void printdata(studgrade obj[], int num) {
        JFrame f3 = new JFrame("students data");
        f3.setSize(300, 300);
        for(int i=0;i<num;i++) {
            JPanel panel = new JPanel();
            panel.setBounds(40,i*200,200,200);
            JLabel label1 = new JLabel("Rank" + obj[i].rank);
            JLabel label2 = new JLabel("name :" + obj[i].name);
            JLabel label3 = new JLabel("city :" + obj[i].city);
            JLabel label4 = new JLabel("grade :" + obj[i].grade);
            JLabel label5 = new JLabel("total mark :" + obj[i].totalmark);
            label1.setBounds(30, 30, 120, 30);
            label2.setBounds(30, 70, 120, 30);
            label3.setBounds(30, 110, 120, 30);
            label4.setBounds(30, 150, 120, 30);
            label5.setBounds(30, 190, 120, 30);

            panel.add(label1);
            panel.add(label2);
            panel.add(label3);
            panel.add(label4);
            panel.add(label5);

            f3.add(panel);

            panel.setLayout(null);
            panel.setVisible(true);
        }

        f3.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                f3.dispose();
            }
        });
        f3.setLayout(null);
        f3.setVisible(true);
    }

    public static void calculator(){
        JFrame f1 = new JFrame("calculator");
        f1.setSize(500,400);

        JLabel label1 = new JLabel("operand 1:");
        JLabel label2 = new JLabel("operand 2:");
        JLabel label3 = new JLabel("operator :");
        JLabel label4 = new JLabel("result :");
        JTextField op1 = new JTextField();
        JTextField op2 = new JTextField();
        JButton result = new JButton("calculate");

        String operator[]=new String[]{"+","-","x","/"};
        JComboBox cb = new JComboBox(operator);

        label1.setBounds(50,100,100,30);
        label2.setBounds(50,140,100,30);
        label3.setBounds(50,180,100,30);
        op1.setBounds(160,100,100,30);
        op2.setBounds(160,140,100,30);
        cb.setBounds(160,180,100,30);
        label4.setBounds(50,220,100,30);
        result.setBounds(90,270,100,40);

        f1.setLayout(null);
        label4.setVisible(false);

        f1.add(label1);f1.add(label2);f1.add(label3);f1.add(op1);f1.add(op2);f1.add(cb);
        f1.add(label4);f1.add(result);

        result.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double a = Double.parseDouble(String.valueOf(op1.getText()));
                double b = Double.parseDouble(String.valueOf(op2.getText()));
                String op = (String) cb.getItemAt(cb.getSelectedIndex());
                double c;
                if(op == "+"){
                    c = a + b;}
                else if(op == "-")
                    c = a-b;
                else if(op == "x")
                    c = a*b;
                else
                    c = a/b;
                label4.setText("result :"+c);
                label4.setVisible(true);
            }
        });

        f1.setVisible(true);
    }
    public static void main(String[] args)
    {
        
    }
}
