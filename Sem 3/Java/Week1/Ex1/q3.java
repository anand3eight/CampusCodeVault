//Employee Display

import java.util.*;

public class q3{
    public static void main(String[] args) {
        q3 obj = new q3();
        obj.employeeDisplay();
    }
    public void employeeDisplay(){
        Employee1 Emp_Obj = new Employee1(), test = new Employee1("ABC", "12");
        Emp_Obj.display(test);
    }

}

class Employee1{
    String ename, eno;
    Employee1(){
        ename = null;
        eno = null;
    }
    Employee1(String a, String b){
        ename = a;
        eno = b;
    }
    void display(Employee1 obj){
        System.out.println("Name : " + obj.ename + "\nNo : " + obj.eno);
    }

}