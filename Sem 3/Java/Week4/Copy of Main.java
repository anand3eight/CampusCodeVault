import java.util.*;
import StudentInterface.*;
import StuGrade.*;
import StuRank.*;
import DisplayStudent.*;
import SearchStudent.*;

class RankThread extends Thread{
     int[] rankarr;
     int len;
     StuGrade.StudentGrade obj[];     
     RankThread(StuGrade.StudentGrade obj1[], int[] r){
	rankarr = r;
	len = r.length;
	obj = obj1;
     }
     public void run(){
        for(int i = 0; i < len; i++){
            System.out.println("Student : " + (i+1));
            obj[i].printData();
	    try {
                if (rankarr[i] > 3) {
                    throw new RankException();
                }
                else{
                    System.out.println("\nRank : " + rankarr[i]);
                }
            }
            catch(RankException r){
                System.out.println(r);
            }
	    
            System.out.println("--------------------------------");
            DisplayStudent.Displaystudent dobj = new DisplayStudent.Displaystudent(obj[i]);
            System.out.println("--------------------------------");
	}
    }
}

class RankException extends Exception {
    RankException(){
        super("You are not a rank holder, Better luck next time");
    }
}

public class Main extends StuRank.Rank{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len;
        System.out.print("Enter Number of Students : ");
        len = sc.nextInt();
        StuGrade.StudentGrade obj[] = new StuGrade.StudentGrade[len];
        try {
            for(int i = 0; i <= len; i++) {
                if(i == len){
                    throw new ArrayIndexOutOfBoundsException();
                }
                System.out.println("Student : " + (i + 1));
                obj[i] = new StuGrade.StudentGrade();
                System.out.println("--------------------------------");
            }
        }
        catch(ArrayIndexOutOfBoundsException a){
                System.out.println(a);
        }
        System.out.println("-----------------------------------------");
        RankThread r = new RankThread(obj, rankCal(obj));
	r.start();
	try{r.join();}
	catch(Exception e){}
    SearchStudent.Searchstudent sobj = new SearchStudent.Searchstudent(obj);
    }
}