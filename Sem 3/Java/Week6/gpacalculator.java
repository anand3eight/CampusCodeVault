package GPA;

public class gpacalculator {
    public static int creditcal(int mark) {
        if (mark > 90)
            return 10;
        else if (mark <= 90 && mark > 80)
            return 9;
        else if (mark <= 80 && mark > 70)
            return 8;
        else if (mark <= 70 && mark > 60)
            return 7;
        else if (mark <= 60 && mark > 50)
            return 6;
        else if (mark == 50)
            return 5;
        else if (mark < 50)
            return 0;
        else
            return -1;
    }

    public static float gpacal(int[] creditarr, int[] markarr) {
        int s1 = 0, s2 = 0;

        for (int i = 0; i < markarr.length; i++) {
            if (creditcal(markarr[i]) == 0)
                return 0;
            s1 += creditcal(markarr[i]) * creditarr[i];
            s2 += creditarr[i];
        }
        return s1 / s2;
    }

    public static void main(String[] args) {

    }
}