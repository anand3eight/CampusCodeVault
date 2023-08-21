package DisplayStudent;
import StuRank.*;
import java.util.*;
import StuGrade.*;

public class Displaystudent
{
    int ch;
    public Displaystudent(StudentGrade obj)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1 : Display Starting Letter of Name and City of a Student in CAPS : ");
        System.out.println("2 : Display Name/City in LowerCase");
        System.out.println("3 : Display Name/City in UpperCase");
        System.out.println("4 : Display");
        ch = sc.nextInt();
        switch (ch)
        {
            case 1 :
                try {
                    System.out.println("Name : " + Character.toUpperCase(obj.name.charAt(0)));
                    System.out.println("City : " + Character.toUpperCase(obj.city.charAt(0)));
                }
                catch(StringIndexOutOfBoundsException s){
                    System.out.println(s);
                }
                break;
            case 2 :
                try {
                    System.out.println("Name : " + obj.name.toLowerCase());
                    System.out.println("City : " + obj.city.toLowerCase());
                }
                catch(StringIndexOutOfBoundsException s){
                    System.out.println(s);
                }
                break;
            case 3 :
                try {
                    System.out.println("Name : " + obj.name.toUpperCase());
                    System.out.println("City : " + obj.city.toUpperCase());
                }
                catch(StringIndexOutOfBoundsException s){
                    System.out.println(s);
                }
                break;
            case 4 :
                System.out.println("Name : " + obj.name + "\nCity : " + obj.city);
                break;
            default :
                System.out.println("Invalid Choice");
        }

    }

    public static void main(String[] args) {
    }

}