//Amazon Package

import java.util.*;

class Password{
    String ps;
    Password(){
        ps = null;
    }
    Password(String ps){
        this.ps = ps;
    }
    void changeps(String s){
        this.ps = s;
    }
    boolean lengthcheck(){
        return ps.length() > 5;
    }

    boolean alnumcheck(){
        boolean upr = false, lwr = false, dig = false;
        for(int i = 0; i < ps.length(); i++){
             if(!upr)
                 upr = Character.isUpperCase(ps.charAt(i));
             if(!lwr)
                 lwr = Character.isLowerCase(ps.charAt(i));
             if(!dig)
                 dig = Character.isDigit(ps.charAt(i));
        }
        return upr && lwr && dig;

    }

    boolean check(){
        return lengthcheck() && alnumcheck();
    }

}

class Product{
    String[] items = {"Phone  ", "TV     ", "Laptop "};
    int[] prices = {10000, 20000, 30000};
}

class Purchase extends Product{
    int billamt = 0;
    void displayItem(){
        System.out.println("-------------------------------------");
        System.out.println("Code : Item   : Price");
        for(int i = 0; i < super.items.length; i++){
            System.out.print((i+1) + "    : " + super.items[i] + " : " + super.prices[i] + "\n");
        }
        System.out.println("-------------------------------------");
    }

    void purchaseItem(){
        int code, q;
        Scanner sc = new Scanner(System.in);
        System.out.println("Purchase Window");
        do{
            System.out.print("Enter Item Code : ");
            code = sc.nextInt();
            System.out.print("Quantity : ");
            q = sc.nextInt();
            billamt += q * prices[code-1];
            System.out.print("To End : Press 0-> ");
        }while(sc.nextInt() != 0);
        System.out.println("-------------------------------------");
    }

    int billAmt(){
        return billamt;
    }
}
public class q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Username : ");
        String user = sc.nextLine();
        System.out.print("Enter Password : ");
        String ps = sc.nextLine();
        Password psobj = new Password(ps);
        while(!psobj.check()){
            System.out.println("Invalid");
            System.out.print("Re-Enter Password : ");
            ps = sc.nextLine();
            psobj.changeps(ps);
        }
        System.out.println("Valid \nSuccessfully Registered");
        Purchase obj = new Purchase();
        obj.displayItem();
        obj.purchaseItem();
        System.out.println("BILL" + "\nUser   : " + user + "\nAmount : " + obj.billAmt());
    }
}