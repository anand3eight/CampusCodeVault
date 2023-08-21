//Addition of Two Numbers

public class q6 {
     static{
        System.out.println("This Program adds 2, 3 or 4 numbers based on input");
    }

    public static void main(String[] args) {
        System.out.println("Start of Main Method");
        int len = args.length;
        addition obj = new addition();
        if(len == 2){
            int a = Integer.parseInt(args[0]),b = Integer.parseInt(args[1]);
            obj.add(a, b);
        }
        else if(len == 3){
            int a = Integer.parseInt(args[0]),b = Integer.parseInt(args[1]), c = Integer.parseInt(args[2]);
            obj.add(a, b, c);
        }
        else if(len == 4){
            int a = Integer.parseInt(args[0]),b = Integer.parseInt(args[1]), c = Integer.parseInt(args[2]), d = Integer.parseInt(args[3]);
            obj.add(a, b, c, d);
        }
    }
}

class addition{
    void add(int a, int b){
        System.out.println(a + b);
    }
    void add(int a, int b, int c){
        System.out.println(a + b + c);
    }
    void add(int a, int b, int c, int d){
        System.out.println(a + b + c + d);
    }
}