import java.awt.*;  
import java.awt.event.*;  
class Sample extends Frame implements ActionListener{  
TextField tf;
Label l;

Sample(){  
  
//create components  
tf=new TextField();  
tf.setBounds(60,50,170,20);
l=new Label();  
l.setBounds(50,100, 250,20);    
Button b=new Button("click me");  
b.setBounds(100,120,80,30);  
  
//register listener  
b.addActionListener(this);//passing current instance  
  
//add components and set size, layout and visibility  
add(b);add(tf); add(l); 
setSize(300,300);  
setLayout(null);  //default layout:flowlayout
setVisible(true);  
} 
 
public void actionPerformed(ActionEvent e){  
tf.setText("Welcome");  
l.setText("Text box data");  

}  
public static void main(String args[]){  
new Sample();  
}  
}  