package SearchStudent;
import java.util.*;
import DisplayStudent.*;
import StuRank.*;
import StuGrade.*;

public class Searchstudent {
    int ch, check = 0;
    char chr, c;

    public Searchstudent(StudentGrade[] objs)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1 : Enter Starting Character of Name");
        System.out.println("2 : Enter Ending Character of City");
        System.out.println("3 : Enter Student Name to be Searched");
        System.out.println("4 : Enter Search String that could be Contained");
        System.out.println("5 : Search Shortest and Longest Student Names");
        System.out.print("Enter your Choice \n->");
        ch = sc.nextInt();
	sc.nextLine();
        switch (ch)
        {
            case 1 :
                System.out.print("Enter Character : ");
                chr = sc.next().charAt(0);
                for(int i = 0; i < objs.length; i++)
                {
                    try {
                        c = objs[i].name.charAt(0);
                        if (chr == c) {
                            check = 1;
                            System.out.println("Name : " + objs[i].name);
                        }
                    }
                    catch(NullPointerException n)
                    {
                        System.out.println(n);
                    }
                }
                if(check == 0)
                {
                    System.out.println("No Names Found");
                }
                break;
            case 2 :
                System.out.println("Enter Character : ");
                chr = sc.next().charAt(0);
                for(int i = 0; i < objs.length; i++)
                {
                    try {
                        c = objs[i].city.charAt(objs[i].city.length() - 1);
                    }
                    catch(NullPointerException n)
                    {
                        System.out.println(n);
                    }
                    if(chr == c){
                        check = 1;
                        System.out.println("City : " + objs[i].city);
                    }
                }
                if(check == 0)
                {
                    System.out.println("No Cities Found");
                }
                break;
            case 3 :
                String searchname;
                System.out.print("Enter Name to Be Searched : ");
                searchname = sc.nextLine();
                for(int i = 0; i < objs.length; i++)
                {
                    try {
                        if (searchname.equalsIgnoreCase(objs[i].name)) {
                            check = 1;
                            System.out.println("Name : " + objs[i].name);
                        }
                    }
                    catch(NullPointerException n){
                        System.out.println(n);
                    }
                }
                if(check == 0)
                {
                    System.out.println("Not Found");
                }
                break;
            case 4:
                String searchword;
                System.out.print("Enter Word to Be Searched : ");
                searchword = sc.nextLine();
                for(int i = 0; i < objs.length; i++)
                {
                    try {
                        if (objs[i].name.contains(searchword)) {
                            check = 1;
                            System.out.println("Name : " + objs[i].name);
                        }
                    }
                    catch(NullPointerException n){
                        System.out.println(n);
                    }
                }
                if(check == 0)
                {
                    System.out.println("Not Found");
                }
                break;
            case 5 :
		int sh = 120, lo = 0;
                String shortest = objs[0].name, longest = objs[0].name;
		try {
                sh = objs[0].name.length(); 
		lo = objs[0].name.length();
		}
		catch(NullPointerException n){
			System.out.println(n);
		}
                for(int i = 1; i < objs.length; i++)
                {
		    try{			
                   	if(objs[i].name.length() < sh){
                        sh = objs[i].name.length();
                        shortest = objs[i].name;
                        continue;
                    }
                    if(objs[i].name.length() > lo)
                    {
                        lo = objs[i].name.length();
                        longest = objs[i].name;
                    }
		}
		catch(NullPointerException n){
			System.out.println(n);
		}

                }
		System.out.println("Longest Name : " + longest + "\nShortest Name : " + shortest);
                break;
            default :
                System.out.println("Invalid Choice");
        }
    }

    public static void main(String[] args) {
    }
}