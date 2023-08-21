package StuGrade;
import StudentInterface.*;
import java.util.*;

class AttendanceException extends Exception{
    AttendanceException(){
        super("Low mark, Attend classes regularly");
    }
}

class GradeException extends Exception{
    GradeException(){
        super("Not eligible for GPA, Work hard");
    }
}

class TotalThread extends Thread{
	int[] arr = new int[5];
	TotalThread(int[] a){
		arr = a;
	}
	public void run(){
		int sum = 0;
		for(int i : arr){
			sum += i;
		}
		System.out.print(sum);
	}
}
class GradeThread extends Thread{
     int att = 0, sum = 0;
     GradeThread(int s, int at){
	 sum = s;
         att = at;
     }
     public void run(){
        int avg = (sum + att*5)/5;
        try{
            if(avg < 50){
		System.out.println(avg);
                throw new GradeException();
            }
        }
        catch (GradeException g){
            System.out.println(g);
        }
        if(avg > 90){
            System.out.print("O");
        }
        else if(avg > 85 && avg <= 90){
            System.out.print("A+");
        }
        else if(avg > 80 && avg <= 85){
            System.out.print("A");
        }
        else if(avg > 70 && avg <= 80){
            System.out.print("B+");
        }
        else if(avg > 60 && avg <= 70){
            System.out.print("B");
        }
        else if(avg > 50 && avg <= 60){
            System.out.print("C");
        }
        else if(avg < 50){
            System.out.print("F");
        }
	else{
       	    System.out.print("-1");
    	}
    }
}

public class StudentGrade implements Attendance, Grade{
    public int val, totdays, leavedays, att, avg, age, rank, failch = 0, sum = 0;
    public String name, city, grade;
    public int[] markarr = new int[5];
    public StudentGrade() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        name = sc.nextLine();
        if(name.equals("")){
            name = null;
        }
        System.out.print("Enter City : ");
        city = sc.nextLine();
        if(city.equals("")){
            city = null;
        }
        System.out.print("Enter Age : ");
        age = sc.nextInt();
        System.out.println("Enter 5 Subject Marks for 95 : ");
        for (int i = 0; i < 5; i++) {
	    System.out.print("Enter Mark : ");
            val = sc.nextInt();
	    try{
            if (val > 95 || val < 0) {
		i--;
                throw new ArithmeticException();		
            } else {
                 if (val < 35) {
                   	grade = "F";
                        failch = 1;
                    }
             markarr[i] = val;
             sum += val;
           }
           }
	   catch(ArithmeticException a){
		System.out.println(a);
           }
	}
        att = this.attendanceCal();
        try {
            if (att < 3) {
                throw new AttendanceException();
            }
        }
        catch (AttendanceException a) {
            System.out.println(a);
        }
    }

    public String gradeCal(){
	GradeThread g = new GradeThread(sum, att);
	if (failch == 0) {
            g.start();
	    try{g.join();}
	    catch(Exception e){}
            return null;
        }
	System.out.print(grade);
	return null;
   }

    public int attendanceCal(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Total Working Days : ");
        totdays = sc.nextInt();
        System.out.print("Enter Leave Days : ");
        leavedays = sc.nextInt();
        att = ((totdays - leavedays) * 100)/totdays;
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

    public void printData(){
	TotalThread t = new TotalThread(markarr);
        System.out.println("Name : " + name + "\nCity : " + city + "\nAge : " + age);
        System.out.print("Attendance : " + att + "\nTotal : ");
	t.start();
	try{t.join();}	
	catch(Exception e){}
	System.out.print("\nGrade : ");
	gradeCal();
    }
    public static void main(String[] args) {
    }
}
