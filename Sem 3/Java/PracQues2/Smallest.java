public class Smallest {
    public static void main(String[] args) {

        int n1 = Integer.parseInt(args[0]);
        int n2 = Integer.parseInt(args[1]);
        int n3 = Integer.parseInt(args[2]);
        int smst;
        smst = n1 < n2 ? n1 : n2;
        smst = smst < n3 ? smst : n3;
        System.out.println("Smallest Number is : "+smst);
    }
}