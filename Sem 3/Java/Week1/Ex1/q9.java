//Lamp Class

public class q9 {
    public static void main(String[] args) {
        Lamp switch_on = new Lamp();
        Lamp switch_off = new Lamp();
        switch_on.turn_on();
        switch_on.display();
        switch_on.turn_off();
        switch_on.display();
        switch_off.turn_off();
        switch_off.display();
    }
}

class Lamp{
    boolean on = false;
    void turn_on(){
        on = true;
    }
    void turn_off(){
        on = false;
    }
    void display(){
        System.out.println(on);
    }
}