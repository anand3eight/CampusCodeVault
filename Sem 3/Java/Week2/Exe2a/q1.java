//Interface

import java.util.*;
public class q1{
	public static void main(String args[]){
		Result obj = new Result();
		Scanner sc = new Scanner(System.in);
		int[] marks = new int[5];
		int avg, sum = 0, ch = 0;
		for(int i = 0; i < 5; i++){
			System.out.print("Enter Mark " + (i+1) + " : ");
			marks[i] = sc.nextInt();
			sum += marks[i];
		}
		for(int i = 0; i < 5; i++){
			if(!obj.pass(marks[i]))
				ch = 1;			
			System.out.println("Sub " + (i+1) + " : " + obj.pass(marks[i]));
		}
		avg = sum/5;
		if(ch == 0)
			System.out.println(obj.division(avg));
		else
			System.out.println("No Division");	
		
	}
}
interface Exam{
	boolean pass(int marks);
}
interface Classify{
	String division(int avg);
}

class Result implements Exam, Classify{
	public boolean pass(int marks){
		if(marks >= 50){
			return true;
		}
		else{
			return false;
		}
	}
	
	public String division(int avg){
		if(avg >= 60){
			return "First";
		}
		else if(avg >= 50 && avg < 60){
			return "Second";
		}
		else{
			return "No Division";
		}
	}
}

