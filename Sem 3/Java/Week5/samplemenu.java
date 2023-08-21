import java.awt.*; 
import java.awt.event.*;  
class samplemenu  
{  
     samplemenu(){  
         Frame f= new Frame("Menu and MenuItem Example");  
         MenuBar mb=new MenuBar();  
         Menu menu=new Menu("Menu");
//submenu  
         Menu submenu=new Menu("Sub Menu"); 
//popup
         PopupMenu popupmenu = new PopupMenu("Edit"); 
         MenuItem i1=new MenuItem("Item 1");  
         MenuItem i2=new MenuItem("Item 2");  
         MenuItem i3=new MenuItem("Item 3");  
         MenuItem i4=new MenuItem("Item 4");  
         MenuItem i5=new MenuItem("Item 5");  
         menu.add(i1);  
         menu.add(i2);  
         menu.add(i3);  
         submenu.add(i4);  
         submenu.add(i5);  
         menu.add(submenu);  
         mb.add(menu);
//popup menu
         MenuItem cut = new MenuItem("Cut");  
         MenuItem copy = new MenuItem("Copy");
         MenuItem paste = new MenuItem("Paste");               
         popupmenu.add(cut);  
         popupmenu.add(copy);  
         popupmenu.add(paste);    
//Listner
            f.addMouseListener(new MouseAdapter() {  
            public void mouseClicked(MouseEvent e) {              
                popupmenu.show(f, e.getX(), e.getY());  
            }                 
         });  
         f.add(popupmenu); 
  //menu

         f.setMenuBar(mb);  
         f.setSize(400,400);  
         f.setLayout(null);  
         f.setVisible(true);  
}  
public static void main(String args[])  
{  
new samplemenu();  
}  
}  
