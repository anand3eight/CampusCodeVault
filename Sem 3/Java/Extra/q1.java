//String Operations

import java.util.*;

class Operations {
    void frequency(String word, char ch){
        int count = 0;
        for(int i = 0; i < word.length(); i++){
            if(word.charAt(i) == ch)
                count++;
        }
        System.out.println(ch + " Occurs " + count + " times.");
    }

    void sort(String word){
        char[] arr = word.toCharArray();
        for(int i = 0; i < word.length(); i++){
            for(int j = i+1; j < word.length(); j++){
                if(arr[i] > arr[j]){
                    char temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.print("Sorted String : ");
        for(char ch : arr){
            System.out.print(ch);
        }
    }

    public char[] swap(String word) {
        char[] ch = new char[word.length()], w = word.toCharArray();
        boolean check = (word.length() % 2 == 0);
        int len = word.length() / 2;
        for (int i = len; i < word.length(); i++) {
            ch[i - len] = w[i];
            if(check)
                ch[i] = w[i - len];
            else if(i + 1 < word.length())
                ch[i + 1] = w[i - len];
        }
        return ch;
    }
}

public class q1 {
    public static void main(String[] args) {
        Operations obj = new Operations();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String : ");
        String word = sc.nextLine(), str = "zero bath bin alpha Alpha Zero Zeros a A z Z";
        System.out.print("Enter a Character in String : ");
        char ch = sc.next().charAt(0);
        obj.frequency(word, ch);
        obj.sort(str);
        System.out.print("\nSwapped String : ");
        for(char c : obj.swap(word)){
            System.out.print(c);
        }
    }
}