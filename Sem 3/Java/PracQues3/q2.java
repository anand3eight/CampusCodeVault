//Password Checker

import PS.*;
import java.util.*;

public class q2 {
    public static void main(String[] args) {
        String ps;
        char ch;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Password : ");
        ps = sc.nextLine();
        PS.Password obj = new PS.Password(ps);
        if(obj.checkpswd())
        {
            System.out.println("Permutations : ");
            obj.printAnagram(ps, "");
            System.out.print("\nEnter a Character in Password : ");
            ch = sc.next().charAt(0);
            obj.countChar(ch);
            obj.sort();
            System.out.print("\nString : " + ps);
            obj.swap();
        }
     else {
            System.out.println("Invalid Password");
     }

    }
}