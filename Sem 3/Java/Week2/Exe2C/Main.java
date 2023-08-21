import StudentInterface.*;
import StuGrade.*;
import StuRank.*;
import java.util.*;

public class Main extends StuRank.Rank{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter Number of Students : ");
	int len = sc.nextInt();
        StuGrade.StudentGrade obj[] = new StuGrade.StudentGrade[len];
        for(int i = 0; i < len; i++) {
            System.out.println("Student : " + (i + 1));
            obj[i] = new StuGrade.StudentGrade();
            System.out.println("--------------------------------");
        }
        int[] rankarr = rankCal(obj);
        for(int i = 0; i < len; i++){
            System.out.println("Student : " + (i+1));
            obj[i].printData();
            System.out.println("Rank : " + rankarr[i]);
            System.out.println("--------------------------------");
        }
    }
}