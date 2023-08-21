package StuGrade;
import StudentInterface.*;
import java.util.*;

public class StudentGrade implements Attendance, Grade{
    public int val, totdays, leavedays, att, avg, age, rank, sum = 0, failch = 0;
    public String name, city, grade;
    public int[] markarr = new int[5];
    public StudentGrade(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name : ");
        name = sc.nextLine();
        System.out.print("Enter City : ");
        city = sc.nextLine();
        System.out.print("Enter Age : ");
        age = sc.nextInt();
        System.out.println("Enter 5 Subject Marks for 95 : ");
        for(int i = 0; i < 5; i++){
            val = sc.nextInt();
            if(val < 96 && val > -1) {
                markarr[i] = val;
		if(val < 35){
			grade = "F";
			failch = 1;
		}
                sum += val;
            }
            else {
                System.out.print("Mark is out of Range \nRe-Enter : ");
                i--;
            }
        }
	att = this.attendanceCal();
	if(failch == 0){
        	grade = this.gradeCal();
	}
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

    public String gradeCal(){
        avg = (sum + att*5)/5;
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
    public void printData(){
        System.out.println("Name : " + name + "\nCity : " + city + "\nAge : " + age + "\nSum : " + sum);
        System.out.println("Attendance : " + att + "\nGrade : " + grade);
    }
    public static void main(String[] args) {
    }
}
