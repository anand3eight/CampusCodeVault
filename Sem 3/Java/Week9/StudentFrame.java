package StuFrame;

import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.ArrayList;
import StuGrade.*;
import StuRank.*;
import SearchStudent.*;
import DisplayStudent.*;
import GPA.*;
import StuFile.*;

class RankException extends Exception {
    RankException() {
        super("You are not a rank holder, Better luck next time");
    }
}

public class StudentFrame {
    JFrame f, pf, sf, gf;
    JLabel lstud, lname, ldob, lcity, lage, lgender, lsem, lmarks, lleave, lgrade, latt, ltotal, lrank, lsearch,
            lresult,
            lcredits, dummy;
    JTextField name, dob, city, age, gender, sem, m1, m2, m3, m4, m5, leave, grade, att, total, rank, search, result,
            c1, c2,
            c3, c4, c5, res;
    JList<String> ls;
    JButton badd, bfinish, bchoose, bprev, bnext, bsearch, bclose;
    String nameval, dobval, genderval, cityval;
    int ageval, leaveval, semval;
    int markarr[] = new int[5];
    int[] r;
    int count = 0, check = 0;
    public ArrayList<StuGrade.StudentGrade> studarr = new ArrayList<StuGrade.StudentGrade>();

    public void clearText() {
        lstud.setText("Student : " + String.valueOf(++count));
        name.setText("");
        dob.setText("");
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
        dobval = dob.getText();
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
        StuGrade.StudentGrade obj = new StuGrade.StudentGrade(nameval, dobval, cityval, genderval, ageval, markarr,
                leaveval,
                semval);
        studarr.add(obj);
    }

    public void inputData() {
        f = new JFrame("Student Details");
        lstud = new JLabel("Student :  " + String.valueOf(++count));
        f.add(lstud);
        lstud.setBounds(20, 30, 220, 20);
        lname = new JLabel("Name : ");
        f.add(lname);
        lname.setBounds(20, 60, 50, 20);
        name = new JTextField();
        f.add(name);
        name.setBounds(80, 60, 220, 20);
        ldob = new JLabel("DOB : ");
        f.add(ldob);
        ldob.setBounds(310, 60, 50, 20);
        dob = new JTextField();
        f.add(dob);
        dob.setBounds(310, 100, 150, 20);
        lcity = new JLabel("City : ");
        f.add(lcity);
        lcity.setBounds(20, 100, 50, 20);
        city = new JTextField();
        f.add(city);
        city.setBounds(80, 100, 220, 20);
        lage = new JLabel("Age : ");
        f.add(lage);
        lage.setBounds(20, 140, 50, 20);
        age = new JTextField();
        f.add(age);
        age.setBounds(80, 140, 70, 20);
        lgender = new JLabel("Gender : ");
        f.add(lgender);
        lgender.setBounds(160, 140, 50, 20);
        gender = new JTextField();
        f.add(gender);
        gender.setBounds(220, 140, 80, 20);
        lsem = new JLabel("Sem : ");
        f.add(lsem);
        lsem.setBounds(310, 140, 50, 20);
        String semarr[] = new String[] { "Sem 1", "Sem 2", "Sem 3", "Sem 4", "Sem 5", "Sem 6", "Sem 7", "Sem 8" };
        ls = new JList<String>(semarr);
        f.add(ls);
        ls.setBounds(370, 140, 100, 160);
        lmarks = new JLabel("Marks : ");
        f.add(lmarks);
        lmarks.setBounds(20, 180, 50, 20);
        m1 = new JTextField();
        f.add(m1);
        m1.setBounds(80, 180, 40, 20);
        m2 = new JTextField();
        f.add(m2);
        m2.setBounds(125, 180, 40, 20);
        m3 = new JTextField();
        f.add(m3);
        m3.setBounds(170, 180, 40, 20);
        m4 = new JTextField();
        f.add(m4);
        m4.setBounds(215, 180, 40, 20);
        m5 = new JTextField();
        f.add(m5);
        m5.setBounds(260, 180, 40, 20);
        lleave = new JLabel("Leave Days : ");
        f.add(lleave);
        lleave.setBounds(20, 220, 80, 20);
        leave = new JTextField();
        f.add(leave);
        leave.setBounds(125, 220, 50, 20);
        badd = new JButton("Add Student");
        f.add(badd);
        badd.setBounds(120, 260, 200, 20);
        bfinish = new JButton("Finish");
        f.add(bfinish);
        bfinish.setBounds(120, 300, 200, 20);
        dummy = new JLabel();
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
        String[] resultVal = displayobj.printModify(obj.name, obj.city, ch).split(",");
        name.setText(resultVal[0]);
        dob.setText(obj.dob);
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
        dob.setText("");
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
        pf = new JFrame("Display Frame");
        lstud = new JLabel();
        pf.add(lstud);
        lstud.setBounds(20, 30, 220, 20);
        String choicearr[] = new String[] { "Name with First Letter in CAPS", "Name in Small Letters",
                "Name in Capital Letters",
                "Name in Normal Form" };
        ls = new JList<String>(choicearr);
        pf.add(ls);
        ls.setBounds(20, 60, 250, 120);
        bchoose = new JButton("Choose");
        pf.add(bchoose);
        bchoose.setBounds(280, 60, 200, 20);
        lname = new JLabel("Name : ");
        pf.add(lname);
        lname.setBounds(20, 220, 50, 20);
        name = new JTextField();
        pf.add(name);
        name.setBounds(80, 220, 220, 20);
        ldob = new JLabel("DOB : ");
        pf.add(ldob);
        ldob.setBounds(310, 220, 50, 20);
        dob = new JTextField();
        pf.add(dob);
        dob.setBounds(310, 260, 150, 20);
        lcity = new JLabel("City : ");
        pf.add(lcity);
        lcity.setBounds(20, 260, 50, 20);
        city = new JTextField();
        pf.add(city);
        city.setBounds(80, 260, 220, 20);
        lage = new JLabel("Age : ");
        pf.add(lage);
        lage.setBounds(20, 300, 50, 20);
        age = new JTextField();
        pf.add(age);
        age.setBounds(80, 300, 70, 20);
        lgender = new JLabel("Gender : ");
        pf.add(lgender);
        lgender.setBounds(160, 300, 50, 20);
        gender = new JTextField();
        pf.add(gender);
        gender.setBounds(220, 300, 80, 20);
        lsem = new JLabel("Sem : ");
        pf.add(lsem);
        lsem.setBounds(20, 340, 50, 20);
        sem = new JTextField();
        pf.add(sem);
        sem.setBounds(80, 340, 20, 20);
        lgrade = new JLabel("Grade : ");
        pf.add(lgrade);
        lgrade.setBounds(20, 380, 50, 20);
        grade = new JTextField();
        pf.add(grade);
        grade.setBounds(80, 380, 50, 20);
        ltotal = new JLabel("Total : ");
        pf.add(ltotal);
        ltotal.setBounds(20, 420, 50, 20);
        total = new JTextField();
        pf.add(total);
        total.setBounds(80, 420, 50, 20);
        latt = new JLabel("Att : ");
        pf.add(latt);
        latt.setBounds(20, 460, 50, 20);
        att = new JTextField();
        pf.add(att);
        att.setBounds(80, 460, 50, 20);
        lrank = new JLabel("Rank : ");
        pf.add(lrank);
        lrank.setBounds(20, 500, 50, 20);
        rank = new JTextField();
        pf.add(rank);
        rank.setBounds(80, 500, 50, 20);
        bnext = new JButton("Next");
        pf.add(bnext);
        bnext.setBounds(20, 540, 100, 20);
        bprev = new JButton("Prev");
        pf.add(bprev);
        bprev.setBounds(130, 540, 100, 20);
        bclose = new JButton("Close");
        pf.add(bclose);
        bclose.setBounds(240, 540, 100, 20);
        dummy = new JLabel();
        pf.add(dummy);
        pf.setSize(600, 600);
        pf.setVisible(true);

        bchoose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                int ch = ls.getSelectedIndex() + 1;

                try {
                    lstud.setText("Student : " + String.valueOf(count));
                    StuFile.StudentFile sf = new StuFile.StudentFile(count + 1, obj[count], r[count]);
                    try {
                        sf.writeDetails();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
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
        sf = new JFrame("Search Frame");
        String choicearr[] = new String[] { "Search Name with Starting Letter", "Search City with Ending Letter",
                "Search Name",
                "Search Name with Contained String", "Search Shortest and Longest Names" };
        ls = new JList<String>(choicearr);
        sf.add(ls);
        ls.setBounds(20, 60, 250, 150);
        lsearch = new JLabel("Search : ");
        sf.add(lsearch);
        lsearch.setBounds(20, 220, 50, 20);
        search = new JTextField();
        sf.add(search);
        search.setBounds(80, 220, 220, 20);
        lresult = new JLabel("Result : ");
        sf.add(lresult);
        lresult.setBounds(20, 260, 50, 20);
        result = new JTextField();
        sf.add(result);
        result.setBounds(80, 260, 220, 20);
        bsearch = new JButton("Search");
        sf.add(bsearch);
        bsearch.setBounds(20, 300, 200, 20);
        bclose = new JButton("Close");
        sf.add(bclose);
        bclose.setBounds(230, 300, 200, 20);
        dummy = new JLabel();
        sf.add(dummy);
        sf.setSize(500, 500);
        sf.setVisible(true);

        bclose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("Done");
                sf.dispose();
                GPAFrame();
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
                GPAFrame();
            }
        });

    }

    public void GPAFrame() {
        gf = new JFrame("GPA Calculator");
        lcredits = new JLabel("Credits : ");
        gf.add(lcredits);
        lcredits.setBounds(20, 20, 50, 20);
        c1 = new JTextField();
        gf.add(c1);
        c1.setBounds(80, 20, 40, 20);
        c2 = new JTextField();
        gf.add(c2);
        c2.setBounds(125, 20, 40, 20);
        c3 = new JTextField();
        gf.add(c3);
        c3.setBounds(170, 20, 40, 20);
        c4 = new JTextField();
        gf.add(c4);
        c4.setBounds(215, 20, 40, 20);
        c5 = new JTextField();
        gf.add(c5);
        c5.setBounds(260, 20, 40, 20);
        res = new JTextField();
        gf.add(res);
        res.setBounds(20, 60, 220, 20);
        bsearch = new JButton("Calculate");
        gf.add(bsearch);
        bsearch.setBounds(20, 100, 200, 20);
        bclose = new JButton("Close");
        gf.add(bclose);
        bclose.setBounds(20, 140, 200, 20);
        dummy = new JLabel();
        gf.add(dummy);

        bsearch.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int creditarr[] = new int[5];
                creditarr[0] = Integer.valueOf(c1.getText());
                creditarr[1] = Integer.valueOf(c2.getText());
                creditarr[2] = Integer.valueOf(c3.getText());
                creditarr[3] = Integer.valueOf(c4.getText());
                creditarr[4] = Integer.valueOf(c5.getText());
                float r = GPA.gpacalculator.gpacal(creditarr, markarr);
                res.setText(String.valueOf(r));

            }
        });

        bclose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("Done");
                gf.dispose();
            }
        });

        gf.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent w) {
                System.out.println("Done");
                gf.dispose();
            }
        });

        gf.setSize(500, 500);
        gf.setVisible(true);

    }

    public static void main(String[] args) {
    }
}