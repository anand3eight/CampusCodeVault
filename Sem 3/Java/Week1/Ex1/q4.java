//Default and Parameterized Constructor

public class q4 {
    public static void main(String[] args) {
        Employee obj1 = new Employee();
        Employee obj2 = new Employee(1, "ABC");
    }
}
class Employee{
    Employee(){
        System.out.println("Default Constructor");
    }

    Employee(int id , String name){
        System.out.println("Parameterized Constructor");
        System.out.println("Employee ID : " + id + "\nName : " + name);
    }
}