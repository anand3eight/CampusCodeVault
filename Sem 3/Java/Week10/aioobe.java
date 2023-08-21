public class aioobe {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3 };
        for (int i = 0; i < 4; i++) {
            try {
                System.out.println(arr[i]);
            } catch (ArrayIndexOutOfBoundsException a) {
                System.out.println(a);
            }
        }
    }
}
