//Array of Objects and Object as a Parameter

public class q10 {
    public static void main(String[] args) {
        Pair[] obj = new Pair[5];
        for(int i = 0; i < 5; i++){
            obj[i] = new Pair(i+2, i*2);
        }
        num numobj = new num();
        for(int i = 0; i < 5; i++){
            numobj.display(obj[i]);
        }
    }
}

class Pair
{
    int n1, n2;
    Pair(int a, int b){
        n1 = a;
        n2 = b;
    }
}

class num{
    void display(Pair obj)
    {
        System.out.println("Num : (" + obj.n1 + ", " + obj.n2 + ")");
    }
}