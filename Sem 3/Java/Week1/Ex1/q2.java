//To print the prompt string

public class q2 {
    public static void main(String[] args) {
        Printer ptr = new Printer();
        String s1 = "Hi! It\'s my Program";
        ptr.print(s1);
        ptr.print();
    }
}
class Printer{
    void print(String s1){
        System.out.println(s1);
    }
    void print(){
        System.out.println("Default String");
    }
}