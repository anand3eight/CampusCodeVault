//Student Grade - Interfaces

import java.util.*;

interface Student
{
    void inputData();
    void printData();
}

interface Attendance extends Student
{
    int attendanceCal();
}

interface Grade extends Attendance
{
    String gradeCal();
}

class StudentGrade implements Attendance, Grade
{
    String name, city, grade;
    int age, attendance, avg = 0, sum = 0, failch = 0;
    int[] marks = new int[5];
    StudentGrade() {
        System.out.println("Enter 5 Subject Marks Out of 95 : ");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            marks[i] = sc.nextInt();
	    if(marks[i] < 35){
		this.grade = "F";
		failch = 1;
	    }
            this.sum += marks[i];
        }
    }
    public void inputData(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        this.name = sc.nextLine();
        System.out.print("Enter City : ");
        this.city = sc.nextLine();
        System.out.print("Enter Age : ");
        this.age = sc.nextInt();
        if(failch == 0){
	this.grade = gradeCal();
	}
    }
    public int attendanceCal(){
        int totdays, leave, att;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Total Working Days : ");
        totdays = sc.nextInt();
        System.out.print("Enter Leave Days : ");
        leave = sc.nextInt();
        att = ((totdays - leave)*100)/totdays;
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
    public String gradeCal(){
	this.attendance = attendanceCal();
        this.avg = (this.sum + this.attendance*5)/5;
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
    public void printData(){
            System.out.println("Name : " + this.name + "\nCity : " + this.city + "\nAge : " + this.age);
            System.out.println("Attendance : " + this.attendance + "\nGrade : " + this.grade);
    }
}

public class q1 {
    public static void main(String[] args) {
        StudentGrade stud[] = new StudentGrade[5];
        System.out.println("Input the Values ->");
        for(int i = 0; i < 5; i++){
            System.out.println("Student : " + (i+1));
            stud[i] = new StudentGrade();
            stud[i].inputData();
            System.out.println("-------------------------------------");
        }
        System.out.println("Output ->");
        for(int i = 0; i < 5; i++){
            System.out.println("Student : " + (i+1));
            stud[i].printData();
            System.out.println("-------------------------------------");
        }

    }
}