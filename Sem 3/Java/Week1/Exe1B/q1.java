//Student Class with Inheritance

// Student Class
import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        String name = sc.nextLine();
        System.out.print("Enter City : ");
        String city = sc.nextLine();
        System.out.print("Enter Age : ");
        int age = sc.nextInt();
        System.out.print("Enter Total Working Days : ");
        int totdays = sc.nextInt();
        System.out.print("Enter Number of Leave days : ");
        int leave = sc.nextInt();
        int att = (totdays - leave)*100/totdays;
        Student s1 = new Student(name, city, age, att);
        s1.display();
    }
}
class Attendance {
    public int attcal(int att){
        if(att > 90){
            return 5;
        }
        else if(att > 85 && att <= 90){
            return 4;
        }
        else if(att > 80 && att <= 85){
            return 3;
        }
        else if(att > 70 && att <= 80){
            return 2;
        }
        else if(att > 60 && att <= 70){
            return  1;
        }

        else if(att < 60){
            return 0;
        }
        return -1;
    }
}
class Grade extends Attendance{
    int avg = 0;
    String gradecal(int sum, int att){
        this.avg = (sum + super.attcal(att)*5)/5;
        if(this.avg > 90){
            return "O";
        }
        else if(this.avg > 85 && this.avg <= 90){
            return "A+";
        }
        else if(this.avg > 80 && this.avg <= 85){
            return "A";
        }
        else if(this.avg > 70 && this.avg <= 80){
            return "B+";
        }
        else if(this.avg > 60 && this.avg <= 70){
            return "B";
        }
        else if(this.avg > 50 && this.avg <= 60){
            return "C";
        }
        else if(this.avg < 50){
            return "F";
        }
        return "-1";
    }
}
class Student extends Grade{
    String name, city, grade;
    int age, att, sum = 0, failch = 0;
    int[] marks = new int[5];
    Student(String n, String c, int age, int att){
        this.name = n;
        this.city = c;
        this.age = age;
        this.att = att;
        System.out.println("Enter 5 Subject Marks for 95: ");
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 5; i++) {
            marks[i] = sc.nextInt();
            if(marks[i] < 35){
		grade = "F";
		failch = 1;
	    }
            this.sum += marks[i];
        }
	if(failch == 0){
		grade = this.gradecal(this.sum, this.att);
        }
    }
    public void display(){
        System.out.println("Name : " + this.name + "\nCity : " + this.city + "\nAge : " + this.age);
        System.out.println("Attendance : " + this.att + "\nGrade : " + grade);
    }
}