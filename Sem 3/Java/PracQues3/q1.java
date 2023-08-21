//String Operations
import java.util.*;

class Strings
{
    String s;
    Strings(String str)
    {
        s = str;
    }
    Strings()
    {
        s = null;
    }
    void printAnagram(String a, String b)
    {
        if(a.length() == 0){
            System.out.print(b + " ");
            return;
        }
        int i;
        char ch;
        String retstr;
        for(i = 0; i < a.length(); i++){
            ch = a.charAt(i);
            retstr = a.substring(0, i) + a.substring(i+1);
            printAnagram(retstr, b + ch);
        }

    }

    int countUpperCaseLetters()
    {
        int i, count = 0;
        for(i = 0; i < s.length(); i++){
            if(Character.isUpperCase(s.charAt(i)) == true){
                count++;
            }
        }
        return count;
    }

    String toUpperCase()
    {
        return s.toUpperCase();
    }

    StringBuffer getReverse()
    {
        StringBuffer s1 = new StringBuffer();
        s1.append(s);
        s1.reverse();
        return s1;
    }

    boolean isPalindrome()
    {
        return s.equals(getReverse().toString());
    }
}


public class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.println("Enter a String : ");
        str = sc.nextLine();
        Strings s = new Strings(str);
        System.out.println("Permutations : ");
        s.printAnagram(str, "");
        System.out.println("\nUpperCase Letters : " + s.countUpperCaseLetters());
        System.out.println("UpperCase String  : " + s.toUpperCase());
        System.out.println("Reversed String   : " + s.getReverse());
        if(s.isPalindrome()) {
            System.out.println("Palindrome");
        }
        else{
            System.out.println("Not A Palindrome");
        }


    }
}