package StuFrame;

import java.awt.event.*;
import java.util.ArrayList;
import java.awt.*;
import StuGrade.*;
import StuRank.*;
import SearchStudent.*;
import DisplayStudent.*;

class RankException extends Exception {
    RankException() {
        super("You are not a rank holder, Better luck next time");
    }
}

public class StudentFrame {
    Frame f, pf, sf;
    Label lstud, lname, lcity, lage, lgender, lsem, lmarks, lleave, lgrade, latt, ltotal, lrank, lsearch, lresult,
            dummy;
    TextField name, city, age, gender, sem, m1, m2, m3, m4, m5, leave, grade, att, total, rank, search, result;
    List ls;
    Button badd, bfinish, bchoose, bprev, bnext, bsearch, bclose;
    String nameval, genderval, cityval;
    int ageval, leaveval, semval;
    int markarr[] = new int[5];
    int count = 0, check = 0;
    public ArrayList<StuGrade.StudentGrade> studarr = new ArrayList<StuGrade.StudentGrade>();

    public void clearText() {
        lstud.setText("Student : " + String.valueOf(++count));
        name.setText("");
        city.setText("");
        age.setText("");
        gender.setText("");
        m1.setText("");
        m2.setText("");
        m3.setText("");
        m4.setText("");
        m5.setText("");
        leave.setText("");
    }

    public void addData() {
        nameval = name.getText();
        genderval = gender.getText();
        cityval = city.getText();
        try {
            ageval = Integer.valueOf(age.getText());
            leaveval = Integer.valueOf(leave.getText());
            markarr[0] = Integer.valueOf(m1.getText());
            markarr[1] = Integer.valueOf(m2.getText());
            markarr[2] = Integer.valueOf(m3.getText());
            markarr[3] = Integer.valueOf(m4.getText());
            markarr[4] = Integer.valueOf(m5.getText());
        } catch (NumberFormatException n) {
        }
        semval = ls.getSelectedIndex() + 1;
        StuGrade.StudentGrade obj = new StuGrade.StudentGrade(nameval, cityval, genderval, ageval, markarr,
                leaveval,
                semval);
        studarr.add(obj);
    }

    public void inputData() {
        f = new Frame("Student Details");
        lstud = new Label("Student :  " + String.valueOf(++count));
        f.add(lstud);
        lstud.setBounds(20, 30, 220, 20);
        lname = new Label("Name : ");
        f.add(lname);
        lname.setBounds(20, 60, 50, 20);
        name = new TextField();
        f.add(name);
        name.setBounds(80, 60, 220, 20);
        lcity = new Label("City : ");
        f.add(lcity);
        lcity.setBounds(20, 100, 50, 20);
        city = new TextField();
        f.add(city);
        city.setBounds(80, 100, 220, 20);
        lage = new Label("Age : ");
        f.add(lage);
        lage.setBounds(20, 140, 50, 20);
        age = new TextField();
        f.add(age);
        age.setBounds(80, 140, 70, 20);
        lgender = new Label("Gender : ");
        f.add(lgender);
        lgender.setBounds(160, 140, 50, 20);
        gender = new TextField();
        f.add(gender);
        gender.setBounds(220, 140, 80, 20);
        lsem = new Label("Sem : ");
        f.add(lsem);
        lsem.setBounds(20, 180, 50, 20);
        ls = new List(8, true);
        f.add(ls);
        ls.setBounds(80, 180, 100, 20);
        ls.add("Sem 1");
        ls.add("Sem 2");
        ls.add("Sem 3");
        ls.add("Sem 4");
        ls.add("Sem 5");
        ls.add("Sem 6");
        ls.add("Sem 7");
        ls.add("Sem 8");
        lmarks = new Label("Marks : ");
        f.add(lmarks);
        lmarks.setBounds(20, 220, 50, 20);
        m1 = new TextField();
        f.add(m1);
        m1.setBounds(80, 220, 40, 20);
        m2 = new TextField();
        f.add(m2);
        m2.setBounds(125, 220, 40, 20);
        m3 = new TextField();
        f.add(m3);
        m3.setBounds(170, 220, 40, 20);
        m4 = new TextField();
        f.add(m4);
        m4.setBounds(215, 220, 40, 20);
        m5 = new TextField();
        f.add(m5);
        m5.setBounds(260, 220, 40, 20);
        lleave = new Label("Leave Days : ");
        f.add(lleave);
        lleave.setBounds(20, 260, 80, 20);
        leave = new TextField();
        f.add(leave);
        leave.setBounds(125, 260, 50, 20);
        badd = new Button("Add Student");
        f.add(badd);
        badd.setBounds(120, 300, 100, 20);
        bfinish = new Button("Finish");
        f.add(bfinish);
        bfinish.setBounds(120, 340, 100, 20);
        dummy = new Label();
        f.add(dummy);

        badd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                addData();
                clearText();
            }
        });

        bfinish.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                f.dispose();
                System.out.println("Done");
                StuGrade.StudentGrade objarr[] = new StuGrade.StudentGrade[studarr.size()];
                objarr = studarr.toArray(objarr);
                int[] r = Rank.rankCal(objarr);
                printFrame(objarr, r);

            }
        });

        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent w) {
                System.out.println("Done");
                f.dispose();
                StuGrade.StudentGrade objarr[] = new StuGrade.StudentGrade[studarr.size()];
                objarr = studarr.toArray(objarr);
                int[] r = Rank.rankCal(objarr);
                printFrame(objarr, r);
            }
        });
        f.setSize(500, 500);
        f.setVisible(true);
    }

    public void printData(StuGrade.StudentGrade obj, int r, int ch, int count) {
        DisplayStudent.Displaystudent displayobj = new DisplayStudent.Displaystudent();
        lstud.setText("Student : " + String.valueOf(count));
        String[] resultVal = displayobj.printModify(obj.name, obj.city, ch).split(",");
        name.setText(resultVal[0]);
        city.setText(resultVal[1]);
        age.setText(String.valueOf(obj.age));
        gender.setText(obj.gender);
        sem.setText(String.valueOf(obj.sem));
        grade.setText(obj.grade);
        total.setText(String.valueOf(obj.sum));
        att.setText(String.valueOf(obj.att));
        try {
            if (r < 1 || r > 3) {
                throw new RankException();
            } else {
                rank.setText(String.valueOf(r));
            }
        } catch (RankException re) {
            System.out.println(re);
        }
    }

    public void clearFields() {
        name.setText("");
        city.setText("");
        age.setText("");
        gender.setText("");
        sem.setText("");
        grade.setText("");
        total.setText("");
        att.setText("");
        rank.setText("");
    }

    public void printFrame(StuGrade.StudentGrade obj[], int r[]) {
        count = 0;
        pf = new Frame("Display Frame");
        lstud = new Label();
        pf.add(lstud);
        lstud.setBounds(20, 30, 220, 20);
        ls = new List(4, true);
        pf.add(ls);
        ls.setBounds(20, 60, 250, 30);
        ls.add("Name with First Letter in CAPS");
        ls.add("Name in Small Letters");
        ls.add("Name in Capital Letters");
        ls.add("Name in Normal Form");
        bchoose = new Button("Choose");
        pf.add(bchoose);
        bchoose.setBounds(280, 60, 50, 20);
        lname = new Label("Name : ");
        pf.add(lname);
        lname.setBounds(20, 100, 50, 20);
        name = new TextField();
        pf.add(name);
        name.setBounds(80, 100, 220, 20);
        lcity = new Label("City : ");
        pf.add(lcity);
        lcity.setBounds(20, 140, 50, 20);
        city = new TextField();
        pf.add(city);
        city.setBounds(80, 140, 220, 20);
        lage = new Label("Age : ");
        pf.add(lage);
        lage.setBounds(20, 180, 50, 20);
        age = new TextField();
        pf.add(age);
        age.setBounds(80, 180, 70, 20);
        lgender = new Label("Gender : ");
        pf.add(lgender);
        lgender.setBounds(20, 220, 50, 20);
        gender = new TextField();
        pf.add(gender);
        gender.setBounds(80, 220, 80, 20);
        lsem = new Label("Sem : ");
        pf.add(lsem);
        lsem.setBounds(20, 260, 50, 20);
        sem = new TextField();
        pf.add(sem);
        sem.setBounds(80, 260, 20, 20);
        lgrade = new Label("Grade : ");
        pf.add(lgrade);
        lgrade.setBounds(20, 300, 50, 20);
        grade = new TextField();
        pf.add(grade);
        grade.setBounds(80, 300, 50, 20);
        ltotal = new Label("Total : ");
        pf.add(ltotal);
        ltotal.setBounds(20, 340, 50, 20);
        total = new TextField();
        pf.add(total);
        total.setBounds(80, 340, 50, 20);
        latt = new Label("Att : ");
        pf.add(latt);
        latt.setBounds(20, 380, 50, 20);
        att = new TextField();
        pf.add(att);
        att.setBounds(80, 380, 50, 20);
        lrank = new Label("Rank : ");
        pf.add(lrank);
        lrank.setBounds(20, 420, 50, 20);
        rank = new TextField();
        pf.add(rank);
        rank.setBounds(80, 420, 50, 20);
        bnext = new Button("Next");
        pf.add(bnext);
        bnext.setBounds(20, 460, 50, 20);
        bprev = new Button("Prev");
        pf.add(bprev);
        bprev.setBounds(80, 460, 50, 20);
        bclose = new Button("Close");
        pf.add(bclose);
        bclose.setBounds(80, 480, 50, 20);
        dummy = new Label();
        pf.add(dummy);
        pf.setSize(600, 600);
        pf.setVisible(true);

        bchoose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                int ch = ls.getSelectedIndex() + 1;
                try {
                    printData(obj[count], r[count], ch, count + 1);
                } catch (ArrayIndexOutOfBoundsException e) {
                    System.out.println(e);
                }
            }
        });

        bprev.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                count--;
                clearFields();

            }
        });

        bnext.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                count++;
                clearFields();

            }
        });

        bclose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("Done");
                pf.dispose();
                searchFrame(obj);
            }
        });

        pf.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent w) {
                System.out.println("Done");
                pf.dispose();
                searchFrame(obj);
            }
        });

    }

    public void searchFrame(StuGrade.StudentGrade obj[]) {
        sf = new Frame("Search Frame");
        ls = new List(5, true);
        sf.add(ls);
        ls.setBounds(20, 60, 250, 30);
        ls.add("Search Name with Starting Letter");
        ls.add("Search City with Ending Letter");
        ls.add("Search Name");
        ls.add("Search Name with Contained String");
        ls.add("Search Shortest and Longest Names");
        lsearch = new Label("Search : ");
        sf.add(lsearch);
        lsearch.setBounds(20, 100, 50, 20);
        search = new TextField();
        sf.add(search);
        search.setBounds(80, 100, 220, 20);
        lresult = new Label("Result : ");
        sf.add(lresult);
        lresult.setBounds(20, 140, 50, 20);
        result = new TextField();
        sf.add(result);
        result.setBounds(80, 140, 220, 20);
        bsearch = new Button("Search");
        sf.add(bsearch);
        bsearch.setBounds(20, 180, 50, 20);
        bclose = new Button("Close");
        sf.add(bclose);
        bclose.setBounds(80, 180, 50, 20);
        dummy = new Label();
        sf.add(dummy);
        sf.setSize(500, 500);
        sf.setVisible(true);

        bclose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("Done");
                sf.dispose();
            }
        });

        bsearch.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                result.setText("");
                int ch = ls.getSelectedIndex() + 1;
                String searchVal = search.getText();
                SearchStudent.Searchstudent searchobj = new SearchStudent.Searchstudent();
                String resultVal = searchobj.matchString(obj, ch, searchVal);
                result.setText(resultVal);
            }
        });

        sf.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent w) {
                System.out.println("Done");
                sf.dispose();
            }
        });

    }

    public static void main(String[] args) {
    }
}