//Student Class with Methods

import java.util.*;
public class q1 {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.inputData();
        s1.printData();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        String name = sc.nextLine();
        System.out.print("Enter City : ");
        String city = sc.nextLine();
        System.out.print("Enter Age : ");
        int age = sc.nextInt();
        Student s2 = new Student(name, city, age);
        s2.printData();
    }
}

class Student{
    String name, city;
    int age, totdays, leavedays;
    int[] mark = new int[5];
    Student(){
        name = null;
        city = null;
        age = 0;
        totdays = 0;
        leavedays = 0;
    }
    Student(String n, String c, int a)
    {
        name = n;
        city = c;
        age = a;
    }
    void inputData(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        name = sc.nextLine();
        System.out.print("Enter City : ");
        city = sc.nextLine();
        System.out.print("Enter Age : ");
        age = sc.nextInt();
    }
    int Attendance(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Total Working Days : ");
        totdays = sc.nextInt();
        System.out.println("Enter Leave Days : ");
        leavedays = sc.nextInt();
        int att = ((totdays - leavedays)*100)/totdays;
        System.out.println("Attendance : " + att);
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
    String Grade(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 5 Subjects for 95 : ");
        int att, sum = 0, failch = 0;
        for(int i = 0; i < 5; i++){
            mark[i] = sc.nextInt();
            if(mark[i] < 35){
		failch = 1;
	    }
            sum += mark[i];
        }
	att = this.Attendance();
	if(failch == 1){
		return "F";
        }
        int avg = (sum + att*5)/5;
        if(avg > 90){
            return "O";
        }
        else if(avg > 85 && avg <= 90){
            return "A+";
        }
        else if(avg > 80 && avg <= 85){
            return "A";
        }
        else if(avg > 70 && avg <= 80){
            return "B+";
        }
        else if(avg > 60 && avg <= 70){
            return "B";
        }
        else if(avg > 50 && avg <= 60){
            return "C";
        }
        else if(avg < 50){
            return "F";
        }
        return "-1";
    }
    void printData(){
        String gr = Grade();
        System.out.println("Name : " + name + "\nCity : " + city + "\nAge : " + age);
        System.out.println("Grade : " + gr);
    }
    }



