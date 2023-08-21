//Employee and Company class with Display method
import java.util.*;

public class q1
{
    public static void main(String args[]){
        String ename, eno;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Employee Name and Number : ");
        ename = sc.nextLine();
        eno = sc.nextLine();
        Employee E_obj = new Employee(ename, eno);
        String cname, cdomain;
        System.out.println("Enter Company Name and Domain : ");
        cname = sc.nextLine();
        cdomain = sc.nextLine();
        Company C_obj = new Company(cname, cdomain);
        E_obj.display();
        C_obj.display();
    }
}

class Employee
{
    String ename, eno;
    Employee(String a, String b){
        ename = a;
        eno = b;
    }

    public void display(){
        System.out.println("\nName : " + ename + "\nNo : " + eno);
    }
}

class Company{
    String cname, cdomain;
    Company(String a, String b){
        cname = a;
        cdomain = b;
    }

    public void display(){
        System.out.println("\nName : " + cname + "\nDomain : " + cdomain);
    }
}