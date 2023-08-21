package StuGrade;

import StudentInterface.*;
import java.util.*;

class AttendanceException extends Exception {
    AttendanceException() {
        super("Low mark, Attend classes regularly");
    }
}

class GradeException extends Exception {
    GradeException() {
        super("Not eligible for GPA, Work hard");
    }
}

public class StudentGrade implements Attendance, Grade {
    public int val, att, totdays, leavedays, attavg, avg, age, sem, failch = 0, sum = 0;
    public String name, city, gender, grade;
    public int[] markarr = new int[5];

    public StudentGrade(String name, String city, String gender, int age, int markarr[], int leaveDays, int sem) {
        this.name = name;
        if (this.name.length() == 0) {
            name = null;
        }
        this.gender = gender;
        if (this.gender.length() == 0) {
            gender = null;
        }
        this.city = city;
        if (this.city.length() == 0) {
            city = null;
        }
        this.age = age;
        this.sem = sem;
        for (int i = 0; i < 5; i++) {
            this.val = markarr[i];
            try {
                if (this.val > 95 || this.val < 0) {
                    throw new ArithmeticException();
                } else {
                    if (this.val < 35) {
                        grade = "F";
                        failch = 1;
                    }
                    this.markarr[i] = this.val;
                    this.sum += this.val;
                }
            } catch (ArithmeticException a) {
                markarr[i] = -1;
                System.out.println(a);
            }
        }
        this.totdays = 90;
        this.leavedays = leaveDays;
        this.att = this.attendanceCal();
        try {
            if (att < 3) {
                throw new AttendanceException();
            }
        } catch (AttendanceException a) {
            System.out.println(a);
        }
        if (failch == 0) {
            this.grade = this.gradeCal();
        }
    }

    public int attendanceCal() {

        attavg = ((totdays - leavedays) * 100) / totdays;
        if (attavg > 90) {
            return 5;
        } else if (attavg > 85 && attavg <= 90) {
            return 4;
        } else if (attavg > 80 && attavg <= 85) {
            return 3;
        } else if (attavg > 70 && attavg <= 80) {
            return 2;
        } else if (attavg > 60 && attavg <= 70) {
            return 1;
        } else if (attavg < 60) {
            return 0;
        }
        return -1;
    }

    public String gradeCal() {
        avg = (sum + att * 5) / 5;
        try {
            if (avg < 50) {
                throw new GradeException();
            }
        } catch (GradeException g) {
            System.out.println(g);
        }
        if (avg > 90) {
            return "O";
        } else if (avg > 85 && avg <= 90) {
            return "A+";
        } else if (avg > 80 && avg <= 85) {
            return "A";
        } else if (avg > 70 && avg <= 80) {
            return "B+";
        } else if (avg > 60 && avg <= 70) {
            return "B";
        } else if (avg > 50 && avg <= 60) {
            return "C";
        } else if (avg < 50) {
            return "F";
        }
        return "-1";
    }

    public void printData() {
    }

    public static void main(String[] args) {
    }
}
