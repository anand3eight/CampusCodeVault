//Banking Class

import java.util.*;

public class q8 {
    public static void main(String[] args) {
        Customer c1 = new Customer();
        Customer c2 = new Customer();
        Customer c3 = new Customer();
        c1.display();
        c2.display();
        c3.display();
    }
}

class Address {
    String street, town, state, country;
    int pin;

    Address() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Street : ");
        street = sc.nextLine();
        System.out.print("Enter Town : ");
        town = sc.nextLine();
        System.out.print("Enter State : ");
        state = sc.nextLine();
        System.out.print("Enter Country : ");
        country = sc.nextLine();
        System.out.print("Enter Pincode : ");
        pin = sc.nextInt();
    }
}
class Person{
    String name;
    Address add_obj;
    Person(String a){
        name = a;
        add_obj = new Address();
    }
}
class Customer{
    Person per_obj;
    int accounts;
    String dateOfJoining;
    Customer()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Customer Name : ");
        String name = sc.nextLine();
        per_obj = new Person(name);
        System.out.print("Enter Date of Joining : ");
        dateOfJoining = sc.nextLine();
        System.out.print("Enter Number of Accounts : ");
        accounts = sc.nextInt();
    }

    void display(){
        System.out.print("\nName : " + per_obj.name + "\nAddress : " + per_obj.add_obj.street + ", ");
        System.out.print(per_obj.add_obj.town + ", " + per_obj.add_obj.state);
        System.out.println(", " + per_obj.add_obj.country + ", " + per_obj.add_obj.pin);
        System.out.println("Accounts : " + accounts);
        System.out.println("Date of Joining : " + dateOfJoining);
    }
}
