//Constructor Chaining

public class q5 {
    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.display();
    }
}

class Employee{
    int ID, age;
    String name, date_of_joining, designation, address;
    Employee(){
        this(12, 22);
    }
    Employee(int a, int b){
        this("ABC");
        System.out.println("Check 1 ");
        ID = a;
        age = b;
    }
    Employee(String c){
        this("1/1/2001","CEO", "126, Times Square");
        name = c;
    }
    Employee(String d, String e, String f){
        date_of_joining = d;
        designation = e;
        address = f;
    }
    void display(){
        System.out.println("\nID : " + ID + "\nName : " + name + "\nDate of Joining : " + date_of_joining + "\nAge : " + age + "\nDesignation : " + designation + "\nAddress : " + address);
    }
}