public class check1 {
    public static void main(String[] args) {
        String name = null;
        int check = 1;
        try {
            if (name == null) {
                check = 0;
                throw new NullPointerException();
            }
        } catch (NullPointerException n) {
            System.out.println(n);
        }
    }
}