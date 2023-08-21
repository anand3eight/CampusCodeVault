//Variables and Scopes

public class q7 {
    public static void main(String[] args) {
        variable obj1 = new variable(10,1);
        obj1.display();
        variable obj2 = new variable(11,2);
        obj1.display();
    }
}

class variable{
    int a ;
    public static int b;
    variable(int val1, int val2){
        a = val1;
        b = val2;
    }
    void display(){
        System.out.println("\nInstance : " + a + "\nStatic : " + b);
    }
}