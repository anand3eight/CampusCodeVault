//To Read a File

import java.io.*;

class StudentFile2 {
      public static void main(String[] args) throws IOException {
            File f = new File("Student.txt"); // 1- File Object
            FileReader fr = new FileReader(f); // 2 - FileReader Object
            char arr[] = new char[100]; // 3 - char arr[]
            int val = fr.read(arr); // 4 - value is stored in arr
            for (char a : arr) {
                  System.out.print(a);
            }
            fr.close();
            System.out.println("\nDone!");
      }
}