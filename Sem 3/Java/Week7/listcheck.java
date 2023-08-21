import javax.swing.*;
import java.awt.*;

class listcheck {
    listcheck() {
        JFrame f = new JFrame("List Check");
        JPanel p = new JPanel(new BorderLayout());
        String[] arr = { "Sem 1", "Sem 2", "Sem 3", "Sem 4", "Sem 5", "Sem 6", "Sem 7", "Sem 8" };
        JList<String> ls = new JList<String>(arr);
        ls.setLayoutOrientation(JList.VERTICAL);
        JScrollPane listscroll = new JScrollPane();
        listscroll.setViewportView(ls);
        p.setPreferredSize(new Dimension(200, 20));
        p.add(listscroll);
        f.add(p);
        f.setSize(200, 200);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);

    }

    public static void main(String[] args) {
        new listcheck();
    }
}