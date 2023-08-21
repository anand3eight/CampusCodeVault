package StuFile;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import StuGrade.*;

public class StudentFile {
      String name, city, dob, gender, grade;
      int age, id, sem, total, att, rank;

      public StudentFile(int id, StuGrade.StudentGrade obj, int rank) {
            this.id = id;
            this.name = obj.name;
            this.city = obj.city;
            this.dob = obj.dob;
            this.gender = obj.gender;
            this.grade = obj.grade;
            this.age = obj.age;
            this.sem = obj.sem;
            this.total = obj.sum;
            this.att = obj.att;
            this.rank = rank;
      }

      public void writeDetails() throws IOException {
            String filename = "C:/Users/ANAND/IdeaProjects/Java_Lab/Week9/StudentDetails/" + "Student_"
                        + String.valueOf(this.id) + ".txt";
            File f = new File(filename);
            FileWriter fw = new FileWriter(f);
            String s = "Student : " + String.valueOf(this.id) +
                        "\nName       : " + this.name +
                        "\nCity       : " + this.city +
                        "\nDOB        : " + this.dob +
                        "\nAge        : " + String.valueOf(this.age) +
                        "\nSem        : " + String.valueOf(this.sem) +
                        "\nTotal      : " + String.valueOf(this.total) +
                        "\nAttendance : " + String.valueOf(this.att) +
                        "\nGrade      : " + this.grade +
                        "\nRank       : " + String.valueOf(this.rank);
            fw.write(s.toCharArray());
            fw.close();
      }

      public static void main(String[] args) {

      }
}